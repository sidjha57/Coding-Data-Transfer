import React, { useEffect } from "react"
import { useLocation, useSearchParams } from "react-router-dom"
import { getContest } from "../api/Contests"
import { ContestTypeConfigID } from "../assets/ContestTypeConfig"
import { ContestType } from "../interface/Contest"
import Portfolios from "./Portfolios"
import { useAuth } from "../context/AuthContext"
import { PortfolioType } from "../interface/Portfolio"
import { getUserPortfolios } from "../api/Portfolio"

function GameTab() {

  const [searchParams, setSearchParams] = useSearchParams()
  const [contest, setContest] = React.useState<ContestType>()
  const [portfolioStatus, setPortfolioStatus] = React.useState("JOINED")
  const [portfolios, setPortfolios] = React.useState<PortfolioType[]>([])

  const { user } = useAuth()

  const fetchContests = async () => {
    console.log(searchParams.get('catalogType') === 'index' ? 1 : 2, ContestTypeConfigID[`${searchParams.get('catalogType')}${searchParams.get('contestType')}`])
    try {
      const { data: contests } = await getContest(
        ContestTypeConfigID[`${searchParams.get('catalogType')}${searchParams.get('contestType')}`],
        user.ipid
      )
      console.log(contests)
      setContest(contests)
    } catch (err) {
      console.log(err)
    }
  }

  React.useEffect(() => {
    console.log(searchParams.get('catalogType'), searchParams.get('contestType'))
    fetchContests()
  }, [searchParams])

  const fetchPortfolios = async () => {
    if (contest) {
      const { data } = await getUserPortfolios(user.ipid, contest?.ipid)
      console.log("API response", data)
      setPortfolios(data)
    }
  }

  React.useEffect(() => {
    console.log("Portfolios", portfolios)
  }, [portfolios])

  React.useEffect(() => {
    fetchPortfolios()
  }, [contest])



  return (
    <div className="">
      {/* State of Portfolios */}
      <div className="fixed top-24 w-screen border-b flex space-x-3 items-center bg-white h-10">
        <button
          onClick={() => {
            searchParams.set('portfolioStatus', 'joined')
            setSearchParams(searchParams)
            setPortfolioStatus("JOINED")
          }}
          className={`cursor-pointer text-xs mt-1 grid place-content-center h-6 ml-4 w-fit px-3 font-medium border border-1 rounded-[4px] ${portfolioStatus === "JOINED"
            ? "border-primary-color bg-dark-background text-primary-color"
            : "outline-gray-200"
            } `}
        >
          Joined
        </button>

        <button
          onClick={() => {
            searchParams.set('portfolioStatus', 'completed')
            setSearchParams(searchParams)
            setPortfolioStatus("COMPLETED")
          }}
          className={`cursor-pointer text-xs mt-1 grid place-content-center h-6 w-fit px-3 font-medium border border-1 rounded-[4px]  ${portfolioStatus === "COMPLETED"
            ? "border-primary-color bg-dark-background text-primary-color"
            : "outline-gray-200"
            }`}
        >
          Completed
        </button>
      </div>

      {/* Main Page */}
      {contest && (
        <Portfolios
          contest={contest}
          portfolioStatus={portfolioStatus}
          portfolios={portfolios}
        />
      )}
    </div>
  )
}

export default GameTab
