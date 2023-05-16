import React from "react"
import { InstrumentType } from "../interface/Intrument"
import WhiteLongIcon from '../assets/Images/WhiteLongIcon.svg'
import WhiteShortIcon from '../assets/Images/WhiteShortIcon.svg'


interface InstrumentPorps {
  instrument: InstrumentType
  selectedInstruments: InstrumentType[]
  onInstrumentAdd: (
    instrumentId: InstrumentType,
    instrumentSelection: string
  ) => void
}

const Instrument = ({
  instrument,
  selectedInstruments,
  onInstrumentAdd,
}: InstrumentPorps) => {

  const disable = selectedInstruments.length >= 4

  return (
    <div className="border-b h-[60px] bg-[#FCFCFC]">
      {!disable ? (
        <div className="grid grid-flow-col place-items-center justify-between m-3  ">
          <div className="font-bold text-sm text-gray-800  ">
            {instrument.instrumentSymbol}
          </div>
          <div className="grid grid-flow-col gap-3">
            <div
              id="1"
              className="cursor-pointer grid place-content-center h-7 w-16 bg-[#008B1E] rounded-sm"
              onClick={(e) => onInstrumentAdd(instrument, "Long")}
            >
              <span className=" text-white text-xs font-bold grid grid-flow-col place-content-center">
                <img src={WhiteLongIcon} alt="" className="inline-block" />
                  Long
              </span>
            </div>

            <div
              id="-1"
              className="cursor-pointer grid place-content-center h-7 w-16 bg-[#E46962] rounded-sm"
              onClick={(e) => onInstrumentAdd(instrument, "Short")}
            >

              <span className=" text-white text-xs font-bold grid grid-flow-col place-content-center">
                <img src={WhiteShortIcon} alt="" className="inline-block " />
                Short
              </span>
            </div>
          </div>
        </div>
      ) : (
        <div className="grid  grid-flow-col place-items-center justify-between m-3">
          <div className="font-bold text-sm text-[#dadbda]  ">
            {instrument.instrumentName}
          </div>

          <div className="grid grid-flow-col gap-3 ">
            <div
              id="1"
              className="cursor-pointer grid place-content-center h-7 w-16 bg-[#cde8d3] rounded-sm"
            >
              <span className=" text-white text-xs font-bold grid grid-flow-col place-content-center">
                <img src={WhiteLongIcon} alt="" className="inline-block" />
                Long
              </span>
            </div>

            <div
              id="-1"
              className="cursor-pointer grid place-content-center h-7 w-16 bg-[#fae1e0] rounded-sm"
            >
              <span className=" text-white text-xs font-bold grid grid-flow-col place-content-center">
                <img src={WhiteShortIcon} alt="" className="inline-block" />

                Short
              </span>
            </div>
          </div>
        </div>
      )}
    </div>
  )
}

export default Instrument
