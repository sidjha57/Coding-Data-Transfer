import React from 'react'
import { useAuth } from '../security/AuthContext';

function Logout() {

  const authContext = useAuth();
  authContext.logout();
  return (
    <div>
        <h1>Logged out sucessfully!</h1>
        <p>Thankyou for using our App. Come back soon!</p>
    </div>
  )
}

export default Logout;