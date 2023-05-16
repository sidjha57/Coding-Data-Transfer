import React from 'react'
import GreenLongIcon from '../assets/Images/GreenLongIcon.svg'
import RedShortIcon from '../assets/Images/RedShortIcon.svg'



const LongShort = ({instruments} :  any) => {
    return (
        <>
            {
                instruments &&
                instruments.map((instrument : any, index : number) => (
                    <span key={instrument.instrument.ipid} className='text-xs font-medium text-[#5E5E62]'>
                        <span className=''>

                            {instrument.instrument.instrumentName}
                        </span>
                        {
                            instrument.boosterSelection > 1 &&
                            <span>({instrument.boosterSelection}x)</span>
                        }   
                        {
                            index < instruments.length - 1 &&
                            <span>, </span>
                        }                 
                    </span>
                ))
            }
        </>
    )
}

const LongShortInstrument = ({portfolioSelections, colored} : any) => {

    const [longInstruments, setLongInstruments] = React.useState([])
    const [shortInstruments, setShortInstruments] = React.useState([])
  
    function distributeInstruments() {
      if (portfolioSelections) {

          const long = portfolioSelections.filter((instrument : any) => (instrument.instrumentSelection > 0))
          setLongInstruments(long);
          //   console.log(long)
          const short = portfolioSelections.filter((instrument : any) => (instrument.instrumentSelection < 0))
          setShortInstruments(short);
        }
    }
  
    React.useEffect(() => {
        distributeInstruments()
    }, [])

  return (
    <div className=''>
        {
            portfolioSelections &&
            <div>
            {
                longInstruments.length > 0 &&
                <div className='grid grid-flow-col '>
                    <div className="flex w-2 mr-2">
                        <img src={GreenLongIcon} className="h-4 w-3 py-1" alt="" />
                        <div className='ml-[2px]'>:</div>
                    </div>

                    <div className='w-[206px]'>
                        <LongShort instruments = {longInstruments} />
                    </div>
                </div>
            }
            <div></div>

            {
                shortInstruments.length > 0 &&
                <div className='grid grid-flow-col'>
                    <div className="flex w-2 mr-2">
                        <img src={RedShortIcon} className="h-4 w-3 py-1" alt="" />
                        <div className='ml-[2px]'>:</div>
                    </div>

                    <div className='w-[206px]'>
                        <LongShort instruments = {shortInstruments} />
                    </div>
                </div>
            }
         </div>
        }
    </div>
  )
}

export default LongShortInstrument