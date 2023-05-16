import React, { useEffect, useState } from "react";
import { useSelector } from "react-redux";
import { getUserPortfoliosByStatus } from "../api/Portfolio";
import { getRanks, updatePoints } from "../api/Ranks";
import PortfolioIcon from '/PortfolioIcon.png';
import { instrumentname } from "../assets/Instruments";

const Portfolio = ({ status, entries }) => {
  const user = useSelector((state) => state.authenticate.user);
  const portfolios = useSelector((state) => state.portfolios.portfolios);
  let count = 1;

  // console.log(status);

  return (
    <div className="z-0">
      {portfolios &&
        portfolios.map(
          (portfolio, index) =>
            portfolio.status == status && portfolio.user.id == user.id && (
              <div
                key={portfolio.id}
                className="box-border rounded-md h-24 w-100 m-1 mx-3 p-2 border-4 border-gray-50 bg-white shadow-md"
              >
                <div className="h-full w-full bg-white flex justify-between text-gray-700">
                  <div className=" ">
                        <div className="flex gap-4 ">
                            <img className='h-4 w-4 mt-[2px]' src={PortfolioIcon}/>
                            <span className='font-bold text-gray-700 text-center'>Portfolio{count++}</span>
                        </div>
                        <div className='text-xs my-3'>
                                    
                            {instrumentname[portfolio.instrument1]}({portfolio.booster1}),  {instrumentname[portfolio.instrument2]}({portfolio.booster2}),
                            <br/>
                            {instrumentname[portfolio.instrument3]}({portfolio.booster3}),  {instrumentname[portfolio.instrument4]}({portfolio.booster4})
                        
                        </div>
                    </div>

                  <div className="flex flex-col">
                    <div>
                      <h1 className="font-semibold">
                        { 
                        
                          portfolio.score?.points > 0 ?
                          <span className="text-green-500">
                            {portfolio.score.points}  Pts
                          </span>
                          :
                            portfolio.score?.points < 0 ?
                                <span className="text-red-500">
                                    {portfolio.score.points}  Pts 
                                </span>
                          :
                          "- Pts" 
                        }
                      </h1>
                    </div>
                    <div className="text-right">
                        {status == "live" ? `${index+1}/${entries}` : "-"} Rank
                    </div>
                  </div>
                </div>
              </div>
            )
        )}
    </div>
  );
};

export default Portfolio;
