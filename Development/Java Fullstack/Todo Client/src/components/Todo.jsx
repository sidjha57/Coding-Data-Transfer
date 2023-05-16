import React, { useEffect, useState } from 'react'
import { useNavigate, useParams } from 'react-router-dom'
import { addTodoApi, retrieveTodoApi, updateTodoApi } from '../api/TodoApiService';
import { useAuth } from '../security/AuthContext';
import {Formik, Form, Field, ErrorMessage} from 'formik'

function Todo() {
  const {id} = useParams();
  const username = useAuth().username;
  const navigate = useNavigate();

  const fetchData = async () => {
    if (id != -1) {
        await retrieveTodoApi(id, username)
        .then((res) => {
            setDescription(res.data.description);
            setTargetDate(res.data.targetDate);
        })
        .catch((err) => console.log(err));
    }
  }

  useEffect(() => {
    fetchData();
  }, [id])


  const [description, setDescription] = useState('')
  const [targetDate, setTargetDate] = useState('')

  const handleSubmit = (values) => {
    // console.log(username);
    const todo = {
        id: id,
        username: username,
        description: values.description,
        targetDate: values.targetDate,
        isDone: false
    }
   
    if (id == -1) {
         // console.log(id)
        addTodoApi(username,todo)
        .then(response => {
            navigate('/todos');
            // console.log(response)
        })
        .catch(error => console.log(error))
    } else {
        updateTodoApi(id,username,todo)
        .then(response => {
            navigate('/todos');
            // console.log(response)
        })
        .catch(error => console.log(error))
    }
  }

  const validate = (values) => {

    const errors = {};

    if(values.description.length<5) {
        errors.description = 'Enter Atleast 5 characters';
    }

    if(values.targetDate === null || values.targetDate === '') {
        errors.description = 'Enter a target date';
    }

    // console.log("validate");
    return errors;
  }


  return (
    <div className="container">
        <h1>Enter Todo Details</h1>
        <div>
            <Formik initialValues={{description, targetDate}}
                enableReinitialize={true}
                onSubmit = {handleSubmit}
                validate = {validate}
                validateOnChange = {false}
                validateOnBlur = {false}
            >
                {
                    (props) => (
                        <Form>
                            <ErrorMessage 
                                name="description"
                                component="div"
                                className='alert alert-warning'
                            />
                              <ErrorMessage 
                                name="target"
                                component="div"
                                className='alert alert-warning'
                            />
                            <fieldset className='form-group mt-3'>
                                <label className="form-label">Description</label>
                                <Field type="text" className="form-control" name="description"/>
                            </fieldset>
                            <fieldset className='form-group mt-3'>
                                <label className="form-label">Target Date</label>
                                <Field type="date" className="form-control" name="targetDate"/>
                            </fieldset>
                            <div>
                                <button className="btn btn-success  mt-4" type="submit">Save</button>
                            </div>
                        </Form>
                    )
                }
            </Formik>
        </div>
    </div>
  )
}

export default Todo