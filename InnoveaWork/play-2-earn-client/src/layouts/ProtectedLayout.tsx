import React from "react"
import { Navigate, Outlet } from "react-router-dom"
import { useAuth } from "../context/AuthContext"

function ProtectedLayout() {
  const { user, isLoading } = useAuth()
    
    if (!isLoading && !user) return <Navigate to={"/login"} />
    
    return (
      <>
        {
          !isLoading &&
          <Outlet />
        }
      </>
    )
  
}

export default ProtectedLayout
