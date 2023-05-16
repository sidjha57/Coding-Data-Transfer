import React from "react"
import { useLocation, useNavigate } from "react-router-dom"
import { JoinedPortfolioType } from "../interface/Portfolio"
import { ContestType } from "../interface/Contest"

interface ResultProps {
  portfolio: JoinedPortfolioType
  contest: ContestType
  entries: number 
}

const Result = ({ portfolio, contest, entries }: ResultProps) => {
  const location = useLocation().state
  //const portfolio = location.portfolio
  const score = portfolio?.points || 0
  const rank = portfolio?.rank || null
  const returns = portfolio?.returnX || null
  const navigate = useNavigate()

  const handleScore = () => {
    if (contest.status.contestStatus === "LIVE")
    navigate("/leaderboard", {
      state: { contest, portfolio },
    })
  }

  const handlePerformance = () => {
    if (contest.status.contestStatus === "LIVE")
    navigate("/performance", { state: { contest, portfolio } })
  }

  return (
    <div className="space-y-4">
      
      <div
        onClick={handlePerformance}
        className={` h-16  mt-6 mx-4 justify-between border flex bg-white rounded-md items-center ${
          score ? "shadow-md" : ""
        }`}
      >
        <div className="ml-3">
          <div className="text-sm font-bold">Portfolio Gains</div>
          <div className="text-xs text-dark-text font-medium">Score</div>
        </div>
        <div className="mr-3 font-bold text-base ">
          {score ? (
            <span>
              <span className="font-bold text-base ">{`${parseFloat(score + "").toFixed(1)}`}</span>
              <span className="font-medium text-sm"> Pts</span>
            </span>
          ) : (
            <span className="font-medium text-sm">- Pts</span>
          )}
        </div>
      </div>

      <div
        onClick={handleScore}
        className={` h-16   mx-4 justify-between border flex bg-white rounded-md items-center ${
          rank ? "shadow-md" : ""
        }`}
      >
        <div className="ml-3">
          <div className="text-sm font-bold">Rank</div>
          <div className="text-xs text-dark-text font-medium">
            Top 10% out of {entries} entries
          </div>
        </div>
        <div className="mr-3">
          <p className=" font-bold text-xl">
            {rank ? <span>{rank}</span> : <span>- </span>}
          </p>
        </div>
      </div>

      <div
        className={` h-16 mx-4 justify-between border flex bg-white rounded-md items-center ${
          returns ? "shadow-md" : ""
        }`}
      >
        <div className="ml-3">
          <div className="text-sm font-bold">Return Potential</div>
          <div className="text-xs text-dark-text font-medium">
            Estd. INR 2500
          </div>
        </div>
        <div className="mr-3">
          <p className="font-bold text-xl">{returns || "- x"}</p>
        </div>
      </div>
    </div>
  )
}

export default Result
