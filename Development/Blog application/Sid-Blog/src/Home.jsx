import BlogList from "./BlogList";
import useFetch from "./useFetch";


const Home = () => {
  const {
    data: blogs,
    isPending,
    error,
  } = useFetch(`http://localhost:8000/blogs`);

  // const handleDelete = (id) => {
  //     const newBlogs = blogs.filter(blog => blog.id !== id);
  //     setBlogs(newBlogs);
  // }

  return (
    <div className="home">
      {error && <div>{error}</div>}
      {isPending && <div>Loading...</div>}
      {/* this is how conditional output works in react */}
      {blogs && <BlogList blogs={blogs} title="All blogs" />}{" "}
      {/*We can pass multiple props*/}
      {/* <BlogList blogs={blogs.filter((blog) => blog.author === 'mario')} title="Mario's Blogs"/> */}
    </div>
  );
}
 
export default Home;