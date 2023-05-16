

const Modal = ({children, onClose} : any) => {
    return (
        <>
          <div
            className="justify-center items-center flex overflow-x-hidden  fixed inset-0 z-50 outline-none focus:outline-none"
          >
            <div className="relative w-auto my-6 mx-auto max-w-3xl">
              {/*content*/}
                {children}
                
            </div>
          </div>
          <div className="opacity-25 fixed inset-0 z-40 bg-black"></div>
        </>
    )
}

export default Modal;