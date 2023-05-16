import React, { useRef } from 'react'
import WhiteHomeIcon from '/WhiteHomeIcon.png';
import BlackHomeIcon from '/BlackHomeIcon.png';
import WhiteTrophyIcon from '/WhiteTrophyIcon.png';
import BlackTrophyIcon from '/BlackTrophyIcon.png';
import WhiteAnalysisIcon from '/WhiteAnalysisIcon.png';
import BlackAnalysisIcon from '/BlackAnalysisIcon.png';
import { useNavigate } from 'react-router-dom';
import { useDispatch, useSelector } from 'react-redux';
import { SetFooterStatus } from '../features/selectedSlice';

const Footer = () => {
    const navigate = useNavigate();
    const footerStatus = useSelector((state) => state.selected.footerStatus)
    const dispatch = useDispatch();

    const handleClick = (e) => {
        e.preventDefault();
        dispatch(SetFooterStatus(e.target.name));
        navigate("/" + e.target.name);
    }

  return (
    <footer className='bg-white fixed w-screen bottom-0 h-16 grid grid-flow-col place-content-center justify-evenly'>
       

          <div className='mt-5' name="home" onClick={handleClick} >
              { footerStatus == 'home' &&
                <div name="home"  className="block cursor-pointer select-none font-bold">
                    <img name="home" className='h-5 w-5 mx-4' src={BlackHomeIcon} alt="" />
                    <p name="home" className='text-xs my-2 text-center ' >Home</p>            
                </div>
              } 
              {
                footerStatus != 'home' &&
                 <div name="home"  className="block cursor-pointer select-none  ">
                    <img name="home" className='h-5 w-5 mx-4' src={WhiteHomeIcon} alt="" />
                    <p name="home" className='text-xs my-2  text-center ' >Home</p>            
                 </div>
              }
          </div>
        

        <div className='mt-5'  name="index" onClick={handleClick}>
            {
              footerStatus == 'index' &&
              <div name="index"  className="block cursor-pointer select-none font-bold">
                <img  name="index" className='h-4 w-4 mx-5'  src={BlackTrophyIcon} alt="" />
                <p  name="index" className='text-xs my-3 text-center ' >IndexPlay</p>
              </div>
            }
            {
              footerStatus != 'index' &&
              <div name="index"  className="block cursor-pointer select-none  ">
                <img  name="index" className='h-4 w-4 mx-5'  src={WhiteTrophyIcon} alt="" />
                <p  name="index" className='text-xs my-3 text-center ' >IndexPlay</p>
              </div>
            }
        </div>

        <div className='mt-5' onClick={handleClick}>
            {
              footerStatus == 'stock' &&
              <div name="stock"  className="block cursor-pointer select-none font-bold">
                  <img name="stock" className='h-4 w-4 mx-5'  src={BlackTrophyIcon} alt="" />
                  <p name="stock" className='text-xs my-3 text-center ' >StockPlay</p>
              </div>
            } 
            {
              footerStatus != 'stock' &&
              <div name="stock"  className="block cursor-pointer select-none  ">
                <img name="stock" className='h-4 w-4 mx-5'  src={WhiteTrophyIcon} alt="" />
                <p name="stock" className='text-xs my-3 text-center ' >StockPlay</p>
              </div>
            }
        </div>

        <div className='mt-5' onClick={handleClick}>
            {
              footerStatus == 'analysis' &&
              <div name="analysis"  className="block cursor-pointer select-none font-bold "> 
                  <img name="analysis" className='h-5 w-5 mx-4'  src={BlackAnalysisIcon} alt="" />
                  <p name="analysis" className='text-xs my-2 text-center'>Learn</p>
              </div>
            } 
            {
                footerStatus != 'analysis' &&
                <div name="index"  className="block cursor-pointer select-none  ">
                  <img name="analysis" className='h-5 w-5 mx-4'  src={WhiteAnalysisIcon} alt="" />
                  <p name="analysis" className='text-xs my-2 text-center'>Learn</p>
                </div>
            }
        </div>
    </footer>
  )
}

export default Footer