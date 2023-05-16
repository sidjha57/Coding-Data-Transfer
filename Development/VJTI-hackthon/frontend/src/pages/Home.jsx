import React from 'react'
import Cart from '../components/Cart'
import Slider from '../components/Slider'

const Home = () => {
  return (
    
    <div className=''>
      <Slider />
      <div className="component">
          <div className="name text-3xl font-bold mx-24">
            Notable Collections
          </div>
          <div className='flex mx-20'>
            <Cart />
            <Cart />
            <Cart />
            <Cart />
            <Cart />
            <Cart />
          </div>
      </div>
      <div className="component">
          <div className="name text-3xl font-bold mx-24">
            Notable Collections
          </div>
          <div className='flex mx-20'>
            <Cart />
            <Cart />
            <Cart />
            <Cart />
            <Cart />
            <Cart />
          </div>
      </div>
      <div className="component">
          <div className="name text-3xl font-bold mx-24">
            Notable Collections
          </div>
          <div className='flex mx-20'>
            <Cart />
            <Cart />
            <Cart />
            <Cart />
            <Cart />
            <Cart />
          </div>
      </div>
    </div>
  )
}

export default Home