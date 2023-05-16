import { Link } from "react-router-dom";

const Navbar = () => {
    return ( 
        <nav className="navbar">
            <h1>The Sid Articles</h1>
            <div className="links">
                <Link to="/">Home</Link>
                <Link to="/create" style={{ // inline styling in react is dynamic
                    color: "white",
                    backgroundColor: '#f1356d',
                    borderRadius: `8px`
                }}>New Company Experience</Link>
            </div>
        </nav>
     );
}
 
export default Navbar;