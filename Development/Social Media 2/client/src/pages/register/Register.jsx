import "./register.scss";
import { Link } from "react-router-dom";


function Register() {
  return (
    <div className="register">
      <div className="card">
        <div className="left">
          <h1>Sid's Social</h1>
          <p>
            Welcome to Sid's Social Media, Connect with friends and family. Show the
            world what are you upto...
          </p>
          <span>You have an account?</span>
          <Link to="/login">
            <button>Login</button>
          </Link>
        </div>

        <div className="right">
          <h1>Register</h1>
          <form>
            <input type="text" placeholder="Name" required />
            <input type="email" placeholder="Email" required />
            <input type="username" placeholder="Username" required />
            <input type="password" placeholder="Password" required />
            <Link to="/login">
              <button>Register</button>
            </Link>
          </form>
        </div>
        
      </div>
    </div>
  );
}

export default Register