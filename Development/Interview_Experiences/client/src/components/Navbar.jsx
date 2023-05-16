import axios from 'axios'
import React, { useEffect, useState } from 'react'
import { useContext } from 'react'
import {Link, useLocation, useNavigate} from 'react-router-dom'
import { AuthContext } from '../context/AuthContext'
import Logo from "../img/Logo.png"
import SPCE_Logo from "../img/SPCE.webp"
import search from "../img/search.png"

const Navbar = () => {

  const location = useLocation();
  const navigate = useNavigate();

  const [searchText, setSearchText] = useState("");
  const {currentUser, logout} = useContext(AuthContext);

  const handleChange = (e) => {
    // e.preventDefault();
    setSearchText(e.target.value);
    // console.log(searchText);
  }

  const addQuery = (key, value) => {
    let pathname = location.pathname;
    let searchParams = new URLSearchParams(location.search);
    searchParams.set(key, value);
    navigate({
      pathname: pathname,
      search: searchParams.toString()
    });
  };

  let filter = useLocation().search;

  const handleSearch = async (e) => {
    e.preventDefault();
    addQuery("search", searchText);
    
    try {
      if (searchText.length > 0) {
        const res = await axios.get(`/posts/filters${filter}`);
      }
    }catch(err) {
      console.log(err);
    }

  }

  useEffect(() => {
    handleSearch();
  }, [searchText])
  return (
    <div className="navbar">
      <div className="container">
        <div className="logo">
          <Link to="/">
            <img src={SPCE_Logo} alt="" />
          </Link>
          {/* <p>Share Your Experience</p> */}
        </div>
        
        <form>
          <div className="searchbar">
            <input type="text" onChange = {handleChange} placeholder='Search..' />
            <button onClick = {handleSearch} ></button>
              <img onClick = {handleSearch} src={search} alt="Search" />
            {/* </button> */}
          </div>
        </form>

        <div className="links">
          <span>{currentUser?.name}</span>
          {currentUser ? (
            <span onClick={logout}>Logout</span>
          ) : (
            <Link className="link" to="login">
              Login
            </Link>
          )}
          <span className="write">
            <Link className="link" to="/write">
              Write
            </Link>
          </span>
        </div>
      </div>
    </div>
  );
}

export default Navbar