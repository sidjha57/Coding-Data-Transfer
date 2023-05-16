import React from 'react'
import { useNavigate } from 'react-router-dom'

const CommonFooter = ({message, button, buttonColor, assignBooster}) => {

  const navigate = useNavigate();
  const handleFront = () => {
    navigate(assignBooster);
  }
  console.log(buttonColor)
  return (
    <footer className='Footer '>
        <div className='bg-white place-content-center fixed bottom-0 w-screen items-center flex flex-col'>
            <span className='text-[0.7rem] font-semibold text-gray-700 mx-5 py-3'>{message}</span>
            <div className='pb-3'>
                <button  onClick={handleFront} className='bg-primary-color h-[6vh] w-[90vw] mx-3 justify-center  text-white text-xl align-center rounded-md' style={{backgroundColor: buttonColor}}>{button}</button>
            </div>
        </div>
    </footer>
  )
}

export default CommonFooter