import React, { useCallback, useEffect, useRef, useState } from 'react'
import { verifyUserApi } from '../api/Verify';
import CommonFooter from '../components/CommonFooter';
import CommonHeader from '../components/CommonHeader';
import { SetUser } from '../features/authenticateSlice';
import { useDispatch, useSelector } from 'react-redux'
import { useNavigate } from 'react-router-dom';
import {  SetFooterStatus, SetHeaderStatus } from '../features/selectedSlice';
import { addDataIntoCache, getDataFromCache } from '../js/caching';


const Verification = () => {
    const phoneNum = useRef("");
    const dispatch = useDispatch();
    const [error, setError] = useState(null);
    const [buttonColor, setButtonColor] = useState("#e5e0e6");
    const navigate = useNavigate();

    const handleChange = (e) => {
        e.preventDefault();
        if (e.target.value.length == 10) {
            setButtonColor("#133d9f");
        } else {
            setButtonColor("#e5e0e6");
        }
    }

    // useEffect(() => {},[buttonColor])


    const handleSubmit = useCallback(
    () => async (e) => {
      e.preventDefault();
      if (phoneNum.current.value.length < 10) {
        setError("Please provide a valid 10 digit phone number");
        return;
      };
      try {
          const res = await verifyUserApi(phoneNum.current.value);
          console.log(res);
          if (res.data.status == 200) {
              dispatch(SetUser(res.data.data));
              addDataIntoCache("user", "http://localhost:5173", res.data.data);
              addDataIntoCache("instruments", "http://localhost:5173", []);
              addDataIntoCache("portfolioStatus", "http://localhost:5173", "joined");
              dispatch(SetFooterStatus("home"));
              dispatch(SetHeaderStatus("daily"));
              addDataIntoCache("footerStatus", "http://localhost:5173", "home");
              navigate("/home");
          }
          else {
            setError(res.data.message);
            console.log(res.data);
          }
        } catch (err) {
            console.log(err);
        }
    },
    []
  );

  return (
    <>
        <CommonHeader header = {`Login with phone`}/>
            <form className="Main mb-auto" onSubmit={handleSubmit()}>
                <div className='flex flex-col w-screen mx-4 space-y-3  my-[15vh]'>
                    <div className='text-dark-text text-xs font-semibold '>
                        Please enter your mobile number to get OTP and login 
                    </div>

                    <div className='outline hover:outline-blue-500 bg-white w-[90vw] outline-1 text-sm font-bold outline-gray-400 rounded-sm'>
                        <div className="py-3">

                            <span className='mx-4 my-3'>+91</span>
                            <input onChange={handleChange} ref={phoneNum} className='peer outline-none  w-[70vw]' type="tel" required maxLength="10" name="phonenum" id="phonenum" placeholder='10-digit mobile number'/>
                        </div>
                    </div>
                    {
                        error && 
                        <div className="text-sm text-red-800 rounded-lg bg-red-50 dark:text-red-400" role="alert">
                            <span className="font-medium">Danger alert! </span> 
                            {error}
                        </div>
                    }
                </div>
            <CommonFooter message={`I agree to the T&C and Privacy Policy`} button={`Verify`} buttonColor={buttonColor}/>
            </form>
            {/* <iframe className='h-[100vh] w-[100vw]' src="https://subscriptions1938.editorx.io/marketplaylearn"></iframe> */}
    </>
  )
}

export default Verification;