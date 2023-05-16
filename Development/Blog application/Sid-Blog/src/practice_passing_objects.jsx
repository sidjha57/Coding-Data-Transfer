import './App.css';

function App() {

  // outputting lists
  const [blogs, setBlogs] = useState([
    { title: 'My new website', body: 'lorem ipsum...', author: 'mario', id: 1 },
    { title: 'Welcome party!', body: 'lorem ipsum...', author: 'yoshi', id: 2 },
    { title: 'Web dev top tips', body: 'lorem ipsum...', author: 'mario', id: 3 }
  ])


  // useState is a hook, hooks in react rerenders the whole page whenever its value changes
  const [name, setName] = useState('mario');
  const [age, setAge] = useState(25);


  const title = 'Welcome to the blog';
  const likes = 50;
  const person = {
    name : 'Sid',
    age  : 21
  };

  const handleClick = (e) => {
    setName(`sejal`);
    setAge(`21`);
  }

  return (
    <div className="App">
      <div className="content">
        <h1>{title}</h1>
        {/* react creates variables, arrays to string but not boolean and objects */}
        <p>Liked {likes} times</p> 
        {/* <p>{person}</p> */}

        <p>{name} is {age} years old</p>
        <button onClick={handleClick}>Click me</button> 
        

        {blogs.map((blog) => (
          <div className="blog" key={blog.id}> {/*For using react inside map we need to pass unique id */}
            <h2>{blog.title}</h2>
            <p>Written by {blog.author}</p>
          </div>
        ))}

      </div>
    </div>
  );
}

export default App;
