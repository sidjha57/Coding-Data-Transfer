import React from 'react'
import { useLocation, useNavigate } from 'react-router-dom'
import moment from 'moment'


const Result = () => {
    const location = useLocation().state;
    const portfolio = location.portfolio;
    const score = portfolio.score.points;
    const rank = location.rank;
    const entries = location.entries;
    const navigate = useNavigate()
  
    const handleScore = () => {
        navigate("/leaderboard", {state:{rank:rank, entries:entries, status:"live"}})
    }

    const handlePerformance = () =>{
        navigate("/performance", {state:{score:score, portfolio:portfolio}});
    }

  return (
    <div className=''>
        
{/* 
        <div className='RevisePortfolioContainer h-14 w-92 m-4 shadow-md flex justify-around bg-white rounded-md items-center'>
            
            <div className=''>
                <p className='text-xs text-dark-text'>
                    You can revise your portfolio till the <br/> market opens.
                </p>
            </div>
            <div className='h-5 bg-primary-color grid place-content-center rounded-md ml-9'>
                <p className='text-white text-sm mx-2 ' >Revise</p>
            </div>
        </div> */}

        <div onClick={handlePerformance} className=' h-14 w-92 m-4 justify-between shadow-md flex bg-white rounded-md items-center'>
            
            <div className='mx-4'>
                <div className='text-dark-text font-bold'>Portfolio Gains</div>
                <div className='text-xs text-dark-text'>Score</div>
            </div>
            <div className='mx-4'>
                <p className='text-dark-text font-bold mx-2 text-xl' >{score > 0 ? `+${score}`: score} Pts</p>
            </div>
        </div>
        <div onClick={handleScore} className=' h-14 w-92 m-4 justify-between shadow-md flex bg-white rounded-md items-center'>
            
            <div className='mx-4'>
                <div className='text-dark-text font-bold'>Rank</div>
                <div className='text-xs text-dark-text'>Top 10% out of {entries} entries</div>
            </div>
            <div className='mx-4'>
                <p className='text-dark-text font-bold mx-2 text-xl' >{rank}</p>
            </div>
        </div>
        {/* <div className=' h-14 w-92 m-4 justify-between shadow-md flex bg-white rounded-md items-center'>
            
            <div className='mx-4'>
                <div className='text-dark-text font-bold'>Return Potential</div>
                <div className='text-xs text-dark-text'>Estd. INR 2500</div>
            </div>
            <div className='mx-4'>
                <p className='text-dark-text font-bold mx-2 text-xl' >2.5x</p>
            </div>
        </div> */}
    </div>
  )
}

export default Result