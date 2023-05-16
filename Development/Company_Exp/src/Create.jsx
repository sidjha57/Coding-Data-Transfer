import { useState } from "react";
import { useNavigate } from 'react-router-dom';

const Create = () => {
    const [role, setRole] = useState('');
    const [body, setBody] = useState('');
    const [company, setCompany] = useState('mario');
    const [isPending, setIsPending] = useState(false);
    const history = useNavigate();

    const handleSubmit = (e) => {
      e.preventDefault();
      const blog = {role, body, company};

      setIsPending(true);
      
      fetch(`http://localhost:8000/blogs/`, {
        method: 'POST',
        headers: {"Content-Type": "application/json"},
        body: JSON.stringify(blog)
      }).then (() => {
        console.log("new blog added");
        setIsPending(false);
        history('/');
      })

    }

    return (
      <div className="create">
        <h2>Add a New Experience</h2>
        <form onSubmit={handleSubmit}>
          <label>Company :</label>
          <input
            type="text"
            required
            value={company}
            onChange={(e) => setRole(e.target.value)}
          />
          <label>Body :</label>
          <textarea
            required
            value={body}
            onChange={(e) => setBody(e.target.value)}
          ></textarea>
          <label>Role Offered :</label>
          <input
            required
            value={role}
            onChange={(e) => setCompany(e.target.value)}
          />
          {!isPending && <button>Add Experience</button>}
          { isPending && <button disabled>Adding Experience ....</button>}

        </form>
      </div>
    );
}
 
export default Create;