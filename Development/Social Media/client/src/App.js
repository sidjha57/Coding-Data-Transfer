import Home from "./pages/home/Home";
import Login from "./pages/login/Login";
import Profile from "./pages/profile/Profile";
import Register from "./pages/register/Register";
import { useContext } from "react";
import {AuthContext} from "./context/AuthContext";
import Messenger from "./pages/messenger/Messenger";

import {
  BrowserRouter as Router,
  Routes as Switch,
  Route,
  Navigate as Redirect
} from "react-router-dom";

function App() {

  const {user} = useContext(AuthContext)

  return (
    <Router>
      <Switch>
        <Route exact path="/" element={user ? <Home /> : <Login />} />
        <Route path="/login" element={user ? <Redirect to="/" /> : <Login />} />
        <Route path="/register" element={user ? <Redirect to="/" /> : <Register />} />
        <Route path="/profile/:username" element={<Profile />} />
        <Route path="/messenger" element={!user ? <Redirect to="/"/> : <Messenger/>} />
      </Switch>
    </Router>
  );
}

export default App;
