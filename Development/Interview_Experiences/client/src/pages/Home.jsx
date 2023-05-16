import axios from 'axios';
import React, { useEffect, useState } from 'react'
import ReactQuill from 'react-quill';
import { Link, useLocation, useNavigate } from 'react-router-dom';
import RightSearchBar from '../components/RightSearchBar';
import Accepted from '../img/icons/Accepted';
import Decline from '../img/icons/Decline';
import Neutral from '../img/icons/Neutral';
import moment from "moment";

function removeTags(str) {
  if ((str===null) || (str===''))
      return false;
  else
      str = str.toString();
        
  // Regular expression to identify HTML tags in 
  // the input string. Replacing the identified 
  // HTML tag with a null string.
  return str.replace( /(<([^>]+)>)/ig, '');
}

const Home = () => {

  const [posts, setPosts] = useState([])
  const navigate = useNavigate();
  
  const filter = useLocation().search;
  const fetchData = async ()=>{
    try{
      const res = await axios.get(`/posts${filter}`);
      setPosts(res.data);
    }catch(err){
      console.log(err);
    }
  };
  useEffect(()=>{
    fetchData();
  },[filter])

  function getDate (date) {
    const d = new Date(date);
    return d;
  }

  const handleClick = (id) => {
    navigate(`/post/${id}`)
  }

  return (
    <div className="home">
     
      <div className="posts">
        {posts &&
          posts.map((post) => (
            <div className="post" key={post.id}>
              {/* <div className="img">
              <img src={post.img} alt="" />
            </div> */}
              <div className="content">
                <Link className="link" to={`/post/${post.id}`}>
                  <h1>{post.role}</h1>
                </Link>
                <div className="details">
                  <span>{post.company}</span>
                  <span>{post.ctc} LPA</span>
                  <span>{post.type}</span>
                  <span>{post.college}</span>
                </div>

                <div className="info">
                  <div className="status">
                    {post.status === "Accepted Offer" ? (
                      <>
                        <Accepted /> <label>Accepted Offer</label>
                      </>
                    ) : post.status === "Rejected Offer" ? (
                      <>
                        <Decline />
                        <label>Rejected Offer</label>
                      </>
                    ) : (
                      <>
                        <Neutral />
                        <label>No Offer</label>
                      </>
                    )}
                  </div>

                  <div className="status">
                    {post.experience === "Positive Experience" ? (
                      <>
                        <Accepted /> <label>Postive Experience</label>
                      </>
                    ) : post.experience === "Negative Experience" ? (
                      <>
                        <Decline />
                        <label>Negative Experience</label>
                      </>
                    ) : (
                      <>
                        <Neutral />
                        <label>Neutral Experience</label>
                      </>
                    )}
                  </div>

                  <div className="status">
                    {post.level === "Easy Level" ? (
                      <>
                        <Accepted /> <label>Easy Interview</label>
                      </>
                    ) : post.level === "Difficult Level" ? (
                      <>
                        <Decline />
                        <label>Difficult Interview</label>
                      </>
                    ) : (
                      <>
                        <Neutral />
                        <label>Average Interview</label>
                      </>
                    )}
                  </div>
                </div>
                <div className="desc">
                  <p>
                    {
                      removeTags(post.desc)
                    }
                  </p>
                  {/* <ReactQuill
                    value={post.desc}
                    readOnly={true}
                    theme={"bubble"}
                    
                  /> */}
                </div>
                <div className="last">

                <Link className="link" to={`/post/${post.id}`}>

                  <button>Read More</button>
                </Link>
                  <span>
                    {
                      moment(getDate(post.date)).format('LL')
                    }
                  </span>
                </div>
              </div>
            </div>
          ))}
          
      </div>
      <div className="rightbar">
        <RightSearchBar />
      </div>

    </div>
  );
}

export default Home