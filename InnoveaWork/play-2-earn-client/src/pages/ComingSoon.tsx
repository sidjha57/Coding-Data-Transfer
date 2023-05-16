import React from 'react'
import { Navigate } from 'react-router-dom'
import Footer from '../components/Footer'
import Header from '../components/Header'
import { useAuth } from '../context/AuthContext'


const ComingSoon = () => {
  const {isInstalled} = useAuth()

  if (!isInstalled) {
    <Navigate to={"/"} />
  }

  return (
    <>
        <Header />
            <div className='grid align-middle  font-bold text-3xl text-light-text py-40 place-content-center'>
                Coming Soon ....
            </div>
        <Footer />
    </>
  )
}

export default ComingSoon