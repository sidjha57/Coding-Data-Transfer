import moment from "moment";
import React, { useEffect, useState } from "react";
import { useDispatch, useSelector } from "react-redux";
import { useNavigate } from "react-router-dom";
import { createUsers } from "../api/Users";
import { userlist } from "../assets/Users";
import { SetHeaderStatus, SetFooterStatus, SetPortfolioStatus } from "../features/selectedSlice";

import Briefcase from "/briefcase.svg";
import Pointer from "/point.svg";
import Trophy from "/trophy.svg";
import Modal from "../components/Modal";
import { getUserPortfolios } from "../api/Portfolio";
import { SetPortfolio } from "../features/portfolioSlice";

const Home = () => {
  const navigate = useNavigate();
  const dispatch = useDispatch();
  const user = useSelector((state) => state.authenticate.user);

  const startTime = moment("9:15:59 am", "HH:mm:ss a");
  const endTime = moment("03:15:59 pm", "HH:mm:ss a");

  const [modalOpen, setModalOpen] = useState(true);

  // calculate total duration
  var duration = moment.duration(endTime.diff(startTime));

  // duration in hours
  var hours = parseInt(duration.asHours());

  // duration in minutes
  var minutes = parseInt(duration.asMinutes()) % 60;

  
  const handleClick = async () => {
    setModalOpen(false);
    dispatch(SetHeaderStatus("daily"));
    dispatch(SetFooterStatus("index"));
    dispatch(SetPortfolioStatus("joined"));
  
    await getUserPortfolios(user.id).then((res) => {
        console.log(res.data.data)
        dispatch(SetPortfolio(res.data.data))
    }).catch ((err) => {console.log(err)})
    navigate("/index");
  };

  const modalContent = (
    <div className="py-10 mx-5 rounded-xl bg-gradient-to-br from-[#294AA4] to-[#030A1C]">
      <div
        onClick={handleClick}
        className="mr-7 mt-[-20px] cursor-pointer text-xl text-white flex justify-end"
      >✕</div>

      <div className="flex space-x-3">
        <div></div>
        <div>
          <div className="h-10 w-10 bg-[#ECF1FF1A] bg-opacity-10 text-white rounded-full text-center my-2">
            <img src={Briefcase} />
          </div>
          <div className="w-[0.1rem] ml-5 my-2 h-16 bg-[#d3d3d4]"></div>
        </div>

        <div className="space-y-4">
          <div className=" text-xl mt-4 text-white">Setup Portfolio</div>
          <div className="text-[#C8C6CA] font-medium text-sm mr-10">
            Select from market instrument to go Long or Short & assign boosters.
          </div>
          {/* <div onClick={handleClick} className='cursor-pointer h-7 w-20 text-white bg-primary-color rounded-md text-center'>
               Continue
           </div> */}
        </div>
      </div>
      <div className="flex space-x-3">
        <div></div>
        <div>
          <div className="h-10 w-10 bg-[#ECF1FF1A] bg-opacity-10 text-white rounded-full text-center my-2 p-1">
            <img height={35} width={35} src={Pointer} />
          </div>
          <div className="w-[0.1rem] ml-5 my-2 h-16 bg-[#d3d3d4]"></div>
        </div>

        <div className="space-y-4">
          <div className=" text-xl mt-4 text-white">Join Contest</div>
          <div className="text-[#C8C6CA] font-medium text-sm mr-10">
            Choose joining mode, Pay and Enter. You can join as spectator too.
          </div>
          {/* <div className='text-[#C8C6CA] font-medium text-xs'>
               Closes in <span className='f text-xl mt-1 text-white'>11h : 29 min</span>
           </div> */}
        </div>
      </div>
      <div className="flex space-x-3">
        <div></div>
        <div>
          <div className="h-10 w-10 bg-[#ECF1FF1A] bg-opacity-10 text-white rounded-full text-center my-2">
            <img src={Trophy} />
          </div>
          {/* <div className='w-[0.1rem] mx-5 my-2 h-28 bg-[#d3d3d4]'></div> */}
        </div>

        <div className="space-y-4">
          <div className=" text-xl mt-4 text-white">Your Results</div>
          <div className="text-[#C8C6CA] font-medium text-sm mr-10">
            Check your gains, rank and performance.
          </div>
        </div>
      </div>
    </div>
  );

  //    Used for adding users
  //    useEffect(() => {
  //     userlist.map(async (user) => {
  //         await createUsers(user);
  //     })
  //    }, [])

  return (
    <>
      {modalOpen && (
        <Modal
          children={modalContent}
          onClose={() => {
            setModalOpen(false);
          }}
        />
      )}
    </>
  );
};

export default Home;
