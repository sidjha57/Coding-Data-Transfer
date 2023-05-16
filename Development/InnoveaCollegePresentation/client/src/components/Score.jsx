import React from 'react'
import { instrumentname } from '../assets/Instruments'

const Score = ({portfolio,entries,rank}) => {


  return (
    <div>
      {

          portfolio && entries && rank &&
          <div className=' h-16 w-92 m-4 justify-between shadow-md flex bg-white rounded-md items-center'>
            
            <div className='m-4 '>
                <div className='text-dark-text font-medium'>{portfolio.user.name}</div>
                <div className='text-xs text-dark-text'>
                    <span className=''>
                        {instrumentname[portfolio.instrument1]}({portfolio.booster1}),  {instrumentname[portfolio.instrument2]}({portfolio.booster2}),
                        <br/>
                        {instrumentname[portfolio.instrument3]}({portfolio.booster3}),  {instrumentname[portfolio.instrument4]}({portfolio.booster4})
                    </span>
                </div>
            </div>
            <div className='flex flex-col space-y-2 mx-4'>
                 {
                  portfolio.score.points > 0 ?
                    <p className='text-dark-text text-md text-green-500' >+{portfolio.score.points} Pts</p>
                  :
                    <p className='text-dark-text text-md text-red-500' >{portfolio.score.points} Pts</p>
                 }
                <p className='text-dark-text font-bold text-[1rem] text-right'>{rank}/{entries}</p>
            </div>
        </div>
      }
    </div>
  )
}

export default Score