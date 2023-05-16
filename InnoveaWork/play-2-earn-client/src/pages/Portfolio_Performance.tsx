import React, { useEffect, useRef, useState } from "react"
import CommonHeader from "../components/CommonHeader"
import InstrumentPerformance from "../components/InstrumentPerformance"
import { getInstruments } from "../api/Instruments"
import { useLocation } from "react-router-dom"
import { getWeekNumber } from "../utils"
import { getPortfoliosRank } from "../api/Portfolio"
import { PortfolioRankType } from "../interface/Portfolio"

const Portfolio_Performance = () => {
  const location = useLocation().state
  const contest = location?.contest
  const portfolio = location?.portfolio
  const catalogId = location?.catalogId
  const weekNumber = getWeekNumber()

  const [portfoliosRanks, setPortfoliosRanks] = useState<any>({})

  console.log(portfoliosRanks)

  useEffect(() => {
    console.log("inside")
    async function fetchData() {
      const { data } = await getInstruments(catalogId, weekNumber)
      const { data: portfolioRanks } = await getPortfoliosRank(
        contest.ipid,
        data.length ? weekNumber : 1
      )
      console.log(portfolioRanks, "portfolioRanks")
      setPortfoliosRanks(portfolioRanks)
    }
    if (contest.status.contestStatus === "LIVE") fetchData()
  }, [contest, portfolio, catalogId, weekNumber])


  console.log(portfoliosRanks)

  return (
    <div>
      <CommonHeader
        header={`Portfolio Performance`}
        navigateBack={"/results"}
      />
      <div className=" h-16 w-92 m-4 border justify-between flex bg-white rounded-md items-center">
        <div className="mx-4">
          <div className="text-dark-text font-bold">Portfolio Gains</div>
          <div className="text-xs text-dark-text">Score</div>
        </div>
        <div className="mx-4">
          <p className="text-dark-text font-bold mx-2 text-xl">
            {portfoliosRanks &&
            portfoliosRanks[portfolio.ipid] &&
            portfoliosRanks[portfolio.ipid]?.total > 0
              ? `+${parseFloat(
                  (portfoliosRanks[portfolio.ipid]?.total || 0) + ""
                ).toFixed(2)}`
              : `${parseFloat(
                  (portfoliosRanks[portfolio.ipid]?.total || 0) + ""
                ).toFixed(2)}`}{" "}
            Pts
          </p>
        </div>
      </div>

      <div>
        <div className="m-4 font-bold text-dark-text">Your Selections</div>
        <div className="h-fit w-92 m-4 bg-white rounded-md">
          {portfolio?.portfolioSelections?.length &&
            portfolio?.portfolioSelections?.map((instrument: any) => (
              <div key={instrument.ipid}>
                <InstrumentPerformance
                  instrumentItem={instrument}
                  portfolioRank={
                    portfoliosRanks ? portfoliosRanks[portfolio.ipid] : null
                  }
                  type={1}
                />
              </div>
            ))}
        </div>

      </div>
    </div>
  )
}

export default Portfolio_Performance
