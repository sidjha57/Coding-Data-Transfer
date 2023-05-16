import {Link}  from "react-router-dom";

const BlogList = ({blogs, title, handleDelete}) => {
    // const blogs = props.blogs; // instead of using this we can destructure the components
    // const title = props.title;

    return ( 
        <div className="blog-list">
          <h2>{title}</h2>
            {
              blogs.map((blog) => (
              <div className="blog-preview" key={blog.id}> {/*For using react inside map we need to pass unique id */}
                <Link to={`/blogs/${blog.id}`}>
                  <h2>{blog.title}</h2>
                  <p>Written by {blog.author}</p>
                </Link>
                {/* <button onClick={() => {handleDelete(blog.id)}}>Delete</button> */}
              </div>
              
            ))}
        </div>
     );
}
 
export default BlogList;