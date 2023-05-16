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
            <Cart image={"1.avif"}/>
            <Cart image={"2.avif"}/>
            <Cart image={"3.avif"}/>
            <Cart image={"4.avif"}/>
            <Cart image={"5.avif"}/>
            <Cart image={"6.avif"}/>
          </div>
      </div>
      <div className="component">
          <div className="name text-3xl font-bold mx-24">
            Trending in Art
          </div>
          <div className='flex mx-20'>
            <Cart image={"7.avif"}/>
            <Cart image={"8.avif"}/>
            <Cart image={"9.avif"}/>
            <Cart image={"10.avif"}/>
            <Cart image={"11.avif"}/>
            <Cart image={"12.avif"}/>
          </div>
      </div>
      <div className="component">
          <div className="name text-3xl font-bold mx-24">
            Trending in Gaming
          </div>
          <div className='flex mx-20'>
            <Cart image={"13.avif"}/>
            <Cart image={"14.avif"}/>
            <Cart image={"15.avif"}/>
            <Cart image={"16.avif"}/>
            <Cart image={"17.avif"}/>
            <Cart image={"18.avif"}/>
          </div>
      </div>
    </div>
  )
}

export default Home