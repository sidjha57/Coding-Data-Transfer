import moment from "moment";
import React, { useEffect, useRef, useState } from "react";
import { useLocation } from "react-router-dom";
import { getRanks, getTotalEntries, updatePoints } from "../api/Ranks";
import CommonHeader from "../components/CommonHeader";
import Score from "../components/Score";

const Leaderboard = ({contestStatus}) => {
  const [ranks, setRanks] = useState();
  let firstTime = 1;
  const location = useLocation().state;
  const status = location.status;
  const rank = location.rank;
  const entries = location.entries;
  
  
  async function fetch () {
    try {   
      console.log("LeaderBoard", moment().format('HH:mm:ss'));   
      await getRanks()
      .then((res) => {
        if (res.data) {
          setRanks(res.data.data);
        }
        console.log(res.data);
      })
      .catch((err) => {
        console.log(err);
      })
    } catch (err) {
      console.log(err);
    }
  }


  useEffect(() => {
    fetch();
    if (contestStatus == "live") {
      setInterval(fetch, 2000);
      return () => clearInterval(fetch)
    }
  }, [])

  console.log(ranks);
  return (
    <div>
      <CommonHeader header={`Leaderboard`} navigateBack={"/results"}/>
      <div className="h-fit w-screen bg-white fixed">
          <div className="pt-1">

            <div className=" h-14 outline outline-1 outline-[#d6d5d6] m-4 justify-between flex bg-white rounded-md items-center">
              <div className="mx-4">
                <div className="text-dark-text font-bold">Rank</div>
                <div className="text-xs text-dark-text">
                  Top 10% out of {entries} entries
                </div>
              </div>
              <div className="mx-4">
                <p className="text-dark-text font-bold mx-2 text-xl">{rank}</p>
              </div>
            </div>
          </div>
      
        {/* <div className="flex mx-4 pb-2 space-x-4">
          <div>
            <input
              type="radio"
              name="option"
              id="1"
              className="peer hidden"
            />
            <label
              htmlFor="1"
              className="block text-[0.65rem] w-12 font-md outline outline-[1px] outline-[#eaebeb] text-dark-text cursor-pointer select-none rounded-md p-1 text-center peer-checked:bg-[#dce1fe] peer-checked:outline-primary-color peer-checked:text-primary-color"
            >
              0-10%
            </label>
          </div>

          <div>
            <input type="radio" name="option" id="2" className="peer hidden" />
            <label
              htmlFor="2"
              className="block text-[0.65rem] w-12 font-md outline outline-[1px] outline-[#eaebeb] text-dark-text cursor-pointer select-none rounded-md p-1 text-center peer-checked:bg-[#dce1fe] peer-checked:outline-primary-color peer-checked:text-primary-color"
            >
              10-20%
            </label>
          </div>

          <div>
            <input type="radio" name="option" id="3" className="peer hidden" />
            <label
              htmlFor="3"
              className="block text-[0.65rem] w-12 font-md outline outline-[1px] outline-[#eaebeb] text-dark-text cursor-pointer select-none rounded-md p-1 text-center peer-checked:bg-[#dce1fe] peer-checked:outline-primary-color peer-checked:text-primary-color"
            >
              20-30%
            </label>
          </div>
        </div> */}
        <div className='h-[1px]  bg-[#d6d5d6]'/>
      </div>
      <div className="pt-[11vh]">
        {
          ranks
          ? ranks.map((portfolio, index) => (
            <div key={portfolio.id}> 
              <Score portfolio={portfolio} entries={ranks.length} rank={index+1}/>
            </div>
          ))
          :
          <div class="text-center my-10">
              <div role="status">
                  <svg aria-hidden="true" class="inline w-8 h-8 mr-2 text-gray-200 animate-spin dark:text-gray-600 fill-blue-600" viewBox="0 0 100 101" fill="none" xmlns="http://www.w3.org/2000/svg">
                      <path d="M100 50.5908C100 78.2051 77.6142 100.591 50 100.591C22.3858 100.591 0 78.2051 0 50.5908C0 22.9766 22.3858 0.59082 50 0.59082C77.6142 0.59082 100 22.9766 100 50.5908ZM9.08144 50.5908C9.08144 73.1895 27.4013 91.5094 50 91.5094C72.5987 91.5094 90.9186 73.1895 90.9186 50.5908C90.9186 27.9921 72.5987 9.67226 50 9.67226C27.4013 9.67226 9.08144 27.9921 9.08144 50.5908Z" fill="currentColor"/>
                      <path d="M93.9676 39.0409C96.393 38.4038 97.8624 35.9116 97.0079 33.5539C95.2932 28.8227 92.871 24.3692 89.8167 20.348C85.8452 15.1192 80.8826 10.7238 75.2124 7.41289C69.5422 4.10194 63.2754 1.94025 56.7698 1.05124C51.7666 0.367541 46.6976 0.446843 41.7345 1.27873C39.2613 1.69328 37.813 4.19778 38.4501 6.62326C39.0873 9.04874 41.5694 10.4717 44.0505 10.1071C47.8511 9.54855 51.7191 9.52689 55.5402 10.0491C60.8642 10.7766 65.9928 12.5457 70.6331 15.2552C75.2735 17.9648 79.3347 21.5619 82.5849 25.841C84.9175 28.9121 86.7997 32.2913 88.1811 35.8758C89.083 38.2158 91.5421 39.6781 93.9676 39.0409Z" fill="currentFill"/>
                  </svg>
                  <span class="sr-only">Loading...</span>
              </div>
          </div>
        }
      </div>
    </div>
  );
};

export default Leaderboard;
