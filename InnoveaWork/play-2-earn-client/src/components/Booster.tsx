import React from "react"
import { InstrumentType } from "../interface/Intrument"
import BlackLongIcon from '../assets/Images/BlackLongIcon.svg'
import BlackShortIcon from '../assets/Images/BlackShortIcon.svg'

interface BoosterProps {
  instrument: InstrumentType
  boosters: number[]
  onBoosterSelect: (instrumentId: number, boosterSelection: number) => void
}

const Booster = ({ instrument, boosters, onBoosterSelect }: BoosterProps) => {
  return (
    <div className="">
      <div className="flex items-center m-[0.0rem] bg-white ">
        <div className="font-bold text-sm flex-auto mx-6">
          {instrument.instrumentSymbol}
          <div className="grid grid-flow-col place-content-start">
              {
                instrument.instrumentSelection === "Long" ?
                <img src={BlackLongIcon} className="mt-1 mr-1"  alt="" />
                :
                <img src={BlackShortIcon} className="mt-1 mr-1" alt="" />
              }
              <div className="text-center  text-xs text-[#5E5E62] font-medium">
                {instrument.instrumentSelection}
              </div>
            </div>
        </div>
        <div className="m-4 flex space-x-3">
          {boosters.map((booster, index) => (
            <button
              key={`${instrument.ipid} -${index + 1}`}
              onClick={() => onBoosterSelect(instrument.ipid, (instrument?.boosterSelection === booster) ? 1 :  booster)}
              className={`outline rounded-full h-9 w-9 ${
                instrument?.boosterSelection === booster
                  ? "outline-2 bg-[#DDE1FF] text-[#08309E] outline-[#DDE1FF]"
                  : "outline-1 outline-dark-text text-dark-text"
              } `}
            >
              <p className="text-sm font-bold ">{booster}x</p>
            </button>
          ))}
        </div>
      </div>
    </div>
  )
}

export default Booster
