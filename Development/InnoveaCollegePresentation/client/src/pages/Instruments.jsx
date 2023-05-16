import React, { useState , useEffect} from 'react'
import CommonFooter from '../components/CommonFooter'
import CommonHeader from '../components/CommonHeader'
import Instrument from '../components/Instrument'
import { useSelector } from 'react-redux'
import { instrumentsymbol } from '../assets/Instruments'


const Instruments = () => {
    let instruments = useSelector((state) => state.portfolios.instruments.instrument)
    let disable = false;

    if (!instruments) {
        instruments = [];
    }

    if ( instruments[0] != null && instruments.length >= 4) {
        disable = true;
    } else {
        disable = false;
    }
  
    console.log(instruments);

  return (
    <div>
    
        <CommonHeader header={`Setup Portfolio`} message={`Select 4 instruments to save portfolio. Select Long if Bullish, Select Short if Bearish.`} navigateBack={"/index"} />
        <div className='bg-white fixed w-screen'>
            <div className='flex space-x-1 mb-2 justify-center'>
                <div className='box-border h-1 w-20 pt-30 mt-2  bg-[#E4E1E6] rounded-sm' style={{backgroundColor:  instruments[0] && instruments.length >= 1?  "#546FDC" : "#C8C6CA"}}></div>
                <div className='box-border h-1 w-20 pt-30 mt-2  bg-[#E4E1E6] rounded-sm' style={{backgroundColor:  instruments[0] && instruments.length >= 2?  "#546FDC" : "#C8C6CA"}}></div>
                <div className='box-border h-1 w-20 pt-30 mt-2  bg-[#E4E1E6] rounded-sm' style={{backgroundColor:  instruments[0] && instruments.length >= 3?  "#546FDC" : "#C8C6CA"}}></div>
                <div className='box-border h-1 w-20 pt-30 mt-2  bg-[#E4E1E6] rounded-sm' style={{backgroundColor:  instruments[0] && instruments.length >= 4?  "#546FDC" : "#C8C6CA"}}></div>
            </div>
        </div>

        <div className='flex flex-col py-[2vh] pb-[5vh]'>
            {
                instrumentsymbol.map((instrument) =>(
                    <div key={instrument}> 
                        <Instrument name={instrument} disable={disable} />
                    </div>
                ))
            }
        </div>
        <CommonFooter message={`You can edit your portfolio till market opens`} button={`Assign boosters`} buttonColor={ instruments[0] && instruments.length >= 4? "#08309E" : "#E4E1E6"} assignBooster={"/boosters"}/>
    </div>
  )
}

export default Instruments