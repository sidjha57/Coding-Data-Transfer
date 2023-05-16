import React, { useRef } from "react"

interface InstrumentType {
  name: string
  perchange: number
  booster: number
}

interface InstrumentProps {
  instrumentItem: any
  portfolioRank: any
  type: number
}

const InstrumentPerformance = ({
  instrumentItem,
  portfolioRank,
  type,
}: InstrumentProps) => {
  console.log(instrumentItem)
  console.log(portfolioRank)
  console.log(type)
  const point = useRef(0)

  return (
    <div>
      <div className="grid grid-flow-col place-content-between ">
        <div className="mx-4 my-2 text-left">
          <div className="text-dark-text font-bold">
            {instrumentItem.instrument.instrumentName}
          </div>
          <div className="text-xs text-dark-text">
            {instrumentItem.instrumentSelection > 0 ? "Long" : "Short"}{" "}
            {instrumentItem.boosterSelection
              ? `| ${instrumentItem.boosterSelection}x`
              : ``}
          </div>
        </div>
        <div className="mx-4 my-2 text-right">
          {portfolioRank && (
            <>
              <div className="text-dark-text font-bold">
                {parseFloat(
                  (portfolioRank[instrumentItem.instrumentId]?.perChange || 0) +
                    ""
                ).toFixed(2)}
                %
              </div>
              <div className="">
                {(portfolioRank[instrumentItem.instrumentId]?.score || 0) >
                0 ? (
                  <div className="text-xs text-green-400 text-right">
                    +
                    {parseFloat(
                      (portfolioRank[instrumentItem.instrumentId]?.score || 0) +
                        ""
                    ).toFixed(2)}{" "}
                    pt
                  </div>
                ) : (
                  <div className="text-xs text-red-400 text-right">
                    {parseFloat(
                      (portfolioRank[instrumentItem.instrumentId]?.score || 0) +
                        ""
                    ).toFixed(2)}{" "}
                    pt
                  </div>
                )}
              </div>
            </>
          )}
        </div>
      </div>

      <div className="h-[1px] mx-4 bg-[#eaebeb]" />
    </div>
  )
}

export default InstrumentPerformance
