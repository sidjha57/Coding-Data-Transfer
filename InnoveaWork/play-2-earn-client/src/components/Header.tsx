import React from "react"
import WalletIcon from "../assets/Images/WalletIcon.svg"
import UserIcon from "../assets/Images/UserIcon.svg"
import { useNavigate } from "react-router-dom"

const Header = () => {

  const navigate = useNavigate();

  const handleClick = (e : any) => {
    navigate(e.target.id);
  }

  return (
    <header className="Header z-10 fixed w-screen bg-white h-16 ">
     <div className="grid grid-flow-col grid-cols-8 mx-4 h-16 place-content-center">
          <div className="font-black font-satoshi text-xl text-[#002485]">
            MarketPlay
          </div>

          
          <img onClick={handleClick} id="/wallet" className="h-6 w-6 col-end-9" src={WalletIcon} alt="" />
          <img onClick={handleClick} id="/account" className="h-6 w-6 col-end-10" src={UserIcon} alt="" />
      </div>
    </header>
  )
}

export default Header
