import React, { useState } from "react"
import { useNavigate, useSearchParams } from "react-router-dom"

import Briefcase from "../assets/Images/BriefcaseIcon.svg"
import Pointer from "../assets/Images/PointIcon.svg"
import Trophy from "../assets/Images/TrophyIcon.svg"
import Modal from "../components/Modal"

const Home = () => {
  const navigate = useNavigate()
  const [modalOpen, setModalOpen] = useState(true)

  const handleClick = async () => {
    setModalOpen(false)
    navigate({
      pathname:"/index",
      search: '?contestType=daily&catalogType=index&portfolioStatus=joined'
    })
  }

  const modalContent = (
    <div className="py-10 mx-5 rounded-xl bg-gradient-to-br from-[#294AA4] to-[#030A1C]">
      <div
        onClick={handleClick}
        className="mr-7 mt-[-20px] cursor-pointer text-xl text-white flex justify-end"
      >
        ✕
      </div>

      <div className="flex space-x-3">
        <div></div>
        <div>
          <div className="h-10 w-10 bg-[#ECF1FF1A] bg-opacity-10 text-white rounded-full text-center my-2">
            <img src={Briefcase} alt=""/>
          </div>
          <div className="w-[0.1rem] ml-5 my-2 h-16 bg-[#d3d3d4]"></div>
        </div>

        <div className="space-y-4">
          <div className=" text-xl mt-4 text-white">Setup Portfolio</div>
          <div className="text-[#C8C6CA] font-medium text-sm mr-10">
            Select from market instrument to go Long or Short & assign boosters.
          </div>
  
        </div>
      </div>
      <div className="flex space-x-3">
        <div></div>
        <div>
          <div className="h-10 w-10 bg-[#ECF1FF1A] bg-opacity-10 text-white rounded-full text-center my-2 p-1">
            <img height={35} width={35} src={Pointer} alt=""/>
          </div>
          <div className="w-[0.1rem] ml-5 my-2 h-16 bg-[#d3d3d4]"></div>
        </div>

        <div className="space-y-4">
          <div className=" text-xl mt-4 text-white">Join Contest</div>
          <div className="text-[#C8C6CA] font-medium text-sm mr-10">
            Choose joining mode, Pay and Enter. You can join as spectator too.
          </div>
        </div>
      </div>
      <div className="flex space-x-3">
        <div></div>
        <div>
          <div className="h-10 w-10 bg-[#ECF1FF1A] bg-opacity-10 text-white rounded-full text-center my-2">
            <img src={Trophy} alt=""/>
          </div>
        </div>

        <div className="space-y-4">
          <div className=" text-xl mt-4 text-white">Your Results</div>
          <div className="text-[#C8C6CA] font-medium text-sm mr-10">
            Check your gains, rank and performance.
          </div>
        </div>
      </div>
    </div>
  )

  return (
    <>
      {modalOpen && (
        <Modal
          children={modalContent}
          onClose={() => {
            setModalOpen(false)
          }}
        />
      )}
    </>
  )
}

export default Home
