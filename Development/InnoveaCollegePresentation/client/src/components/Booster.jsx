import React from "react";
import { useDispatch } from "react-redux";
import { instrumentname } from "../assets/Instruments";
import { EditInstrument } from '../features/portfolioSlice';


const Booster = ({instrument, booster1, booster2}) => {
  const dispatch = useDispatch();

  const handleClick = (e) => {
    e.preventDefault();
    dispatch(EditInstrument({booster: e.target.id*(instrument.booster > 0 ? 1 : -1), name: instrument.name}));    
  }


  return (
    <div>
      <div className="flex items-center m-[0.0rem] bg-background ">
        <div className="font-bold text-gray-700 flex-auto mx-6">
          {instrumentname[instrument.name]}
          <div className="text-xs">
            {
              instrument.booster > '0' ? "Long" : "Short"
            }
          </div>
        </div>
        <div className="m-4 flex space-x-3">
         
          <div name='2'>
            {
              (instrument.booster == 2 || instrument.booster == -2) ?
                <button className="outline outline-2 bg-dark-background text-primary-color outline-dark-background rounded-full h-9 w-9">
                  <p id= '2' className="text-sm font-bold ">2x</p>
                </button> 
              :
                <button name='2' id='2' onClick={handleClick} className="outline outline-1 outline-dark-text text-dark-text rounded-full h-9 w-9">
                    <p id= '2' className="text-sm font-bold ">2x</p>
                </button>   
               
            }
          </div>

          <div name='1.5'>
            {
              (instrument.booster == 1.5 || instrument.booster == -1.5) ? 
                <button className="outline outline-2 bg-dark-background text-primary-color outline-dark-background h-9 w-9 rounded-full">
                  <p id='1.5' className="text-sm font-bold">1.5x</p>
                </button>
              
              :
                <button name={1.5} id={1.5} onClick={handleClick} className="outline outline-1 outline-dark-text text-dark-text h-9 w-9 rounded-full">
                  <p name={1.5} id='1.5' className="text-sm font-bold">1.5x</p>
                </button>
            }
          </div>
         
       </div>
       </div>
     </div>
  );
};

export default Booster;
