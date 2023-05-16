import React, { useEffect, useRef, useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'
import { useNavigate } from 'react-router-dom'
import { countPortfoliosByStatusOfUser } from '../api/Portfolio'
import Booster from '../components/Booster'
import CommonHeader from '../components/CommonHeader'
import { SetPortfolio, UpdatePortfolios } from '../features/portfolioSlice'

const Boosters = () => {
  const selectedInstruments = useSelector((state) => state.portfolios.instruments.instrument);
  const user = useSelector((state) => state.authenticate.user);
  const portfolios = useSelector((state) => state.portfolios.portfolios)
  const dispatch = useDispatch();
  const navigate = useNavigate();
  const [error, setError] = useState();


  const booster1 = useRef(null);
  const booster2 = useRef(null);

  const handleClick = async (e) => {
    e.preventDefault()
    if (e.target.name == "joined") {
        await countPortfoliosByStatusOfUser(user.id, "joined").then((res) => {
            if (res.data.data == 5) {
                setError(" You can have only upto 5 portfolios in joined state");
                setTimeout(() => {
                    setError(null);
                }, 3000);
            } else {
                dispatch(UpdatePortfolios({status: e.target.name, user_id: user.id}));
                SetPortfolio(portfolios)
                navigate('/index')            
            }
        }).catch((err) => console.log(err))
    } else {
        dispatch(UpdatePortfolios({status: e.target.name, user_id: user.id}));
        SetPortfolio(portfolios)
        navigate('/index')
    }
   
  }

  return (
    <div>
        <CommonHeader header={`Setup Portfolio`} message={`Select conviction multiples 2x & 1.5x for instruments that has potential to perform well`} navigateBack={"/instruments"}/>
        {
                error && 
                <div className=" mx-2 text-sm text-red-900 rounded-lg bg-red-50 dark:text-red-400 grid place-content-center" role="alert">
                    Danger alert!  
                    {error}
                </div>
        }
        {
            selectedInstruments ?  
            <div className='flex flex-col  pb-24'>
                {
                    selectedInstruments.map((instrument) => (
                        <div key={instrument.name}> 
                            <Booster instrument={instrument} booster1={booster1} booster2={booster2} />
                            <hr/>
                        </div>
                    ))
                }
            </div>
            :
            <div> No instruments selected </div>
        }
        
     

        <footer className='Footer '>
            <div className='bg-light-background place-content-center fixed bottom-0 w-screen items-center flex flex-col'>
                <span className='text-[0.7rem] font-semibold text-gray-700 mx-5 py-3'>You can edit your portfolio till market opens</span>
                <div className='pb-3 flex'>
                    <button onClick={handleClick} name="saved" className='outline outline-1 outline-primary-color h-12 w-[10rem] mx-3 justify-center  text-primary-color  align-center rounded-md font-semibold'>Save</button>
                    <button onClick={handleClick} name="joined" className='bg-primary-color h-12 w-[10rem] mx-3 justify-center  text-white  align-center rounded-md font-semibold' >Join</button>
                </div>
            </div>
        </footer>
    </div>
  )
}

export default Boosters