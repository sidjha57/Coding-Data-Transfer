import React, { useEffect, useRef, useState } from 'react'
import CommonHeader from '../components/CommonHeader'
import InstrumentPerformance from '../components/InstrumentPerformance'
import { getInstruments } from '../api/Instruments'
import { useLocation } from 'react-router-dom'

const Portfolio_Performance = () => {
  const [instruments, SetInstruments] = useState(null);
  const [selectedInstruments,setSelectedInstruments] = useState(null);
  const [nonSelectedInstruments,setNonSelectedInstruments] = useState(null);
  const location = useLocation().state;
  const score = location.score;
  const portfolio = location.portfolio;



  console.log(portfolio);
  const fetch = async () => {
    await getInstruments()
    .then((res) => {

      const selected = res.data.filter((instrument) => {
        if (instrument.id == portfolio.instrument1) {
          instrument.booster = portfolio.booster1;
          return instrument;
        }
        if (instrument.id == portfolio.instrument2) {
          instrument.booster = portfolio.booster2;
          return instrument;
        }
        if (instrument.id == portfolio.instrument3) {
          instrument.booster = portfolio.booster3;
          return instrument;
        }
        if (instrument.id == portfolio.instrument4) {
          instrument.booster = portfolio.booster4;
          return instrument;
        }
      })

      const nonSelected = res.data.filter((instrument) => {
        if (instrument.id != portfolio.instrument1 && instrument.id != portfolio.instrument2 && instrument.id != portfolio.instrument3 && instrument.id != portfolio.instrument4)
          return instrument;
      })

      SetInstruments(res.data);
      setSelectedInstruments(selected);
      setNonSelectedInstruments(nonSelected);
    })
    .catch((err) => {console.log(err)})
  }
  useEffect( () => {
    fetch()
  }, [])


  console.log(selectedInstruments);
  console.log(nonSelectedInstruments);

  return (
    <div>
        <CommonHeader header={`Portfolio Performance`} navigateBack={"/results"}/>
        <div className=' h-14 w-92 m-4 justify-between shadow-md flex bg-white rounded-md items-center'>
            
            <div className='mx-4'>
                <div className='text-dark-text font-bold'>Portfolio Gains</div>
                <div className='text-xs text-dark-text'>Score</div>
            </div>
            <div className='mx-4'>
                <p className='text-dark-text font-bold mx-2 text-xl' >{score > 0 ? `+${score}` : score} Pts</p>
            </div>
        </div>

        <div>
          <div className='m-4 font-bold text-dark-text'>Your Selections</div>
          <div className='h-fit w-92 m-4 shadow-md bg-white rounded-md'>
            {
              selectedInstruments && 
              selectedInstruments.map((instrument) => (
                <div className="" key={instrument.id}>
                  <InstrumentPerformance instrument={instrument} type={1}/>
                </div>
              )) 
            }
          </div>
          <div className='m-4 font-bold text-dark-text'>Other Indices</div>
          <div className='h-fit w-92 m-4 shadow-md bg-white rounded-md'>
            {
              nonSelectedInstruments && 
              nonSelectedInstruments.map((instrument) => (
                <div className="" key={instrument.id}>
                  <InstrumentPerformance instrument={instrument} type={0}/>
                </div>

              )) 
            }

          </div>
        </div>
    </div>
  )
}

export default Portfolio_Performance