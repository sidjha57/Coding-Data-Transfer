import Navbar from "./Navbar";
import Home from './Home';
import Create from "./Create";
import {BrowserRouter as Router, Route, Routes as Switch} from 'react-router-dom';
import BlogDetails from "./BlogDetails";
import NotFound from "./NotFound";


function App() {
  return (
    <Router>
      <div className="App">
        <Navbar />
        <div className="content">
          <Switch> {/*Switch inspects all the route and displays the one which matches with the path*/}
            <Route path="/" element={<Home/>}/>
            <Route path="/create" element={<Create/>}/>
            <Route path="/blogs/:id" element={<BlogDetails/>}/>
            <Route path="*" element={<NotFound/>}/>

          </Switch>
        </div>
      </div>
    </Router>
  );
}

export default App;
