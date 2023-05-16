import React, { useState } from 'react'
import { Link, useNavigate } from 'react-router-dom'
import axios from 'axios';
import { useContext } from 'react';
import { AuthContext } from '../context/AuthContext';

const Login = () => {
   // always initialize the useState
   const [inputs, setInputs] = useState({
    email:"",
    password: "",
  });
  const [err,setError] = useState(null);

  const navigate = useNavigate();

  const {login} = useContext(AuthContext);


  
  const handleChange = e => {
    setInputs(prev =>({...prev, [e.target.name]: e.target.value})) // this updates only the object value which is changed
  };

  const handleSubmit = async e => {
    e.preventDefault(); 
    try{
      await login(inputs);
      const res = await axios.post("/auth/login", inputs);
      console.log(res);
      navigate("/");
    }catch(err){
      alert("Wrong password typed");
      setError(err.response.data);
      console.log(err);
    }
  }

  // console.log(inputs);

  return (
    <div className='auth'>
      <h1>Login</h1>
      <form>
        <input required type='email' placeholder='email' name='email' onChange={handleChange}/>
        <input required type='password' placeholder='password' name='password' onChange={handleChange}/>
        <button onClick={handleSubmit}>Login</button>
        {err && <p>{err}</p>}
        <span>Don't you have an account? <Link to="/register">Register</Link></span>
      </form>
    </div>
  )
}

export default Login