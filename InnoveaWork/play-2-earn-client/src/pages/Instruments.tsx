import React, { useState, useEffect, useCallback } from "react"
import { useLocation, useNavigate, useSearchParams } from "react-router-dom"

import CommonFooter from "../components/CommonFooter"
import CommonHeader from "../components/CommonHeader"
import Instrument from "../components/Instrument"
import { InstrumentType } from "../interface/Intrument"
import { getAppState, appStateKey, updateAppState } from "../lib/appState"
import { getInstruments } from "../api/Instruments"
import SelectedInstrument from "../components/SelectedInstrument"

const Instruments = () => {
  const navigate = useNavigate()
  const [instruments, setInstruments] = useState<any[]>([])
  const [selectedInstruments, setSelectedInstruments] = useState<
    InstrumentType[]
  >([])
  const weekNumber = 1;
  const [searchParams, setSearchParams] = useSearchParams();
  const location = useLocation()
  console.log(location.state);

  const getCatalogIntruments = useCallback(async () => {
    const { data } = await getInstruments(searchParams.get('catalogType') === 'index'? 1 : 2, weekNumber)
    console.log({ data })
    setInstruments(data)
  }, [])

  useEffect(() => {
   
      getCatalogIntruments()

    getAppState(appStateKey).then((data) => 
      setSelectedInstruments(data.selectedInstruments)
    )
  }, [getCatalogIntruments])

  const onInstrumentAdd = (
    instrument: InstrumentType,
    instrumentSelection: string
  ) => {
    setSelectedInstruments([
      ...selectedInstruments,
      { ...instrument, instrumentSelection },
    ])
  }

  const onInstrumentRemove = (instrumentId: number) => {
    const updatedSelectedInstruments = selectedInstruments.filter(
      (item) => item.ipid !== instrumentId
    )
    setSelectedInstruments(updatedSelectedInstruments)
  }

  const getFilterInstruments = () => {
    if (selectedInstruments.length === 0) return instruments

    const filterInstruments = instruments.filter(
      (item) =>
        selectedInstruments.findIndex((sitem) => sitem.ipid === item.ipid) ===
        -1
    )
    return filterInstruments
  }

  const onAssignBoosterClick = async () => {
    await updateAppState({ selectedInstruments }, appStateKey)
    navigate({
    pathname:  "/boosters",
    search: searchParams.toString()
    }, {state: {...location.state}})
  }

  return (
    <div>
      <CommonHeader
        header={`Setup Portfolio`}
        message={`Select 4 instruments to save portfolio. Select Long if Bullish, Select Short if Bearish.`}
        navigateBack={"/index"}
      />
      <div className="bg-white fixed w-screen h-7">
        <div className="grid grid-flow-col mx-4">
          <div
            className="border h-1 w-[79px] my-3 bg-[#E4E1E6] rounded-sm"
            style={{
              backgroundColor:
                selectedInstruments.length >= 1 ? "#3955C1" : "#E4E1E6",
            }}
          ></div>
          <div
            className="border h-1 w-[79px] my-3 bg-[#E4E1E6] rounded-sm"
            style={{
              backgroundColor:
                selectedInstruments.length >= 2 ? "#3955C1" : "#E4E1E6",
            }}
          ></div>
          <div
            className="border h-1 w-[79px] my-3  bg-[#E4E1E6] rounded-sm"
            style={{
              backgroundColor:
                selectedInstruments.length >= 3 ? "#3955C1" : "#E4E1E6",
            }}
          ></div>
          <div
            className="border h-1 w-[79px] my-3  bg-[#E4E1E6] rounded-sm"
            style={{
              backgroundColor:
                selectedInstruments.length >= 4 ? "#3955C1" : "#E4E1E6",
            }}
          ></div>
        </div>
        <hr/>
      </div>

      <div className="flex flex-col pt-7 pb-[76px] bg-[#F5F5F5]">
        {selectedInstruments.map((selectedInstrument) => (
          <SelectedInstrument
            key={`s-${selectedInstrument.ipid}`}
            selectedInstrument={selectedInstrument}
            onInstrumentRemove={onInstrumentRemove}
          />
        ))}
        {getFilterInstruments().map((instrument) => (
          <Instrument
            key={instrument.ipid}
            instrument={instrument}
            selectedInstruments={selectedInstruments}
            onInstrumentAdd={onInstrumentAdd}
          />
        ))}
      </div>
      <CommonFooter
        message={`You can edit your portfolio till market opens`}
        button={`Assign boosters`}
        buttonColor={selectedInstruments.length >= 4 ? "#08309E" : "#E4E1E6"}
        isDisabled={selectedInstruments.length < 4}
        onButtonClick={onAssignBoosterClick}
      />
    </div>
  )
}

export default Instruments
