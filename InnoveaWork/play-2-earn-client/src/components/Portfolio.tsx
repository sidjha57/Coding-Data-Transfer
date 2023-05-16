import React from "react"
import { useNavigate, useSearchParams } from "react-router-dom"
import BlueBagIcon from "../assets/Images/BlueBagIcon.svg"
import { JoinedPortfolioType, PortfolioType } from "../interface/Portfolio"
import LongShortInstrument from "./LongShortInstrument"
import { ContestType } from "../interface/Contest"

interface PortfolioProps {
  status: string
  portfolios: JoinedPortfolioType[]
  totalEntries?: Number
  contest: ContestType
}

const Portfolio = ({
  status,
  portfolios,
  contest,
  totalEntries,
}: PortfolioProps) => {
  let count = 1
  const navigate = useNavigate()
  const [searchParams, setSearchParams] = useSearchParams()

  // React.useEffect(() => {
  //   console.log(portfolios)
  // }, [portfolios])

  const handleNavigate = (portfolio: JoinedPortfolioType, count: number) => {
    navigate({
      pathname: '/results',
      search: searchParams.toString()
    }, {
      state: {
        portfolio: portfolio,
        index: count,
        contest: contest
      },
    })
  }
  return (
    <div className="z-0">
      {portfolios &&
        portfolios.map((portfolio, index) => (
          <div
            key={portfolio.ipid}
            onClick={() => handleNavigate(portfolio, count)}
            className="border rounded-md h-[108px] mb-4 mx-4 py-[14px] px-[12px] bg-white shadow-md"
          >
            <div className=" bg-white flex justify-between">
              <div className="w-[224px]">
                <div className="grid grid-flow-col place-content-start gap-1 ">
                  <img className="h-5 w-5 p-[2.5px]" src={BlueBagIcon} alt="" />
                  <span className="font-semibold text-sm text-[#47464A] text-center">
                    Portfolio{count++}
                  </span>
                </div>
                <div className="text-xs my-3 ">
                  <LongShortInstrument
                    portfolioSelections={portfolio.portfolioSelections}
                    colored={true}
                  />
                </div>
              </div>

              {/* <div className="justify-self-end"> */}

              <div className="grid w-[80px] h-[76px] place-items-end">
                <div className="grid grid-flow-row place-items-end">
                  <h1 className="font-medium text-xs text-right text-[#77767A]">
                    <span>
                      <span className="font-bold text-base text-black">
                        {
                          portfolio?.points? 
                            <span>
                              {parseFloat(portfolio?.points + "").toFixed(1)}
                              <span className="font-medium text-xs"> Pts</span>
                            </span>
                            : 
                            
                            "- Pts"
                        }
                      </span>
                    </span>
                  </h1>
                </div>
                <div className="text-right font-medium text-xs text-[#77767A]">
                  {contest.status.contestStatus === "LIVE" ||
                  contest.status.contestStatus === "COMPLETED" ? (
                    <span>
                      <span className="text-sm text-black">
                        {portfolio?.rank || 0}
                      </span>
                      <span>/{`${totalEntries}`}</span>
                    </span>
                  ) : (
                    "- Rank"
                  )}
                </div>
                <div className="place-content-center grid h-6 w-8 bg-[#D7F5D6] rounded-3xl font-medium text-xs text-[#258122]">
                  {`${portfolio?.returnX || "-x"}`}
                </div>
              </div>
              {/* </div> */}
            </div>
          </div>
        ))}
    </div>
  )
}

export default Portfolio
