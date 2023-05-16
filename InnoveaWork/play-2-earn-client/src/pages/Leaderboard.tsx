import moment from "moment"
import React, { useEffect, useState } from "react"
import { useLocation } from "react-router-dom"
// import { getRanks } from "../api/Ranks";
import CommonHeader from "../components/CommonHeader"
import Score from "../components/Score"
import { PortfolioType } from "../interface/Portfolio"
import Loading from "../components/Loading"
import LoaderOverlay from "../components/Loading"
import { getInstruments } from "../api/Instruments"
import { getPortfoliosRank } from "../api/Portfolio"
import { getWeekNumber } from "../utils"

const Leaderboard = () => {
  const location = useLocation().state
  const contest = location?.contest
  const portfolio = location?.portfolio
  const catalogId = location?.catalogId
  const weekNumber = getWeekNumber()

  const [portfoliosRanks, setPortfoliosRanks] = useState<any>({})

  useEffect(() => {
    async function fetchData() {
      const { data } = await getInstruments(catalogId, weekNumber)
      const { data: portfolioRanks } = await getPortfoliosRank(
        contest.ipid,
        data.length ? weekNumber : 1
      )
      console.log(portfolioRanks, "portfolioRanks")
      setPortfoliosRanks(portfolioRanks)
    }
    //if (contest.status.contestStatus === "LIVE")
    fetchData()
  }, [contest, portfolio, catalogId, weekNumber])



  return (
    <div>
      <CommonHeader header={`Leaderboard`} navigateBack={"/results"} />
      <div className="h-fit w-screen bg-white fixed">
        <div className="pt-1">
          <div className=" h-14 outline outline-1 outline-[#d6d5d6] m-4 justify-between flex bg-white rounded-md items-center">
            <div className="mx-4">
              <div className="text-dark-text font-bold">Rank</div>
              <div className="text-xs text-dark-text">
                Top 10% out of {Object.keys(portfoliosRanks).length} entries
              </div>
            </div>
            <div className="mx-4">
              <p className="text-dark-text font-bold mx-2 text-xl">
                {portfoliosRanks && portfoliosRanks[portfolio.ipid]
                  ? portfoliosRanks[portfolio.ipid]?.rank
                  : ""}
              </p>
            </div>
          </div>
        </div>

        {/* <div className="flex mx-4 pb-2 space-x-4">
          <div>
            <input
              type="radio"
              name="option"
              id="1"
              className="peer hidden"
            />
            <label
              htmlFor="1"
              className="block text-[0.65rem] w-12 font-md outline outline-[1px] outline-[#eaebeb] text-dark-text cursor-pointer select-none rounded-md p-1 text-center peer-checked:bg-[#dce1fe] peer-checked:outline-primary-color peer-checked:text-primary-color"
            >
              0-10%
            </label>
          </div>

          <div>
            <input type="radio" name="option" id="2" className="peer hidden" />
            <label
              htmlFor="2"
              className="block text-[0.65rem] w-12 font-md outline outline-[1px] outline-[#eaebeb] text-dark-text cursor-pointer select-none rounded-md p-1 text-center peer-checked:bg-[#dce1fe] peer-checked:outline-primary-color peer-checked:text-primary-color"
            >
              10-20%
            </label>
          </div>

          <div>
            <input type="radio" name="option" id="3" className="peer hidden" />
            <label
              htmlFor="3"
              className="block text-[0.65rem] w-12 font-md outline outline-[1px] outline-[#eaebeb] text-dark-text cursor-pointer select-none rounded-md p-1 text-center peer-checked:bg-[#dce1fe] peer-checked:outline-primary-color peer-checked:text-primary-color"
            >
              20-30%
            </label>
          </div>
        </div> */}
        <div className="h-[1px]  bg-[#d6d5d6]" />
      </div>
      <div className="pt-[11vh]">
        {portfoliosRanks &&
          portfoliosRanks.map((portfolio : any, index :any) => (
            <div key={portfolio.ipid}>
              <Score
                portfolio={portfolio}
                entries={portfoliosRanks.length}
                rank={index + 1}
              />
            </div>
          ))}
      </div>
    </div>
  )
}

export default Leaderboard
