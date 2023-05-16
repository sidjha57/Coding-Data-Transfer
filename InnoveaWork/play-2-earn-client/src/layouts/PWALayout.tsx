import React from 'react'
import { Navigate, Outlet } from 'react-router-dom';
import { useAuth } from '../context/AuthContext';
import LandingPage from '../pages/LandingPage/LandingPage';

const PWALayout = () => {
  const {isInstalled} = useAuth();

  function showInstallPromotion() {
    // Check if PWA is installed
    if (window.matchMedia('(display-mode: standalone)').matches) {
      console.log('PWA is installed');
      return <Outlet />
    } else {
      console.log('PWA is not installed');
      return <LandingPage />
    }
  }
 
  return (
     isInstalled ?
      <Outlet />
     :
      <LandingPage />
  )
}

export default PWALayout