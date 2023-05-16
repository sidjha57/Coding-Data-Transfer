import moment from "moment";
import React, { useEffect, useState } from "react";
import { useSelector } from "react-redux";
import { useNavigate } from "react-router-dom";
import { getUserPortfoliosByStatus } from "../api/Portfolio";
import PortfolioIcon from '/PortfolioIcon.png';
import { getRanks, updatePoints } from "../api/Ranks";
import { instrumentname } from "../assets/Instruments";

const LivePortfolio = ({ status, entries }) => {
  const user = useSelector((state) => state.authenticate.user);
  const [portfolios, setPortfolios] = useState(null);
  let count = 1;

    async function fetch() {
      console.log("Daily Index", moment().format('HH:mm:ss'));   
      await getRanks()
      .then((res) => {
        setPortfolios(res.data.data);
        console.log(res.data.data);
      })
      .catch((err) => {
      console.log(err);
      });
    }

  

    useEffect(() => {
      fetch();
      if (status == "live") {
        setInterval(fetch, 2000);
        return () => clearInterval(fetch)
      }
    }, [])

   const navigate = useNavigate();
   const handleClick = (portfolio, rank, entries, index) => {
    navigate(`/results`, {state:{portfolio:portfolio, rank:rank, entries:entries, index:index}})
   }
   



  console.log(status);

  return (
    <div className="z-0">
      {portfolios &&
        portfolios.map(
          (portfolio, index) =>
            portfolio.status == status && portfolio.user.id == user.id && (
              <div
                onClick={() => {handleClick(portfolio, index+1, portfolios.length)}}
                key={portfolio.id}
                className="box-border rounded-md h-24 w-100 my-2 mx-2 p-2 border-4 border-gray-50 bg-white shadow-md"
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
                        {status == "live" ? `${index+1}/${portfolios.length}` : "-"} Rank
                    </div>
                  </div>
                </div>
              </div>
            )
        )}
    </div>
  );
};

export default LivePortfolio;
