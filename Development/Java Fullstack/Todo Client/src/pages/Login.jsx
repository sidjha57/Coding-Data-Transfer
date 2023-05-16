import React, { useState } from 'react'
import { useNavigate } from 'react-router-dom';
import { useAuth } from '../security/AuthContext';

function Login() {

  const authContext = useAuth();

  console.log(authContext);

  const [inputs, setInputs] = useState({
    username:"",
    password: "",
  });

  const [err,setError] = useState(null);
  const navigate = useNavigate();


  const handleChange = e => {
    setInputs(prev =>({...prev, [e.target.name]: e.target.value})) // this updates only the object value which is changed
  };

   async function handleSubmit (e) {
    e.preventDefault();
    console.log("reached here")
    await authContext.login(inputs.username, inputs.password)
    .then(() => {
      setError("Success");
      navigate(`/welcome/${inputs.username}`);
      console.log("authentucated")
    })
    .catch((err) => {
      setError("Failed");
    })
  }

  console.log(inputs);

  return (
    <div className="Login">
      <div className="row g-3 align-items-center">
        <form>
          <div className="mb-3">
            <label className="form-label">Username</label>
            <input type="text" className="form-control" name="username" placeholder='username' onChange={handleChange}/>
            <div id="emailHelp" className="form-text">We'll never share your credentials with anyone else.</div>
          </div>
          
          <div className="mb-3">
            <label className="form-label">Password</label>
            <input type="password" className="form-control" name="password" placeholder='password' onChange={handleChange}/>
          </div>
          
          <button type="submit" className="btn btn-primary" onClick={handleSubmit}>Login</button>
        </form>

          {err && <div className='alert alert-warning'>Authentication {err}. Invalid Credentials</div>}
        
      </div>
    </div>
  )
}

export default Login;