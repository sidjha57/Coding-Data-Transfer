import React, { useRef, useState, useEffect, useReducer } from "react";
import Autocomplete from '@mui/material/Autocomplete';
import TextField from '@mui/material/TextField';
import { Link, useNavigate, useLocation, useSearchParams } from "react-router-dom";
import axios from "axios";


const root = {  
  color: "teal",
  fontSize: 18,
  "& :hover": {
    color: "#87A2FB"
  },  
};
const textfield = {
  "& .MuiInputBase-input.MuiAutocomplete-input": {
    color: "#87A2FB",
    fontSize: 18
  },
  "& #custom-autocomplete-label": {
    color: "#87A2FB"
  },
  "& .MuiButtonBase-root.MuiAutocomplete-clearIndicator": {
    color: "#87A2FB"
  },
  '&[class*="MuiOutlinedInput-root"] .MuiAutocomplete-input:first-child': {
    paddingLeft: 26
  },
  "& .MuiOutlinedInput-notchedOutline": {
    borderColor: "teal"
  },
  "&:hover .MuiOutlinedInput-notchedOutline": {
    borderColor: "#87A2FB"
  },
  "&.Mui-focused .MuiOutlinedInput-notchedOutline": {
    borderColor: "teal"
  }
};


export default function RightSearchBar() {
  const location = useLocation();
  const navigate = useNavigate();

  const [values, setValues] = useState({
    college: [],
    role: [],
    company: [],
    cat: [],
    type: [],
    experience: [],
    status: [],
    level: [],
  })

  const [filters, setFilters] = useState({
    
    college: "",
    role: "",
    company: "",
    cat: "",
    type: "",
    experience: "",
    status: "",
    level: "",
  });

  const filtering = ["college","role","company","cat","type","experience","status","level"]
  let filter = useLocation().search;


  const addQuery = (key, value) => {
    let pathname = location.pathname;
    let searchParams = new URLSearchParams(location.search);
    searchParams.set(key, value);
    navigate({
      pathname: pathname,
      search: searchParams.toString()
    });
  };

  const deleteQuery = (key) => {
    let pathname = location.pathname;
    let searchParams = new URLSearchParams(location.search);
    searchParams.delete(key);
    navigate({
      pathname: pathname,
      search: searchParams.toString()
    });
  }
   
  const fetchData = async () => { 
    await Promise.all(
      filtering.map(async fil => {
        try{
            if (filter) {
              const res = await axios.get(`/posts/filters${filter}&filterType=${fil}`);
              setValues(prev =>({...prev, [fil]:res.data}))
              // console.log(res.data);
            } else {
              const res = await axios.get(`/posts/filters?filterType=${fil}`);
              setValues(prev =>({...prev, [fil]:res.data}))
              // console.log(res.data);
            }
        }catch(err){
            console.log(err);
        }
      })
    )  
  }

  useEffect(() => {
    fetchData();
  },[filters])
  
  function handleSelect (event,value,type) {
    if (value) {
      // console.log(value, "selected");
      setFilters(prev =>({...prev, [type]:value}))
      addQuery(type,value);
    } else {
      // console.log(value, "not selected");
      setFilters(prev =>({...prev, [type]:'%'}));
      console.log(filters);
      deleteQuery(type);
    }
  }

  return (
    <div className="rightbar">
        <Autocomplete
          sx={{ width: "20vw" }}
          id="custom-autocomplete"
          options={values.college}
          onChange={(event,value) => handleSelect(event,value?.college,"college")}
          getOptionLabel={(option) => `${option.college}`} //filter value
          isOptionEqualToValue={(option, value) => option.college === value.college}
          ListboxProps={{ sx: root }}
          renderInput={(params) => {
            return (
            
              <TextField
                name="college"
                {...params}
                variant="standard"
                label="College"
                sx={textfield}
                />
                );
              }}
        />
      <Autocomplete
          sx={{ width: "20vw" }}
          id="custom-autocomplete"
          options={values.company}
          onChange={(event,value) => handleSelect(event,value?.company,"company")}
          getOptionLabel={(option) => `${option.company}`} //filter value
          isOptionEqualToValue={(option, value) => option.company === value.company}
          ListboxProps={{ sx: root }}
          renderInput={(params) => {
            return (
              <TextField
              {...params}
              variant="standard"
              label="Company"
              sx={textfield}
              />
              );
            }}
      />

        <Autocomplete
          sx={{ width: "20vw" }}
          id="custom-autocomplete"
          options={values.role}
          onChange={(event,value) => handleSelect(event,value?.role,"role")}
          getOptionLabel={(option) => `${option.role}`} //filter value
          isOptionEqualToValue={(option, value) => option.role === value.role}
          ListboxProps={{ sx: root }}
          renderInput={(params) => {
            return (
              <TextField
              {...params}
              variant="standard"
              label="Role"
              sx={textfield}
              />
              );
            }}
      />
        <Autocomplete
          sx={{ width: "20vw" }}
          id="custom-autocomplete"
          options={values.cat}
          onChange={(event,value) => handleSelect(event,value?.category,"category")}
          getOptionLabel={(option) => `${option.cat}`} //filter value
          isOptionEqualToValue={(option, value) => option.cat === value.cat}
          ListboxProps={{ sx: root }}
          renderInput={(params) => {
            return (
              <TextField
              {...params}
              variant="standard"
              label="Category"
              sx={textfield}
              />
              );
            }}
      />
        <Autocomplete
          sx={{ width: "20vw" }}
          id="custom-autocomplete"
          options={values.type}
          onChange={(event,value) => handleSelect(event,value?.type,"type")}
          getOptionLabel={(option) => `${option.type}`} //filter value
          isOptionEqualToValue={(option, value) => option.type === value.type}
          ListboxProps={{ sx: root }}
          renderInput={(params) => {
            return (
              <TextField
              {...params}
              variant="standard"
              label="Type"
              sx={textfield}
              />
              );
            }}
      />
        <Autocomplete
          sx={{ width: "20vw" }}
          id="custom-autocomplete"
          options={values.level}
          onChange={(event,value) => handleSelect(event,value?.level,"level")}
          getOptionLabel={(option) => `${option.level}`} //filter value
          isOptionEqualToValue={(option, value) => option.level === value.level}
          ListboxProps={{ sx: root }}
          renderInput={(params) => {
            return (
              <TextField
              {...params}
              variant="standard"
              label="Level"
              sx={textfield}
              />
              );
            }}
      />

      <Autocomplete
          sx={{ width: "20vw" }}
          id="custom-autocomplete"
          options={values.experience}
          onChange={(event,value) => handleSelect(event,value?.experience,"experience")}
          isOptionEqualToValue={(option, value) => option.experience === value.experience}
          getOptionLabel={(option) => `${option.experience}`} //filter value
          ListboxProps={{ sx: root }}
          renderInput={(params) => {
            return (
              <TextField
              {...params}
              variant="standard"
              label="Experience"
              sx={textfield}
              />
              );
            }}
      />

    <Autocomplete
          sx={{ width: "20vw" }}
          id="custom-autocomplete"
          options={values.status}
          onChange={(event,value) => handleSelect(event,value?.status,"status")}
          isOptionEqualToValue={(option, value) => option.status === value.status}
          getOptionLabel={(option) => `${option.status}`} //filter value
          ListboxProps={{ sx: root }}
          renderInput={(params) => {
            return (
              <TextField
              {...params}
              variant="standard"
              label="Status"
              sx={textfield}
              />
              );
            }}
      />

    </div>
    
  );
}


