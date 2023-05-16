import React, { useEffect } from "react";
import WalletIcon from "/WalletIcon.png";
import UserIcon from "/UserIcon.png";
import { useLocation, useNavigate } from "react-router-dom";
import { useDispatch, useSelector } from "react-redux";
import { SetHeaderStatus, SetPortfolioStatus } from "../features/selectedSlice";

const Header = () => {
  const Location = useLocation();
  const navigate = useNavigate();
  const headerStatus = useSelector((state) => state.selected.headerStatus);
  const portfolioStatus = useSelector((state) => state.selected.portfolioStatus);
  const dispatch = useDispatch();

  const handlePortfolioClick = (e) => {
    e.preventDefault();
    console.log(e.target.id);
    dispatch(SetPortfolioStatus(e.target.id));
  }

  const handleHeaderClick = (e) => {
    e.preventDefault();
    dispatch(SetHeaderStatus(e.target.id));
    if (e.target.id == "daily") navigate("/index")
    else navigate("/coming")
  }

  return (
    <header className="Header fixed bg-white w-screen">

      <div className="flex flex-row justify-evenly mx-5 my-2 py-3">

        <div className="grow">
          <div className="font-extrabold font-satoshi text-2xl text-[#002485]">
            MarketPlay
          </div>
        </div>
        <div className="flex space-x-[17px]">
          <img className="h-[18px] w-[17px]" src={WalletIcon} alt="" />
          <img className="h-[19px] w-[19px]" src={UserIcon} alt="" />
        </div>
      </div>

      <div className="flex flex-row pt-1 justify-evenly">
        <div name="intraday" id="intraday" onClick={handleHeaderClick} className="text-sm text-center text-gray-600 focus:text-primary-color  focus:underline focus:decoration-4 focus:underline-offset-8 focus:decoration-primary-color">
          {
            headerStatus == "intraday" &&
            <div name="intraday" id="intraday" className=" text-[#08309E]">
              <div className="my-1 cursor-pointer" id="intraday">
                Intraday
              </div>
              <div className="h-[3px] w-[60px] rounded-tl-full rounded-tr-full bg-[#08309E]"></div>
            </div>
          }
          {
            headerStatus != "intraday" &&
            <div name="intraday" id="intraday" className=" ">
              <div className="my-1 cursor-pointer" id="intraday">
                Intraday
              </div>
            </div>
          }
        </div>
        <div name="daily" id="daily" onClick={handleHeaderClick} className="text-sm text-center text-gray-600 focus:text-primary-color  focus:underline focus:decoration-4 focus:underline-offset-8 focus:decoration-primary-color">
          {
            headerStatus == "daily" &&
            <div name="daily" id="daily" className="  text-[#08309E]">
              <div className="my-1 cursor-pointer" id="daily">
                Daily
              </div>
              <div name="daily" id="daily" className="h-[3px] w-[60px] rounded-tl-full rounded-tr-full bg-[#08309E]"></div>
            </div>
          }
          {
            headerStatus != "daily" &&
            <div name="daily" id="daily" className="">
              <div className="my-1 cursor-pointer" id="daily">
                Daily
              </div>
            </div>
          }
        </div>
      </div>
      <hr></hr>

      {Location.pathname == "/index" && (
        <div className="flex  flex-row bg-white mx-4 space-x-4">
          <div name="joined" onClick={handlePortfolioClick}>

            {
              portfolioStatus == "joined" &&
              <div name="joined" className="my-2">
                <div name="joined" id="joined" className="cursor-pointer px-3 py-[2px] text-[0.75rem] text-[#303034]  font-medium font-  outline outline-1   rounded-sm  outline-primary-color  bg-dark-background text-primary-color">
                  Joined
                </div>
              </div>
            }
            {
              portfolioStatus != "joined" &&
              <div name="joined" id="joined" className="my-2 ">
                <div name="joined" id="joined" className="cursor-pointer px-3 py-[2px] text-[0.75rem] text-[#303034] font-medium  outline outline-1   rounded-sm outline-gray-200">
                  Joined
                </div>
              </div>
            }
          </div>
          <div name="completed" onClick={handlePortfolioClick}>

            {
              portfolioStatus == "completed" &&
              <div name="completed" id="completed" className="my-2 ">
                <div name="completed" id="completed" className="cursor-pointer px-3 py-[2px] text-[0.75rem] text-[#303034] font-medium  outline outline-1   rounded-sm  outline-primary-color  bg-dark-background text-primary-color">
                  Completed
                </div>
              </div>
            }
            {
              portfolioStatus != "completed" &&
              <div name="completed" id="completed" className="my-2 ">
                <div name="completed" id="completed" className="cursor-pointer px-3 py-[2px] text-[0.75rem] text-[#303034] font-medium  outline outline-1   rounded-sm outline-gray-200">
                  Completed
                </div>
              </div>
            }
          </div>

        </div>
      )}
      <hr></hr>

    </header>
  );
};

export default Header;
