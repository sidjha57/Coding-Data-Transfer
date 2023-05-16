import React from 'react'
import LeftArrow from '/BackArrowIcon.png'
import { useNavigate } from 'react-router-dom'


const CommonHeader = ({header,message, navigateBack}) => {

  const navigate = useNavigate();
  const handleBack = (e) => {
    e.preventDefault();
    navigate(-1);
  }

  return (
    <header className='Header top-0 bg-white sticky w-screen'>
       <div className="">

        <nav className='flex space-x-4 mx-4 py-4'>
            {
              navigateBack &&
              <div onClick={handleBack} className=''>
                <img src={LeftArrow} className='h-5 w-5 my-1'/>
              </div>
            }
            <h1 className=' font-semibold text-xl'>
                {header}
            </h1>
        </nav>

        {
          message &&
          <div className='bg-light-background text-xs '>
          
              <div className='text-justify px-8 py-2'>
                  {message}
              </div>
          
            </div>
        }
      </div>
       
    </header>
  )
}

export default CommonHeader