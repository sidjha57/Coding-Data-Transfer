import React from "react";
import CommonHeader from "../components/CommonHeader";
import EditIcon from "../assets/Images/EditIcon.svg"
import HistoryIcon from "../assets/Images/History.svg";
import LockIcon from "../assets/Images/Lock.svg";
import QuestionMarkIcon from "../assets/Images/QuestionMark.svg";
import MessageIcon from "../assets/Images/Message.svg";
import { useAuth } from "../context/AuthContext";

const Account = () => {
  const {user, logout} = useAuth();
  console.log(user)

  return (
<div>
    <CommonHeader header="My Account" navigateBack="/" />
    <div className="px-2 opacity-40">
      <div className="flex flex-row justify-between px-5 items-center mt-8">
        <div className="flex flex-row items-center">
        <div className="bg-[#6F89F8]  h-14 w-14 mr-3 text-2xl text-white rounded-full flex items-center justify-center">
            {user.firstName[0]}{user.lastName[0]}
        </div>
        <div>
          <div className="font-medium mb-1 ">
            {user.firstName} {user.lastName}
          </div>
          <div className="text-sm">{user.emailId}</div>
          <div className="text-sm">{user.phoneNumber}</div>
        </div>
        </div>
        <div><img alt="" src={EditIcon} className="h-6 w-6"/></div>
      </div>
      <div className="py-5 px-5 mt-4 font-semibold flex flex-row justify-between">
          <div className="flex flex-row"><img alt="" className="mr-2" src={HistoryIcon} />My Transactions</div>
          <div className="text-[#C8C6CA]">{">"}</div>
        </div>

        <div className="py-5 px-5 mt-4 font-semibold flex flex-row justify-between">
          <div className="flex flex-row"><img alt="" className="mr-2" src={LockIcon} />Privacy Policy</div>
          <div className="text-[#C8C6CA]">{">"}</div>
        </div>

        <div className="py-5 px-5 mt-4 font-semibold flex flex-row justify-between">
          <div className="flex flex-row"><img alt="" className="mr-2" src={QuestionMarkIcon} />FAQ's</div>
          <div className="text-[#C8C6CA]">{">"}</div>
        </div>

        <div className="py-5 px-5 mt-4 font-semibold flex flex-row justify-between">
          <div className="flex flex-row"><img alt="" className="mr-2" src={MessageIcon} />Contact Us</div>
          <div className="text-[#C8C6CA]">{">"}</div>
        </div>
    </div>
    <div className="bg-white fixed bottom-0 width w-full px-3  py-4">
      <button className="flex justify-center border border-[#546FDC] text-sm text-[#08309E] font-bold h-11 py-2 w-full rounded-sm" onClick={() => logout()}>Logout</button>
    </div>
  </div>
  )
};

export default Account;