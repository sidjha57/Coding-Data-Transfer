import React from "react";
import ReactQuill from "react-quill";
import EditorToolbar, { modules, formats } from "./EditorToolbar";
import "react-quill/dist/quill.snow.css";
import "./styles.css";

export var desc;

export const Editor = () => {
  const [state, setState] = React.useState({ value: null });
  const handleChange = value => {
    desc = value;
    setState({ value });
  };
  // console.log(state);
  return (
    <div className="text-editor">
      <EditorToolbar />
      <ReactQuill
        theme="snow"
        value={state.value}
        onChange={handleChange}
        placeholder={"Share your interview experience..."}
        modules={modules}
        formats={formats}
      />
      
    </div>
  
  );
};

export default Editor;




