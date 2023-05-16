import React, { useState } from 'react'
import { Link, useNavigate } from 'react-router-dom'
import axios from "axios"

const Register = () => {
  // always initialize the useState
  const [inputs, setInputs] = useState({
    password:"",
    email:"",
    name: "",
  });
  const [err,setError] = useState(null);

  const navigate = useNavigate();

  const handleChange = e => {
    // by using this functional update we are updating the element in the memory and not reassigning 
    // it a new number to it, this helps in case of async update  
    setInputs(prev =>({...prev, [e.target.name]: e.target.value})) // this updates only the object value which is changed
  };

  const handleSubmit = async e => {
    e.preventDefault(); // do not refresh the page
    try{

      const res = await axios.post("/auth/register", inputs);
      console.log(res);

      navigate("/login");
    }catch(err){
      setError(err.response.data);
      console.log(err);
    }
  }

  // console.log(inputs)
  return (
    <div className='auth'>
      <h1>Register</h1>
      <form>
        <input type='text' placeholder='name' name='name' onChange={handleChange}/>
        <input type='email' placeholder='email' name='email' onChange={handleChange} />
        <input type='password' placeholder='password' name='password' onChange={handleChange}/>
        <button onClick={handleSubmit}>Register</button>
        {err && <p>{err}</p>}
        <span>Do you have an account? <Link to="/login">Login</Link></span>
      </form>
    </div>
  )
}

export default Register