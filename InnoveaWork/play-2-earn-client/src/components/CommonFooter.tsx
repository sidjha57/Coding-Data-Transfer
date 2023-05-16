import React from "react"

interface CommonFooterProps {
  message?: string
  button?: string
  buttonColor?: string
  onButtonClick?: (e: any) => void
  isDisabled?: boolean
}

const CommonFooter = ({
  message,
  button,
  buttonColor,
  onButtonClick,
  isDisabled,
}: CommonFooterProps) => {
 
  return (
    <footer className="Footer h-[76px] fixed bottom-0">     
        <div className="bg-white border-t  fixed bottom-0 width w-full px-3 py-4">
        {/* <div className="py-3">
              <input type="checkbox"  id="terms" className='w-4 h-4 ml-3 checked:bg-[#08309E]'/>
              <label htmlFor="terms" className='text-xs font-medium'> I agree to the <a href={"/"} className="underline text-[#08309E]">T&C</a> and <a href={"/"} className="underline text-[#08309E]">Privacy Policy</a></label>
            </div> */}
          <button
            disabled={isDisabled}
            onClick={(e) => (onButtonClick ? onButtonClick(e) : "")}
            className={`flex justify-center border bg-primary-color h-[44px] text-white font-bold py-2 w-full rounded-md ${
            isDisabled ? "cursor-not-allowed bg-[e5e0e6]" : ""
           }`}
           style={{ backgroundColor: buttonColor }}
           >
            {button}
           </button>
        </div>
    </footer>
  )
}

export default CommonFooter
