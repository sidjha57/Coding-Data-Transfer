import Navbar from "./Navbar";
import Home from './Home';
import Create from "./Create";
import {BrowserRouter as Router, Route, Routes as Switch} from 'react-router-dom';
import CompanyDetails from "./CompanyDetails";
import NotFound from "./NotFound";


function App() {
  return (
    <Router>
      <div className="App">
        <Navbar />
        <div className="content">
          <Switch> 
            <Route path="/" element={<Home/>}/>
            <Route path="/create" element={<Create/>}/>
            <Route path="/companies/:id" element={<CompanyDetails/>}/>
            <Route path="*" element={<NotFound/>}/>
          </Switch>
        </div>
      </div>
    </Router>
  );
}

export default App;
