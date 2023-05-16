import "./login.css";
import {useRef, useContext} from "react";
import {loginCall} from "../../apiCalls";
import { AuthContext } from "../../context/AuthContext";
import CircularProgress from '@material-ui/core/CircularProgress';
import {useNavigate } from "react-router-dom";
// import CircularProgress from '@mui/material/CircularProgress';


export default function Login() {

 
  const navigate = useNavigate();
  const email = useRef();
  const password = useRef();

  const {user, isFetching, error, dispatch} = useContext(AuthContext);

  const handleClick = (e) =>{
    e.preventDefault();
    loginCall(
      { email: email.current.value, password: password.current.value },
      dispatch
    );
  }

  const handleRegister = (e) => {
    e.preventDefault();
    navigate("/Register");
  }

  return (
    <div className="login">
      <div className="loginWrapper">
        <div className="loginLeft">
          <h3 className="loginLogo">JhaSocial</h3>
          <span className="loginDesc">
            Expand your network meet people around the globe, enjoy being a
            social animal
          </span>
        </div>
        <div className="loginRight">
          <form className="loginBox" onSubmit={handleClick}>
            <input
              placeholder="Email"
              className="loginInput"
              type="email"
              required
              ref={email}
            />
            <input
              placeholder="Password"
              className="loginInput"
              type="password"
              required
              minLength="6"
              ref={password}
            />
            <button className="loginButton" type="submit" disabled={isFetching} >
              {isFetching ? (
                <CircularProgress color="white" size="20px" />
              ) : (
                "Log In"
              )}
            </button>
            <span className="loginForgot">Forgot Password?</span>
            <button className="loginRegisterButton" onClick={handleRegister}>
              {isFetching ? (
                <CircularProgress color="white" size="20px" />
              ) : (
                "Create a New Account"
              )}
            </button>
          </form>
        </div>
      </div>
    </div>
  );
}
