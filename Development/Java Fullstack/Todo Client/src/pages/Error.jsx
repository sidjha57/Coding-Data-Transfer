import React from 'react'
import { Link } from 'react-router-dom'


function Error() {
  return (
    <div>
      <h1>We are Working very hard</h1>
      <p>Page Broken. Navigate to Home Page <Link to="/welcome/yourname">Home</Link></p>
    </div>
  )
}

export default Error;