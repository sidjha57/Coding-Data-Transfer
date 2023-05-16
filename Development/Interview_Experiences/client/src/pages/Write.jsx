import React, { useState } from 'react';
import {  useLocation, useNavigate } from 'react-router-dom';
import Editor, {desc} from '../editor/Editor.js';
import EditorToolbar, { modules, formats } from "../editor/EditorToolbar.js";
import moment from "moment";
import { useEffect } from 'react';
import ReactQuill from 'react-quill';
import axios from 'axios';


const Write = () => {
  const navigate = useNavigate();
  const state = useLocation().state;
  const [error, setError] = useState("");
  const [values, setValues] = useState({
    role: state?.role ||  "",
    company: state?.company || "",
    desc: state?.desc || null,
    ctc: state?.ctc || 0,
    college: state?.college || "",
    type: state?.type || "On Campus",
    experience: state?.experience || "Positive Experience",
    status: state?.status || "Accepted Offer",
    level: state?.level || "Easy Level",
    cat: state?.cat || "",
    img: state?.img || "",
    date: state?.date || "",
  });

 
  const handleChange = e => {
    setValues(prev =>({...prev, [e.target.name]: e.target.value})) // this updates only the object value which is changed
  };

  const handleDescChange = desc => {
    setValues(prev => ({...prev, ["date"]: moment().format()}));
    setValues(prev => ({...prev, ["desc"]: desc}))
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    try{
      // console.log(values);
      const res = await axios.post("/posts/", {...values});
      // console.log(res);
      navigate("/");
    }catch(err){
      setError(err.response.data);
      console.log(err);
      // console.log(error);
    }
  }

  return (
    <div className="add">
      <div className="content">
        <input type="text" placeholder="Role Offered" value={values.role} onChange={handleChange} name="role"/>
        <input type="text" placeholder="Company Name" value={values.company} onChange={handleChange} name="company"/>
        <div className="editorContainer" name="desc">
          {/* <Editor /> */}
          <EditorToolbar />
          <ReactQuill
            theme="snow"
            value={values.desc}
            onChange={handleDescChange}
            placeholder={"Share your interview experience..."}
            modules={modules}
            formats={formats}
          />
        </div>
      </div>
      <div className="menu">
        <div className="item">
          <h1>Publish</h1>
          <span>
            <b>Status: </b> Draft
          </span>
          <span>
            <b>Visibility: </b> Public
          </span>
          <input style={{ display: "none" }} type="file" id="file" name="" />
          <label className="file" htmlFor="file">
            Upload Cover Image
          </label>
          <div className="buttons">
            <button>Save as a Draft</button>
            <button onClick={handleSubmit}>Update</button>
          </div>
        </div>

        <div className="item">
          <div className="details">
          <h1>Details</h1>
          <span><b>CTC Offered</b></span>
          <div className="ctc">
            <input type="number" placeholder="CTC in LPA" value={values.ctc} onChange={handleChange} name="ctc"/>
          </div>
          <span><b>College Name</b></span>
          <div className="college">
            <input type="text" placeholder="SPCE" value={values.college} onChange={handleChange} name="college"/>
          </div>
          <span><b>Type Of Placement</b></span>
          <div className="type">
            <select name="type" id="placement" value={values.type} className="type"onChange={handleChange} >
              <option value="On Campus">On Campus</option>
              <option value="Off Campus">Off Campus</option>
            </select>
          </div>
          <span><b>How was your Experience?</b></span>
          <div className="experience">
            <select name="experience" id="experience" value= {values.experience} className="experience"onChange={handleChange} >
              <option value="Positive Experience">Positive</option>
              <option value="Neutral Experience">Neutral</option>
              <option value="Negative Experience">Negative</option>
            </select>
          </div>
          <span><b>Offer Status</b></span>
          <div className="status">
            <select name="status" id="status" value={values.status} className="status"onChange={handleChange}>
              <option value="Accepted Offer">Accepted Offer</option>
              <option value="No Offer">No Offer</option>
              <option value="Rejected Offer">Rejected Offer</option>
            </select>
          </div>
          <span><b>Interview Level</b></span>
          <div className="status">
            <select name="level" id="level" value={values.level} className="level"onChange={handleChange} >
              <option value="Easy Level">Easy</option>
              <option value="Average Level">Average</option>
              <option value="Difficult Level">Difficult</option>
            </select>
          </div>
          </div>
        </div>

        <div className="item">
          <h1>Category</h1>
          <div className="cat">
            <input type="radio" name="cat" value="IT" id="IT" onChange={handleChange} />

            <label htmlFor="IT">IT</label>
          </div>
          <div className="cat">
            <input type="radio" name="cat" value="banking" id="banking" onChange={handleChange} />

            <label htmlFor="banking">Banking</label>
          </div>
          <div className="cat">
            <input type="radio" name="cat" value="Marketing" id="Marketing" onChange={handleChange} />

            <label htmlFor="marketing">Marketing</label>
          </div>
          <div className="cat">
            <input type="radio" name="cat" value="Management" id="Management" onChange={handleChange} />

            <label htmlFor="management">Management</label>
          </div>
          <div className="cat">
            <input type="radio" name="cat" value="finance" id="finance" onChange={handleChange} />

            <label htmlFor="finance">Finance</label>
          </div>  <div className="cat">
            <input type="radio" name="cat" value="other" id="other" onChange={handleChange} />

            <label htmlFor="other">Other</label>
          </div>
        </div>
      </div>
    </div>
  );
}

export default Write