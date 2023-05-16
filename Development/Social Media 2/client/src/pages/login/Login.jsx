import "./login.scss";
import { Link } from "react-router-dom";


function Login() {
  return (
    <div className="login">
      <div className="card">
        <div className="left">
          <h1>Hello Buddy!</h1>
          <p>
            Welcome to Sid's Social Media, Connect with friends and family. Show the
            world what are you upto...
          </p>
          <span>Don't you have an account?</span>
          <Link to="/register">
            <button>Register</button>
          </Link>
        </div>
        <div className="right">
          <h1>Login</h1>
          <form>
            <input type="username" placeholder="Username" required />
            <input type="password" placeholder="Password" required />
            <Link to="/home">
              <button>Login</button>
            </Link>
          </form>
        </div>
      </div>
    </div>
  );
}

export default Login