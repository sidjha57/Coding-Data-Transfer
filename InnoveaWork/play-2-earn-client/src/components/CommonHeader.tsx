import React from "react"
import LeftArrow from "../assets/Images/BackArrowIcon.svg"
import { useNavigate } from "react-router-dom"

interface CommonFooterProps {
  header: string
  message?: string
  navigateBack?: string
}

const CommonHeader = ({ header, message, navigateBack }: CommonFooterProps) => {
  const navigate = useNavigate()
  const handleBack = () => {
    navigate(-1)
  }

  return (
    <header className='Header top-0 sticky w-screen bg-white'>


    <nav className='h-16 pl-4 space-x-2 flex '>
        {
          navigateBack &&
          <div onClick={handleBack} className='cursor-pointer justify-self-start place-content-center grid'>
            <img src={LeftArrow} height="16px" width="16px"  alt=""/>
          </div>
        }
        <div className='font-bold text-xl justify-self-start grid place-content-center text-[#303034]'>
            {header}
        </div>
    </nav>

    {
      message ?
      <div className='bg-[#F2F0F4] h-12 font-medium text-xs grid place-items-center'>

          <div className='justify-self-start mx-4 text-[#303034]'>
              {message}
          </div>

      </div>
      :
      <hr />
    }

</header>
  )
}

export default CommonHeader
