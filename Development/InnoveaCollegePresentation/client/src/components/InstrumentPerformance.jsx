import React, { useRef} from 'react'

const InstrumentPerformance = ({instrument, type}) => {
  console.log(instrument);
  console.log(type);
  const point = useRef(0);
   
  if (type) {
    point.current = instrument.perchange * 100 * instrument.booster;
  }

  return (
    <div>
         <div className='grid grid-flow-col place-content-between '>
              <div className='mx-4 my-2 text-left'>
                  <div className='text-dark-text font-bold'>{instrument.name}</div>
                  {
                    type == 1 &&
                    <div className='text-xs text-dark-text'>{instrument.booster>0? "Long": "Short"} {Math.abs(instrument.booster) > 1 ? `| ${Math.abs(instrument.booster)}x` : ``}</div>
                  }
              </div>
              <div className='mx-4 my-2 text-right'>
                  <div className='text-dark-text font-bold'>{instrument.perchange}%</div>
                  {
                    type == 1 && 

                    <div className="">
                      {
                        point.current > 0 ?
                        <div className='text-xs text-green-400 text-right'>+{point.current} pt</div>  
                          :      
                        <div className='text-xs text-red-400 text-right'>{point.current} pt</div>  
                      }
                    </div>
    
                  }
              </div>
            </div>

            <div className='h-[1px] mx-4 bg-[#eaebeb]'/>
    </div>
  )
}

export default InstrumentPerformance