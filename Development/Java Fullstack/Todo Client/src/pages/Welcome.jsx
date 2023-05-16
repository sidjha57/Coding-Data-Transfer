import React from 'react'
import { useParams, Link} from 'react-router-dom';
import { useAuth } from '../security/AuthContext';
import { retriebeHelloWorldPathVariable } from '../api/HelloWorldApiService';

const Welcome = () => {
  const params = useParams();
  // const authContext = useContext(AuthContext);
  const authContext = useAuth();
  const username = authContext.username;

  const handleClick = () => {
    retriebeHelloWorldPathVariable(username, authContext.token)
    .then((res) => console.log(res))
    .catch((err) => console.log(err));
  }

  return (
    <div className="Welcome">
      <h1>Welcome {params.username}</h1>
      <div>
        Manage your todos <Link to="/todos">Go here</Link>
      </div>
      <button className='btn btn-success' onClick={handleClick}>Call Hello World</button>
    </div>


  )
}

export default Welcome;