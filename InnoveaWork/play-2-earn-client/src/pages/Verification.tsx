import React from "react"
import CommonFooter from "../components/CommonFooter"
import CommonHeader from "../components/CommonHeader"
import { useNavigate } from "react-router-dom"
import { useAuth } from "../context/AuthContext"

const Verification = () => {
  const { error: loginError, user, verifyPhoneNumber, isLoading } = useAuth()

  const [phoneNumber, setPhoneNumber] = React.useState("")
  const [error, setError] = React.useState("")
  const [buttonColor, setButtonColor] = React.useState("#e5e0e6")
  const navigate = useNavigate()

  const handleChange = (e: any) => {
    e.preventDefault()
    setPhoneNumber(e.target.value);
    // console.log(phoneNumber);
    if (e.target.value.length === 10) {
      setButtonColor("#133d9f")
    } else {
      setButtonColor("#e5e0e6")
    }
  }

  React.useEffect(() => {
    if (loginError) setError(loginError)
    if (user) navigate({
      pathname:"/index",
      search: '?contestType=daily&catalogType=index&portfolioStatus=joined'
    })
  }, [loginError, user, navigate, isLoading])

  const handleClick = (e : any) => {
    e.preventDefault()
    console.log(phoneNumber);
    console.log("Verified");
    verifyPhoneNumber(phoneNumber)
  }

  return (
    <>
      <CommonHeader header={`Login with phone`} />
      <form className="Main ">
        <div className="flex flex-col mx-4 space-y-3  my-[15vh]">
          <div className="text-dark-text text-xs font-semibold ">
            Please enter your mobile number to get OTP and login
          </div>

          <div className="outline hover:outline-blue-500 bg-white w-[90vw] outline-1 text-sm font-bold outline-gray-400 rounded-sm">
            <div className="py-3">
              <span className="mx-4 my-3">+91</span>
              <input
                onChange={handleChange}
                className="peer outline-none  w-[70vw]"
                type="tel"
                required
                maxLength={10}
                name="phonenum"
                id="phonenum"
                placeholder="10-digit mobile number"
              />
            </div>
          </div>
          {error && (
            <div
              className="text-sm text-red-800 rounded-lg bg-red-50 dark:text-red-400"
              role="alert"
            >
              <span className="font-medium">Danger alert! </span>
              {error}
            </div>
          )}
        </div>
        <CommonFooter
            message={`I agree to the T&C and Privacy Policy`}
            button={`Verify`}
            isDisabled = {phoneNumber.length < 10}
            onButtonClick = {handleClick}
            buttonColor = {buttonColor}
          />
      </form>
    </>
  )
}

export default Verification
