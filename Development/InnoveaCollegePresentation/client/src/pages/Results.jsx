import React from 'react'
import CommonFooter from '../components/CommonFooter'
import CommonHeader from '../components/CommonHeader'
import Result from '../components/Result'
import { Line } from "react-chartjs-2";
import Chart from 'chart.js/auto';
import moment from 'moment';
import LineChart from '../components/LineChart';
import LineD3 from '../components/LineD3';
import Graph from '/graph.jpg';

const Results = ({contestStatus}) => {
    const now = moment().format('HH:mm:ss a');
    const currentTime = moment(now, 'HH:mm:ss ');
    const startTime = moment("09:30:00 ", 'HH:mm:ss ');
    const endTime = moment("15:15:00 ", 'HH:mm:ss ');
    let timeleft = moment.duration(startTime.diff(currentTime));

    if (contestStatus == "live") {
      timeleft = moment.duration(endTime.diff(currentTime));
    }

  return (
    <div>
        <CommonHeader header={`Results`} navigateBack={"/index"}/>
      
        <div className=' mx-4 py-2 text-gray-700'>
                <div className='grid grid-flow-col place-content-between'>
                    <div className='font-bold'>
                        Portfolio
                    </div>
                    <p className='p-2 grid place-content-center capitalize box-border text-center text-xs text-gray-700 rounded-2xl h-5 w-fit border border-gray-400'>
                       {contestStatus}
                    </p>
                </div>

                <div className=" grid grid-flow-col place-content-between">
                    <div className="text-xs font-medium">Daily Contest  {moment().format('D MMM')}</div>
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

        <div className='grid place-content-center my-4'>
            <img src={Graph} width="330" className='' alt=""  />
        </div>
        {/* <LineD3 /> */}
        {/* <LineChart /> */}
        <Result />
    </div>
  )
}

export default Results