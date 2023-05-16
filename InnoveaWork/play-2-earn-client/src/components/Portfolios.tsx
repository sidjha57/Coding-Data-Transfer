import React from "react"
import moment from "moment"

import placeholderImage from "../assets/Images/IndexPlayHomeIcon.svg"
import AddIcon from "../assets/Images/AddIcon.svg"

import { Search, useNavigate, useSearchParams } from "react-router-dom"
import { ContestType } from "../interface/Contest"
import ContestStatus from "./ContestStatus"
import Portfolio from "./Portfolio"
import SavedPortfolio from "./SavedPortfolio"
import { JoinedPortfolioType, PortfolioType } from "../interface/Portfolio"
import { WeekInstrumentType } from "../interface/Intrument"
import { getInstruments } from "../api/Instruments"
import { getPortfoliosRank } from "../api/Portfolio"
import { getReturnX } from "../utils/returnX"
import {
  fetchWeekInstruments,
  formatJoinedPortfoliosData,
  getPortfoliosResults,
} from "../utils"

interface PortfoliosProps {
  contest: ContestType
  portfolioStatus: string
  portfolios: PortfolioType[]
}

const Portfolios = ({
  contest,
  portfolioStatus,
  portfolios,
}: PortfoliosProps) => {
  const weekNumber = moment().week()

  const navigate = useNavigate()

  const [savedPortfolios, setSavedPortfolios] = React.useState<PortfolioType[]>(
    []
  )
  const [joinedPortfolios, setJoinedPortfolios] = React.useState<
    PortfolioType[] | JoinedPortfolioType[]
  >([])

  const [_joinedPortfolios, _setJoinedPortfolios] = React.useState<
    JoinedPortfolioType[]
  >([])
  const [completedPortfolios, setCompletedPortfolios] = React.useState<
    JoinedPortfolioType[]
  >([])
  const [isDisabled, setIsDisabled] = React.useState(false)
  const [returningUser, setReturningUser] = React.useState(false)
  const totalEntries = React.useRef(1);

  const [searchParams, setSearchParams] = useSearchParams();
  const catalogType = searchParams.get('catalogType')  === "index" ? 1 : 2;
  // console.log(catalogType)

  const fetchUserPortfolio = React.useCallback(async () => {
    try {
        console.log(portfolios)
        const joined = portfolios.filter(
          (portfolio: any) => portfolio?.status?.portfolioStatus === "JOINED"
        )

        const saved = portfolios.filter(
          (portfolio: any) => portfolio?.status?.portfolioStatus === "SAVED"
        )

        const completed: JoinedPortfolioType[] = getPortfoliosResults(
          portfolios.filter(
            (portfolio: any) =>
              portfolio?.status?.portfolioStatus === "COMPLETED"
          )
        )

        if (joined.length >= 5 || contest.status.contestStatus === "LIVE") {
          setIsDisabled(true)
        }
        
        setJoinedPortfolios(joined)
        setSavedPortfolios(saved)
        setCompletedPortfolios(completed)
        setReturningUser(
          portfolios.some(
            (portfolio: any) =>
              portfolio?.status?.portfolioStatus === "JOINED" ||
              portfolio?.status?.portfolioStatus === "LIVE"
          )
        )
    } catch (err) {
      console.log(err)
    }
  }, [portfolios])


  React.useEffect(() => {
    fetchUserPortfolio()
    console.log(portfolios)
  }, [portfolios])

  async function LiveState() {
    const {_joinedPortfolios : data, totalEntries: entries} = await fetchWeekInstruments(
       catalogType,
       weekNumber,
       contest.ipid,
       joinedPortfolios
     )
     console.log(entries)
     totalEntries.current = entries
     console.log("Live State", data)
     _setJoinedPortfolios(data)
   }

  React.useEffect(() => {
    console.log("Inside UseEffect",catalogType)
    if (
      contest.status.contestStatus === "LIVE" &&
      portfolioStatus === "JOINED" &&
      joinedPortfolios.length
    ) {
      
      LiveState()
      // fetchWeekInstruments(
      //   // searchParams.get('catalogType') === 'index'? 1 : 2,
      //   catalogType,
      //   weekNumber,
      //   contest.ipid,
      //   joinedPortfolios
      // ).then((_joinedPortfolios) => {
      //   console.log("Contest Ipid",contest.ipid)
      //   console.log("Ranks Included", _joinedPortfolios)
      //   _setJoinedPortfolios(_joinedPortfolios)
      // })
    }
  }, [contest.ipid])

  const _contestStatus =
    contest && contest.status?.contestStatus === "COMPLETED" ? contest : null

  return (
    <div className=" bg-[#F5F5F5] py-6 pt-40 w-screen grid ">
      {portfolioStatus === "COMPLETED" ? (
        <>
          {_contestStatus && (
            <ContestStatus contest={_contestStatus} headerActive={true} />
          )}
        </>
      ) : (
        <>
          {contest && <ContestStatus contest={contest} headerActive={true} />}
        </>
      )}

      {/* Portfolios */}

      <div className="Portfolios pt-4 ">
        {contest && portfolioStatus === "JOINED" && (
          <Portfolio
            status={"JOINED"}
            portfolios={
              contest.status.contestStatus === "LIVE"
                ? _joinedPortfolios
                : joinedPortfolios
            }
            totalEntries ={
              contest.status.contestStatus === "LIVE"
                ? totalEntries.current
                : 0
            }
            contest={contest}
          />
        )}
      </div>
      {contest && portfolioStatus === "COMPLETED" && (
        <Portfolio
          status={"COMPLETED"}
          portfolios={completedPortfolios}
          contest={contest}
        />
      )}

      {portfolioStatus === "JOINED" && (
        <div>
          {!returningUser && joinedPortfolios.length === 0 && (
            <div className="grid place-content-center">
              <img src={placeholderImage} width="300" alt="Index Play" />
            </div>
          )}
          <div className="grid py-4 space-y-4">
            {joinedPortfolios?.length < 5 ? (
              <span className="text-xs text-center font-medium text-[#303034]">
                You can enter upto{" "}
                <span className="font-bold">
                  {5 - joinedPortfolios?.length}
                </span>{" "}
                portfolios for this UPCOMING contest.
                <br /> Tap + to create portfolios to join the contest
              </span>
            ) : (
              <span className="text-xs text-center font-medium text-[#303034]">
                You can't enter more than <span className="font-bold">5</span>{" "}
                portfolios.
              </span>
            )}

            {/* Saved Portfolios */}
          </div>
          {savedPortfolios.length > 0 ? (
            <>
              <div className="">
                {returningUser && <div className="bg-[#E4E1E6] h-1"></div>}

                <div
                  className="bg-background mt-7"
                  style={{ paddingBottom: savedPortfolios.length * 200 }}
                >
                  <SavedPortfolio
                    setIsDisabled={setIsDisabled}
                    isDisabled={isDisabled}
                    joined={joinedPortfolios}
                    setSavedPortfolios={setSavedPortfolios}
                    setJoinedPortfolios={setJoinedPortfolios}
                    portfolios={savedPortfolios}
                    contest={contest}
                  />
                </div>
              </div>
            </>
          ) : (
            <div
              style={{ paddingBottom: savedPortfolios.length === 0 ? 200 : 0 }}
            ></div>
          )}  


          {/* Create Button */}
          <div className="left-[80%] top-[80%] fixed z-10">
            <button
              disabled={isDisabled}
              onClick={() =>
                navigate({
                  pathname: '/instruments',
                  search: searchParams.toString()
                }, {
                  state: {
                    contest: contest,
                    contestParameterId: 1,
                  },
                })
              }
              className={`${
                isDisabled
                  ? "bg-[#E4E1E6]"
                  : "bg-gradient-to-r from-[#0B49F4] to-[#022278] shadow-lg"
              } grid place-items-center font-bold h-14 w-14 rounded-2xl cursor-pointer`}
            >
              <img className="h-4 w-4" src={AddIcon} alt={"+"}></img>
            </button>
          </div>
        </div>
      )}
    </div>
  )
}

export default Portfolios
