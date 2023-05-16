import React, { useEffect, useState } from "react"
import Modal from "./Modal"
import Briefcase from "../assets/Images/BriefcaseIcon.svg"
import Pointer from "../assets/Images/PointIcon.svg"
import Trophy from "../assets/Images/TrophyIcon.svg"
import { AppState } from "../lib/indexDB"
import { appStateKey } from "../lib/appState"

interface P2EProsp {
  updateAppState: ({ showAppIntro }: AppState, key: number) => void
  showAppIntro: boolean
}

function P2EPopup(props: P2EProsp) {
  const [modalOpen, setModalOpen] = useState(props.showAppIntro)

  useEffect(() => {
    setModalOpen(props.showAppIntro)
  }, [props.showAppIntro])

  const handlePopupClose = () => {
    setModalOpen(false)
    props.updateAppState({ showAppIntro: false }, appStateKey)
  }

  return (
    <>
      {modalOpen && (
        <Modal>
          <div className="py-10 mx-5 rounded-xl bg-gradient-to-br from-[#294AA4] to-[#030A1C]">
            <div
              onClick={() => handlePopupClose()}
              className="mr-7 mt-[-20px] cursor-pointer text-xl text-white flex justify-end"
            >
              ✕
            </div>

            <div className="flex space-x-3">
              <div></div>
              <div>
                <div className="h-10 w-10 bg-[#ECF1FF1A] bg-opacity-10 text-white rounded-full text-center my-2">
                  <img src={Briefcase} alt="" />
                </div>
                <div className="w-[0.1rem] ml-5 my-2 h-16 bg-[#d3d3d4]"></div>
              </div>

              <div className="space-y-4">
                <div className=" text-xl mt-4 text-white">Setup Portfolio</div>
                <div className="text-[#C8C6CA] font-medium text-sm mr-10">
                  Select from market instrument to go Long or Short & assign
                  boosters.
                </div>
                {/* <div onClick={handleClick} className='cursor-pointer h-7 w-20 text-white bg-primary-color rounded-md text-center'>
               Continue
           </div> */}
              </div>
            </div>
            <div className="flex space-x-3">
              <div></div>
              <div>
                <div className="h-10 w-10 bg-[#ECF1FF1A] bg-opacity-10 text-white rounded-full text-center my-2 p-1">
                  <img height={35} width={35} src={Pointer} alt="" />
                </div>
                <div className="w-[0.1rem] ml-5 my-2 h-16 bg-[#d3d3d4]"></div>
              </div>

              <div className="space-y-4">
                <div className=" text-xl mt-4 text-white">Join Contest</div>
                <div className="text-[#C8C6CA] font-medium text-sm mr-10">
                  Choose joining mode, Pay and Enter. You can join as spectator
                  too.
                </div>
                {/* <div className='text-[#C8C6CA] font-medium text-xs'>
               Closes in <span className='f text-xl mt-1 text-white'>11h : 29 min</span>
           </div> */}
              </div>
            </div>
            <div className="flex space-x-3">
              <div></div>
              <div>
                <div className="h-10 w-10 bg-[#ECF1FF1A] bg-opacity-10 text-white rounded-full text-center my-2">
                  <img src={Trophy} alt="" />
                </div>
                {/* <div className='w-[0.1rem] mx-5 my-2 h-28 bg-[#d3d3d4]'></div> */}
              </div>

              <div className="space-y-4">
                <div className=" text-xl mt-4 text-white">Your Results</div>
                <div className="text-[#C8C6CA] font-medium text-sm mr-10">
                  Check your gains, rank and performance.
                </div>
              </div>
            </div>
          </div>
        </Modal>
      )}
    </>
  )
}

export default P2EPopup
