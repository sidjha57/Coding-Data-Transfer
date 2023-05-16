import React from 'react'

const Cart = ({image}) => {
  return (
    <div className='bg-gray-50 h-96 w-64 m-4 rounded-2xl shadow-lg'>
        <div className='image h-40 w-50'>
            <img className='rounded-t-2xl ' src={image} alt="" />
        </div>
        <div className='my-24'>
            <div className='p-1 flex'>
                <div className='font-bold m-3 mx-5'>Ghost Boy</div>
                <div className='h-5 w-5 my-3 -mx-3'>
                    <img src="blueTick.jpg" alt="" />
                </div>
            </div>
            <div className='info flex justify-around'>
                <div>
                    <div className='text-gray-500 text-xs'>FLOOR</div>
                    <div className='font-bold'>0.15 ETH</div>
                </div>
                <div>
                    <div className='text-gray-500 text-xs'>Added</div>
                    <div className='font-bold text-'>24 Mar 2022</div>
                </div>
            </div>
        </div>
    </div>
  )
}

export default Cart