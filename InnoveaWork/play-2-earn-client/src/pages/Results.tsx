import React from "react"
import CommonHeader from "../components/CommonHeader"
import Result from "../components/Result"
import moment from "moment"
import { useLocation, useNavigate } from "react-router-dom"
import { InstrumentType } from "../interface/Intrument"
import { JoinedPortfolioType, PortfolioType } from "../interface/Portfolio"
import { addDataIntoCache } from "../js/caching"
import { frontendUrl } from "../js/urls"
import { updateAppState, appStateKey } from "../lib/appState"
import LineChartWithTargets from "../components/LineGraph"
import { ContestType } from "../interface/Contest"
import ContestStatus from "../components/ContestStatus"
import { getCurrentTimeString, getWeekNumber } from "../utils"
import Portfolios from "../components/Portfolios"
import { getInstruments } from "../api/Instruments"
import { getPortfoliosRank } from "../api/Portfolio"
import { getReturnX } from "../utils/returnX"
// import Graph from '/graph.jpg';

interface GraphDataType {
  time: string
  score: number
}

const Results = () => {
  const location = useLocation()
  const portfolio: JoinedPortfolioType = location.state.portfolio
  const contest: ContestType = location.state.contest
  const catalogId: number = location.state.catalogId
  const index: number = location.state.index

  const weekNumber = getWeekNumber()
  const navigate = useNavigate()
  //   const [graphData, setGraphData] = React.useState([
  //     { time: "08:00", score: 90 },
  //     { time: "09:30", score: 140 },
  //     { time: "11:00", score: 15 },
  //     { time: "12:30", score: 25 },
  //     { time: "14:00", score: 30 },
  //     { time: "15:30", score: 35 },
  //     { time: "17:00", score: 30 },
  //   ])
  const [graphData, setGraphData] = React.useState<GraphDataType[]>([
    { time: getCurrentTimeString(), score: portfolio?.points || 0 },
  ])

  const [_weekNumber, _setWeekNumber] = React.useState(weekNumber)
  const [entries, setEntries] = React.useState(0)

  const [_portfolio, _setPortfolio] = React.useState(portfolio)

  React.useEffect(() => {
    if (contest.status.contestStatus === "LIVE") {
      const interval = setInterval(async () => {
        const { data: portfolioRanks } = await getPortfoliosRank(
          contest.ipid,
          _weekNumber
        )
        const time = getCurrentTimeString()
        setGraphData((_graphData) => {
          if (_graphData.length >= 200) {
            _graphData.shift()
          }
          return [
            ..._graphData,
            { time, score: portfolioRanks[portfolio.ipid]?.total || 0 },
          ]
        })
        _setPortfolio((prevPortfolio) => ({
          ...prevPortfolio,
          points: portfolioRanks[portfolio.ipid]?.total || 0,
          rank: portfolioRanks[portfolio.ipid]?.rank || 0,
          returnX: getReturnX(portfolioRanks[portfolio.ipid]?.rank || 0),
        }))
        setEntries(Object.keys(portfolioRanks).length)
      }, 5000)
      return () => clearInterval(interval)
    }
  }, [graphData, _weekNumber])

  React.useEffect(() => {
    async function fetchData() {
      const { data } = await getInstruments(catalogId, weekNumber)
      _setWeekNumber(data.length ? weekNumber : 1)
    }
    if (contest.status.contestStatus === "LIVE") fetchData()
  }, [contest, portfolio, catalogId, weekNumber])

  //console.log(contest)
  const handleEdit = async () => {
    const selectedInstruments: InstrumentType[] =
      portfolio.portfolioSelections.map((instruments) => {
        return {
          ipid: instruments.instrument.ipid,
          instrumentName: instruments.instrument.instrumentName,
          instrumentSymbol: instruments.instrument.instrumentSymbol,
          isActive: 1,
          instrumentSelection:
            instruments.instrumentSelection === 1 ? "Long" : "Short",
          boosterSelection: instruments.boosterSelection,
        }
      })

    console.log(selectedInstruments)
    await updateAppState({ selectedInstruments }, appStateKey)
    await addDataIntoCache("EditState", frontendUrl, {
      edit: true,
      portfolioId: portfolio.ipid,
      statusId: portfolio.status.ipid,
    })
    navigate("/instruments", {
      state: { contest: contest, contestParameterId: 1, catalogId: catalogId },
    })
  }

  return (
    <div>
      <CommonHeader header={`Results`} navigateBack={"/index"} />

      <div className=" mx-4 py-2 text-gray-700 pt-6">
        <div className="grid grid-flow-col place-content-between">
          <div className="font-bold">Portfolio{index}</div>
          <p className="p-2 grid place-content-center capitalize box-border text-center text-xs text-gray-700 rounded-2xl h-5 w-fit border border-gray-400">
            {contest.status.contestStatus}
          </p>
        </div>
      </div>
      <ContestStatus contest={contest} headerActive={false} />

      {/* Graph */}

      {contest.status.contestStatus === "UPCOMING" && (
        <div className="RevisePortfolioContainer h-14 w-92 m-4 border flex justify-between bg-[#F8F3D7] rounded-lg items-center">
          <div className="">
            <p className="text-xs font-medium ml-3 text-dark-text">
              You can revise your portfolio till the <br /> market opens.
            </p>
          </div>
          <div
            onClick={() => handleEdit()}
            className="h-7 bg-[#08309E] mr-3 grid place-content-center rounded-md ml-9"
          >
            <p className="text-white font-bold text-xs mx-3 my-2 ">Revise</p>
          </div>
        </div>
      )}

      <div className="w-92 mx-4 mt-6 mb-1 font-medium text-xs">
        <div className="flex justify-between">
          <div
            className={`${
              contest.status.contestStatus === "COMPLETED"
                ? "text-[#93000A] "
                : contest.status.contestStatus === "LIVE"
                ? "text-[#2DA62A]"
                : ""
            } flex space-x-1`}
          >
            <div
              className={`w-1 h-1 rounded-full my-[6px] ${
                contest.status.contestStatus === "COMPLETED"
                  ? "bg-[#93000A]"
                  : contest.status.contestStatus === "LIVE"
                  ? "bg-[#2DA62A]"
                  : ""
              }`}
            ></div>
            <span className="">
              {contest.status.contestStatus === "COMPLETED"
                ? "Closed"
                : contest.status.contestStatus === "LIVE"
                ? "Live"
                : "Upcoming"}
            </span>
          </div>
          <div>
            {contest.status.contestStatus === "COMPLETED"
              ? `Updated: ${moment(contest.contestSessionEndTime)
                  .utc()
                  .format("Do MMM, h:mmA")}`
              : contest.status.contestStatus === "LIVE"
              ? `Updated: ${moment().format("Do MMM, h:mmA")}`
              : `Upcoming: ${moment(contest.contestSessionStartTime)
                  .utc()
                  .format("Do MMM, h:mmA")}`}
          </div>
        </div>

        {/* {contest.status.contestStatus === "UPCOMING" ? (
          <div className="flex justify-between">
            <div className=" text-[#93000A] flex space-x-1">
              <div className="w-1 h-1 rounded-full my-[6px] bg-[#93000A]"></div>
              <span className="">Closed</span>
            </div>
            <div>Updated: 8th Apr, 3:30 PM</div>
          </div>
        ) : (
          <div className="flex justify-between">
            <div className=" text-[#2DA62A] flex space-x-1">
              <div className="w-1 h-1 rounded-full my-[6px] bg-[#2DA62A]"></div>
              <span className="">Live</span>
            </div>
            <div>Updated: 8th Apr, 3:30 PM</div>
          </div>
        )} */}
      </div>
      <div className="grid  rounded-sm">
        {(contest.status.contestStatus === "COMPLETED" ||
          contest.status.contestStatus === "UPCOMING") && (
          <div className="box-border mx-10 flex h-60 bg-gray-400 border border-solid border-gray-500 rounded-lg order-1 flex-grow">
            <span className="self-center mx-auto font-bold text-2xl">
              Image
            </span>
          </div>
        )}

        {contest.status.contestStatus === "LIVE" && (
          <LineChartWithTargets
            graphData={graphData}
            tenthPercentile={110}
            twentiethPercentile={80}
          />
        )}
      </div>

      <Result
        portfolio={_portfolio}
        contest={contest}
        entries={entries}
      />
    </div>
  )
}

export default Results
