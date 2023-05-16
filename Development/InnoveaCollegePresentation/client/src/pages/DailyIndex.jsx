import moment from 'moment'
import React, { useEffect, useRef, useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'
import { useNavigate } from 'react-router-dom'
import { getUserPortfolios, getUserPortfoliosByStatus, updatePortfolioById } from '../api/Portfolio'
import AddIcon from "/AddIcon.png";
import LivePortfolio from '../components/LivePortfolio'
import Portfolio from '../components/Portfolio'
import SavedPortfolio from '../components/SavedPortfolio'
import { SetPortfolio } from '../features/portfolioSlice'

import placeholderImage from "/IndexPlay_home.svg"

const DailyIndex = ({contestStatus, entries}) => {
  const user = useSelector((state) => state.authenticate.user);
  const portfolioStatus = useSelector((state) => state.selected.portfolioStatus);
  const now = moment().format('HH:mm:ss a');
  const currentTime = moment(now, 'HH:mm:ss ');
  const startTime = moment("09:30:00 ", 'HH:mm:ss ');
  const endTime = moment("15:15:00 ", 'HH:mm:ss ');
  const [returningUser,setReturningUser] = useState(0);
  let timeleft = moment.duration(startTime.diff(currentTime));

  if (contestStatus == "live") {
    timeleft = moment.duration(endTime.diff(currentTime));
  }

  console.log(portfolioStatus);
  const dispatch = useDispatch();
  const navigate = useNavigate();
  
  const fetchData = async () => {
    await getUserPortfolios(user.id).then((res) => {
        res.data.data.map((portfolio) => {
            // console.log(portfolio.status)
            if (portfolio.status == "joined" || portfolio.status == "live")
                setReturningUser(1);
        })
        
        dispatch(SetPortfolio(res.data.data))
    }).catch ((err) => {console.log(err)})
  }

  useEffect(() => {
    fetchData()
  }, [returningUser])

  const handleClick = () => {
    navigate("/instruments");
  }


  return (
        
        <main className='pt-2'>
            
            <div className='pt-[18vh] mx-3 py-2 text-gray-700'>
                <div className='grid grid-flow-col place-content-between'>
                    <div className='font-bold'>
                        Daily Contest  {moment().format('D MMM')}
                    </div>
                    <p className='p-2 grid place-content-center capitalize box-border text-center text-xs text-gray-700 rounded-2xl h-5 w-fit border border-gray-400'>
                       {contestStatus}
                    </p>
                </div>

                <div className=" grid grid-flow-col place-content-between">
                    <div className="text-xs font-medium">9:30 AM - 3:15 PM</div>
                    <div className='text-xs'>
                        {
                            contestStatus == "live" ?
                            <span className='font-medium'>
                        
                                Ends in 
                        
                            </span>
                            :
                            <span className='font-medium'>
                        
                                Starts in 
                    
                            </span>
                        }
                     <span className='text-[#93000A] font-bold ml-1'>
                        { parseInt(timeleft.asHours())}h:{parseInt(timeleft.asMinutes()) % 60}m
                     </span>
                    </div>
                </div>
            </div>

            <div className='Portfolios pt-[2vh] '> 
                {
                    contestStatus == "live" && portfolioStatus == "joined"  &&
                    <div > 
                        <LivePortfolio status={"live"} entries={entries} />
                    </div> 
                }
                {
                    portfolioStatus == "joined" &&
                    <div>
                        <Portfolio status={"joined"} entries={entries}/>
                    </div>
                } 
                {
                    portfolioStatus == "completed" &&
                    <div>
                        <Portfolio status={"completed"} entries={entries}/>
                    </div>
                }
            </div>
            {
                portfolioStatus == "joined" &&
                <div>
                    {
                        !returningUser &&
                        <div className=" flex justify-center">
                            <img src={placeholderImage}  width="300"/>
                        </div>
                    }
                    <div className='grid py-4 space-y-4'>
                        <span className='text-[0.8em] text-center font-medium text-gray-700'>
                            You can enter upto <span className='font-bold'>5</span> portfolios for this upcoming contest.
                            <br/> Tap + to create portfolios to join the contest  
                        </span>
                        <div className='bg-[#E4E1E6] h-1'></div>
                    </div>

                    {
                        contestStatus == "live" ?
                        <div className='z-20 left-[80vw] top-[82vh] fixed '>
                            <div onClick={handleClick} className='bg-[#E4E1E6]  grid place-items-center font-bold h-14 w-14 text-white rounded-2xl ' >
                                <img className='h-4 w-4' src={AddIcon}></img>
                            </div>
                        </div>
                        :
                        <div className='z-20 left-[80vw] top-[82vh] fixed cursor-pointer drop-shadow-xl'>
                            <div onClick={handleClick} className='bg-gradient-to-r from-[#0B49F4] to-[#022278] shadow-lg grid place-items-center font-bold h-14 w-14 text-white rounded-2xl ' >
                                <img className='h-4 w-4' src={AddIcon}></img>
                            </div>
                        </div>
                    }

                    <div className="bg-background mb-[18vh]">
                        <SavedPortfolio contestStatus={contestStatus} setReturningUser={setReturningUser}/>
                    </div>

                   
                </div>
            }

          
           
        </main>
  )
}

export default DailyIndex


