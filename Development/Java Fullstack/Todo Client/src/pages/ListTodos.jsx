import axios from 'axios';
import React, { useEffect, useState } from 'react'
import { useNavigate } from 'react-router-dom';
import { deleteTodoApi, retrieveTodoListApi } from '../api/TodoApiService';
import { useAuth } from '../security/AuthContext';

function ListTodos() {

  const authContext = useAuth();
  const username = authContext.username;

  const navigate = useNavigate();

  const today = new Date()

  const targetDate = new Date(today.getFullYear()+12, today.getMonth(), today.getDay());

  // console.log(targetDate)

  const [todos, setTodos] = useState([]);
  const [message, setMessage] = useState(null);


  const fetchData = async () => {
    await retrieveTodoListApi(username)
    .then((res) => {
      setTodos(res.data);
    })
    .catch((err) => console.log(err))
  } 

  useEffect(() => {
    fetchData()
  },[])

  function handleDelete(id) {
    deleteTodoApi(id, username)
    .then((res) => {
      console.log(res)
      fetchData()
      setMessage(`Delete of todo with id= ${id} successful`)
    })
    .catch((err) => console.log(err))
  }

  function handleUpdate(id) {
    navigate(`/todo/${id}`)
  }

  function handleAdd() {
    navigate(`/todo/-1`)
  }

  return (
    <div className="ListTodos">
      <h1>Things you want to do!</h1>
      {message && <div className="alert alert-danger">{message}</div>}
      <table className="table" >
        <thead>
            <tr>
                <th>Description</th>
                <th>Target Date</th>
                <th>Is Done?</th>
                <th>Delete</th>
                <th>Update</th>
            </tr>
        </thead>
        <tbody className="table-group-divider">
          { todos &&
            todos.map((todo) => (
              <tr key={todo.id}>

                <td>{todo.description}</td>
                <td>{todo.targetDate}</td>
                <td>{todo.done.toString()}</td>
                <td><button className="btn btn-danger" onClick={() => handleDelete(todo.id)}>Delete </button></td>
                <td><button className="btn btn-warning" onClick={() => handleUpdate(todo.id)}>Update </button></td>
              </tr>
            ))
          }
        </tbody>

    </table>

    <button className='btn btn-primary d-flex align-items-center' onClick={handleAdd} >Add New Todo</button>

    </div>
  )
}

export default ListTodos