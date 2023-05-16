import React from "react";
import CommonHeader from "../components/CommonHeader";
import WalletIcon from "../assets/Images/WalletIcon.svg";
import HistoryIcon from "../assets/Images/History.svg";

const Wallet = () => {
  return (
    <div>
      <CommonHeader header="Wallet" navigateBack="/" />
      <div className="px-3">
        <div className="flex flex-row mt-6">
          <img alt="" className="h-6 w-6 p-1" src={WalletIcon} />
          <div className="text-sm font-bold contents">Total Balance</div>
        </div>
        <div className="ml-1 text-4xl font-bold mt-1">Rs.5000</div>
        <div className="bg-[#fcfcfc] border border-[#c8c6ca] py-0 px-3 mt-5 rounded-md">
          <div className="py-5 flex flex-row justify-between items-center border-b border-[#C8C6CA]">
            <div>
              <div className="text-xs font-medium mb-1">Added Cash</div>
              <div className="font-bold mt-1">Rs.1000</div>
            </div>
            <div>
              <button
                disabled
                className="bg-[#E4E1E6] px-5 py-1 text-white rounded-sm text-base"
              >
                Add Cash
              </button>
            </div>
          </div>

          <div className="py-5 flex flex-row justify-between items-center border-b border-[#C8C6CA]">
            <div>
              <div className="text-xs font-medium mb-1">Winnings</div>
              <div className="font-bold mt-1">Rs.4000</div>
            </div>
            <div>
              <button
                disabled
                className="bg-white px-5 py-1 text-[#E4E1E6] border border-[#E4E1E6] rounded-sm text-base"
              >
                Withdraw
              </button>
            </div>
          </div>

          <div className="py-5 flex flex-row justify-between items-center">
            <div>
              <div className="text-xs font-medium mb-1">Cash Bonus</div>
              <div className="font-bold mt-1">Rs.0</div>
            </div>
            <div>
              <button
                disabled
                className="bg-white px-5 py-1 text-[#E4E1E6] border border-[#E4E1E6] rounded-sm text-base"
              >
                Play Now
              </button>
            </div>
          </div>
        </div>

        <div className="bg-[#fcfcfc] border border-[#c8c6ca] py-5 px-3 mt-4 rounded-md font-semibold flex flex-row justify-between">
          <div className="flex flex-row"><img alt="" className="mr-2" src={HistoryIcon} />My Transactions</div>
          <div className="text-[#C8C6CA]">{">"}</div>
        </div>
      </div>
    </div>
  );
};

export default Wallet;
