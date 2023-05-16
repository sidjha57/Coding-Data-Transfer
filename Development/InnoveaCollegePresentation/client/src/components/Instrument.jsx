import React, { useEffect, useRef, useState } from 'react'
import CrossIcon from '/cross.png'
import { useSelector, useDispatch } from 'react-redux'
import { instrumentname } from '../assets/Instruments'
import { AddInstrument, DeleteInstrument } from '../features/portfolioSlice'

const Instrument = ({name, disable}) => {
    const [typeName, setTypeName] = useState(""); 
    let instruments = useSelector((state) => state.portfolios.instruments.instrument)
    const dispatch = useDispatch();

    if (!instruments) {
        instruments = [];
    }

   console.log(instruments)

    useEffect(() =>{
        if (instruments.length > 0 && instruments[0]) {
            instruments.map((instrument) =>{
                if (instrument.name == name) {
                    instrument.booster > 0 ? setTypeName("Long") : setTypeName("Short")
                }
            })
        }
    }, [])

    function handleClick(e, name, booster, type) {
        e.preventDefault();

        console.log(e.target);
        if (booster) {
            if (instruments[0] && instruments.length >= 4) {
                return;
            }
            dispatch(AddInstrument({name:name, booster:booster}))

            setTypeName(type);

        } else {
            dispatch(DeleteInstrument(name))            
            setTypeName(null);
        }
    }


  return (
    <div className='border-[1px] border-y-slate-200 '>
        {!typeName ?
            <>
                { !disable ?
                    <div className='grid grid-flow-col place-items-center justify-between m-3 bg-background '>
                        <div className='font-extrabold text-[2vh] text-gray-800 flex-auto '>
                            {instrumentname[name]}
                        </div>
                        <div className='grid grid-flow-col gap-3'>
                            
                            <div id={1} className='cursor-pointer grid place-content-center h-[4vh] w-[20vw] bg-[#008B1E] rounded-sm' onClick={(e) => handleClick(e,name,1, "Long")} name='Long'>
                                <span name="Long" className=' text-white text-sm font-semibold' >
                                    Long
                                </span>
                            </div>

                            <div id={-1} className='cursor-pointer grid place-content-center h-[4vh] w-[20vw] bg-[#E46962] rounded-sm' onClick={(e) => handleClick(e,name,-1, "Short")} name='Short'>
                                <span name="Short" className=' text-white text-sm font-semibold' >
                                    Short
                                </span>
                            </div>
                        </div>
                    </div>
                   :
                    <div className='grid grid-flow-col place-items-center justify-between m-3'>
                         <div className='font-extrabold text-[2vh] text-[#dadbda] flex-auto '>
                            {instrumentname[name]}
                        </div>

                        <div className='grid grid-flow-col gap-3 '>
                            
                            <div id={1} className='cursor-pointer grid place-content-center h-[4vh] w-[20vw] bg-[#cde8d3] rounded-sm' onClick={(e) => handleClick(e,name,0,"Long")} name='Long'>
                                <span name="Long" className=' text-white text-sm font-semibold'>
                                    Long
                                </span>
                            </div>

                            <div id={-1} className='cursor-pointer grid place-content-center h-[4vh] w-[20vw] bg-[#fae1e0] rounded-sm' onClick={(e) => handleClick(e,name,0, "Short")} name='Short'>
                                <span name="Short" className=' text-white text-sm font-semibold'>
                                    Short
                                </span>
                            </div>
                        </div>
                       
                    </div>
                }

            </>

            :

            <div className=' bg-dark-background'>
                <div className='grid grid-flow-col place-items-center justify-between'>
                    <div className='font-extrabold text-[2vh] text-gray-800 flex-auto m-3'>
                        {instrumentname[name]}
                        <div className='text-xs text-light-text font-semibold'>
                            {typeName}
                        </div>
                    </div>
                    <div className='m-3 cursor-pointer'>
                        <div className='' onClick={(e) => handleClick(e,name,0)} >
                            <img className='w-5 h-5' src={CrossIcon} alt="" />
                        </div>
                    </div>
                </div>

            </div> 
        }
      

    </div>

  )
}

export default Instrument