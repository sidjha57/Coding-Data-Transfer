import React, { useCallback, useEffect, useState } from "react"
import { useLocation, useNavigate } from "react-router-dom"
import { getContestParameter } from "../api/Contests"
import { createUserPortfolioInstance, editPortfolioById } from "../api/Portfolio"
import Booster from "../components/Booster"
import CommonHeader from "../components/CommonHeader"
import { useAuth } from "../context/AuthContext"
import { InstrumentType } from "../interface/Intrument"
import { Selection, Status } from "../interface/Portfolio"
import { addDataIntoCache, getData } from "../js/caching"
import { frontendUrl } from "../js/urls"
import { appStateKey, getAppState , updateAppState} from "../lib/appState"

const Boosters = () => {
  const { user } = useAuth()

  const location = useLocation()
  console.log(location.state)
  const contestId = location.state.contest.ipid;

  const [selectedInstruments, setSelectedInstruments] = useState<
    InstrumentType[]
  >([])
  const [boosters, setBoosters] = useState<number[]>([])

  const fetchSelectedInstrumentsAndContestBoosters = useCallback(async () => {
    const { parameterId, selectedInstruments: _selectedInstruments } = await getAppState(appStateKey)
      const {
        data: { booster1, booster2, booster3 },
      } = await getContestParameter(location.state.contestParameterId)

      setBoosters(
        [booster1, booster2, booster3].filter((booster) => booster !== null)
      )
    
    setSelectedInstruments(_selectedInstruments)
  }, [])

  useEffect(() => {
    if (selectedInstruments.length === 0)
      fetchSelectedInstrumentsAndContestBoosters()
  }, [selectedInstruments, fetchSelectedInstrumentsAndContestBoosters])

  const onBoosterSelect = (instrumentId: number, boosterSelection: number) => {

    setSelectedInstruments(
      selectedInstruments
        .map((item) =>
          item.ipid === instrumentId ? { ...item, boosterSelection } : item
        )
        .map(({ boosterSelection: _boosterSelection, ...item }) =>
          item.ipid !== instrumentId && _boosterSelection === boosterSelection
            ? item
            : { ...item, boosterSelection: _boosterSelection }
        )
    )

    console.log(selectedInstruments);
  }

  const navigate = useNavigate()

  const handleClick = async (e: any) => {
    e.preventDefault()

    const selections = new Array<Selection> ();
    selectedInstruments.forEach((selected : InstrumentType) => {
      selections.push({
        instrumentId : selected.ipid,
        instrumentSelection: selected.instrumentSelection === "Long" ? 1 : -1,
        boosterSelection: selected.boosterSelection ? selected.boosterSelection : 1
      })
    })

    // console.log(user);
    const data = await getData("EditState");

    if (data && data.edit) {
      selections.map((selected : Selection) => {
        return selected.portfolioId = data.portfolioId
      })
      const status : Status = {
        ipid: data.statusId,
        portfolioStatus : e.target.name
      }
      Promise.all([addDataIntoCache("EditState", frontendUrl, {edit: false, portfolioId : null, statusId: null}), editPortfolioById(data.portfolioId, status, selections)])
    } else {
      try {
        await createUserPortfolioInstance(user.ipid, contestId, e.target.name, selections);
      } catch (err) {
        console.log(err)
      }
    }

    // Making selectedInstruments Empty
    updateAppState({ selectedInstruments : [] }, appStateKey)
    navigate(-2)

  }

  return (
    <div className="bg-[#F5F5F5]">
      <CommonHeader
        header={`Setup Portfolio`}
        message={`Choose boosters for indices where you have conviction. This is optional. You can revise till contest goes live.`}
        navigateBack={"/instruments"}
      />

      <div className="pb-20">
        {selectedInstruments.length ? (
          <div className="">
            {selectedInstruments.map((instrument) => (
              <div key={instrument.ipid}>
                <Booster
                  instrument={instrument}
                  boosters={boosters}
                  onBoosterSelect={onBoosterSelect}
                  />
                <hr />
              </div>
            ))}
          </div>
        ) : (
          <div> No instruments selected </div>
          )}

      </div>

      <footer className="Footer ">
        <div className=" bg-white border-t border-1 place-content-center fixed bottom-0 w-screen h-[76px] grid grid-flow-col space-x-3">
            <button
              onClick={handleClick}
              name="SAVED"
              className="outline outline-1 outline-primary-color h-11 w-[44vw]  justify-center  text-primary-color  align-center rounded-md font-bold text-sm"
            >
              Save
            </button>
            <button
              onClick={handleClick}
              name="JOINED"
              className="bg-primary-color h-11 w-[44vw]  justify-center  text-white  align-center rounded-md font-bold text-sm"
            >
              Join
            </button>
        </div>
      </footer>
    </div>
  )
}

export default Boosters
