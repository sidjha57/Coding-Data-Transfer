import React, { useEffect, useState } from 'react'
import editIcon from '/edit.png'
import deleteIcon from '/delete.png'
import PortfolioIcon from '/PortfolioIcon.png'
import { instrumentname } from '../assets/Instruments';
import { useDispatch, useSelector } from 'react-redux';
import {DeletePortfolio, EditPortfolioStatus, SetInstrument, SetPortfolio} from "../features/portfolioSlice"
import { countPortfoliosByStatusOfUser, getUserPortfolios } from '../api/Portfolio';
import { addDataIntoCache } from '../js/caching';
import { useNavigate } from 'react-router-dom';


const SavedPortfolio = ({contestStatus, setReturningUser}) => {
    const user = useSelector((state) => state.authenticate.user);
    const navigate = useNavigate();
    const [error, setError] = useState(null); 
    const portfolios = useSelector((state) => state.portfolios.portfolios);
    const dispatch = useDispatch();
    let count = 1;
    
    // console.log(portfolios);

    const handleEdit = async (saved) => {
        console.log(saved);
        const instruments = {
            id : null,
            instrument : []
        };
        instruments.id = saved.id;
        instruments.instrument.push({name: saved.instrument1, booster: saved.booster1})
        instruments.instrument.push({name: saved.instrument2, booster: saved.booster2})
        instruments.instrument.push({name: saved.instrument3, booster: saved.booster3})
        instruments.instrument.push({name: saved.instrument4, booster: saved.booster4})
        // instruments.push({id: saved.id})
        SetInstrument(instruments);
        addDataIntoCache("instruments", "http://localhost:5173", instruments)
        console.log(instruments);
        
        navigate('/instruments')
    }

    const handleDelete = async (id) => {
        console.log(id);
        dispatch(DeletePortfolio(id));
        await getUserPortfolios(user.id).then((res) => {
            dispatch(SetPortfolio(res.data.data))
        }).catch ((err) => {console.log(err)})
    }

    const handleJoin = async (saved,index) => {
        console.log(index);
        await countPortfoliosByStatusOfUser(user.id, "joined").then((res) => {
            if (res.data.data == 5) {
                setError(" You can have only upto 5 portfolios in joined state");
                setTimeout(() => {
                    setError(null);
                }, 3000);
            } else {
                dispatch(EditPortfolioStatus({index: index, status : "joined"}))
            }
        }).catch((err) => console.log(err))
        setReturningUser(1);
    }


  return (
    
    <div className=' '>
        {
            error && 
            <div className=" mx-2 text-sm text-red-900 rounded-lg bg-red-50 dark:text-red-400 grid place-content-center" role="alert">
                Danger alert!  
                {error}
            </div>
        }
        {
           
            portfolios && 
            portfolios.map((saved, index) => (
                saved.status == "saved" &&
                <div key={saved.id} className="box-border rounded-md m-2 mx-3 border-1 border-gray-100 bg-white shadow-md ">
                    <div className="grid grid-flow-col p-2 place-content-between text-gray-700">
                        
                        <div className=" ">
                            <div className="flex gap-4 ">
                                <img className='h-4 w-4 mt-[2px]' src={PortfolioIcon}/>
                                <span className='font-bold text-gray-700 text-center'>Saved Portfolio{count++}</span>
                            </div>
                            <div className='text-xs my-3'>
                                        
                                {instrumentname[saved.instrument1]}({saved.booster1}),  {instrumentname[saved.instrument2]}({saved.booster2}),
                                <br/>
                                {instrumentname[saved.instrument3]}({saved.booster3}),  {instrumentname[saved.instrument4]}({saved.booster4})
                            
                            </div>
                            
                        </div>
                        {
                            contestStatus == "live" ?
                            <div className=' bg-white text-center my-5 h-7 w-16 border border-[#C8C6CA] rounded-sm' onClick={() => handleJoin(saved, index)}>
                                <span className='inline-block align-middle text-xs font-semibold text-[#E4E1E6]' onClick={() => handleJoin(saved, index)}>
                                    Join
                                </span>
                            </div>
                            :
                            <div className='cursor-pointer bg-white text-center my-5 h-7 w-16 border border-primary-color rounded-sm' onClick={() => handleJoin(saved, index)}>
                                <span className='inline-block align-middle text-xs font-semibold text-primary-color' onClick={() => handleJoin(saved, index)}>
                                    Join
                                </span>
                            </div>
                        }


                    </div>

                    <div className='grid grid-flow-col gap-[2px]'>
                        <div  onClick={() => handleEdit(saved)} className='cursor-pointer h-6 grid grid-flow-col place-content-center place-items-center gap-2 bg-[#f4f5f4]'>
                            
                            <img  className='h-2 w-2' src={editIcon} alt="" />
                            <div className='text-[11px] text-light-text '>Edit</div>
                        </div>
                        <div onClick={() => handleDelete(saved.id)} className='cursor-pointer h-6 grid grid-flow-col place-items-center place-content-center gap-2 bg-[#f4f5f4]'>
                            <div >
                                <img className='h-2 w-2' src={deleteIcon} alt="" />
                            </div>
                            <div className='text-[11px] text-light-text ' >Delete</div>
                        </div>
                    </div>
                </div>
            ))
        }
        
    </div>
  )
}

export default SavedPortfolio