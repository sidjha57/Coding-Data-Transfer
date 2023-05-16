import React from "react"
import CrossIcon from "../assets/Images/CrossIcon.svg"
import BlackLongIcon from '../assets/Images/BlackLongIcon.svg'
import BlackShortIcon from '../assets/Images/BlackShortIcon.svg'
import { InstrumentType } from "../interface/Intrument"


interface InstrumentPorps {
  selectedInstrument: InstrumentType
  onInstrumentRemove: (instrument: number) => void
}

const SelectedInstrument = ({
  selectedInstrument,
  onInstrumentRemove,
}: InstrumentPorps) => {
  return (
    <div className="border-b  ">
      <div className="bg-[#EFEFFF]">
        <div className="grid grid-flow-col place-items-center justify-between">
          <div className="font-bold text-sm text-gray-800  m-3">
            <div>
              {selectedInstrument.instrumentName}
            </div>
            <div className="grid grid-flow-col place-content-start">
              {
                selectedInstrument.instrumentSelection === "Long" ?
                <img src={BlackLongIcon} className="mt-1 mr-1"  alt="" />
                :
                <img src={BlackShortIcon} className="mt-1 mr-1" alt="" />
              }
              <div className="text-center  text-xs text-light-text font-medium">
                {selectedInstrument.instrumentSelection}
              </div>
            </div>
          </div>
          <div className="m-3 cursor-pointer">
            <div
              className=""
              onClick={(e) => onInstrumentRemove(selectedInstrument.ipid)}
            >
              <img className="w-5 h-5" src={CrossIcon} alt="" />
            </div>
          </div>
        </div>
      </div>
    </div>
  )
}

export default SelectedInstrument
