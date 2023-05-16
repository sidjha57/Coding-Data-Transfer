import React, { createContext, useEffect, useState, useContext } from "react"
import { useNavigate, useSearchParams } from "react-router-dom"
import { verifyUserApi } from "../api/Verify"
import { ContestTypeConfigID } from "../assets/ContestTypeConfig"

interface AuthContextValue {
  isInstalled: boolean
  setIsInstalled : any
  isLoading: boolean
  user: any
  error: string
  verifyPhoneNumber: (phoneNumber: string) => void
  logout: () => void
}

export const AuthContext = createContext<AuthContextValue | undefined>(
  undefined
)

export const useAuth = () => useContext(AuthContext)!

export const AuthProvider = ({ children }: { children: React.ReactNode }) => {
  const [user, setUser] = React.useState(null)
  const [isLoading, setIsLoading] = React.useState(true);
  const [error, setError] = useState<string>("")
  const [isInstalled, setIsInstalled] = useState<boolean>(false)


  const navigate = useNavigate()

  function showInstallPromotion() {
    // Check if PWA is installed
    if (window.matchMedia('(display-mode: standalone)').matches) {
      setIsInstalled(true);
      console.log('PWA is installed');
    } else {
      setIsInstalled(false);
      console.log('PWA is not installed');
    }
  }
  

  const fetch = async () => {
    showInstallPromotion()
    const user_data = await localStorage.getItem("user_data")

    // console.log(user_data);

    setIsLoading(false)
    if (user_data) {
      setUser(JSON.parse(user_data))
    }
  }
  useEffect( () => {
    fetch()
  }, [isLoading])



  const verifyPhoneNumber = async (phoneNumber: string) => {
    try {
      const {
        status,
        data:  userData,
      }: any = await verifyUserApi(phoneNumber)

      if (status === 200) {
        console.log(userData);
        if (!userData.length) {
          setError("Invalid credentials")
          return;
        }
        localStorage.setItem("user_data", JSON.stringify(userData[0]))
        setUser(userData[0])
        navigate("/index")
      } else {
        // setError(message)
      }
    } catch (err: any) {
      console.log(err)
      setError(err.message)
    }
  }

  const logout = () => {
    // Here, you would typically make a request to your backend to log out the user
    localStorage.removeItem("user_data")
    
    setUser(null)
    navigate("/login")
  }

  const authContextValue = {
    isInstalled,
    setIsInstalled,
    isLoading,
    error,
    user,
    verifyPhoneNumber,
    logout
  }

  return (
    <AuthContext.Provider value={authContextValue}>
      {children}
    </AuthContext.Provider>
  )
}
