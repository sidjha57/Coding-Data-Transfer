import { FaSearch, FaBars, FaTimes } from "react-icons/fa";
import { GiPistolGun } from "react-icons/gi";
import { AiOutlineUser, AiOutlineShoppingCart, AiOutlineWallet } from "react-icons/ai";
import { Link } from "react-router-dom";
import { useState } from "react";

function Header() {
  const [isMenuOpen, setIsMenuOpen] = useState(false);

  const toggleMenu = () => {
    setIsMenuOpen(!isMenuOpen);
  };

  return (
    <header className="bg-gray-800 fixed z-10 top-0 w-screen ">
      <div className="container mx-auto px-4 py-4 flex items-center justify-between">
        <Link to="/" className="text-white flex items-center flex-shrink-0 mr-4">
          <GiPistolGun className="text-white mr-2" size={48} />
          <span className="font-bold text-3xl">TopGUN</span>
        </Link>
        <div className="flex items-center flex-grow">
          <div className="w-full mr-4">
            <div className="relative flex items-center">
              <span className="absolute inset-y-0 left-0 pl-3 flex items-center">
                <FaSearch className="text-gray-500" />
              </span>
              <input
                type="text"
                className="bg-gray-900 text-white rounded-md py-2 pl-10 pr-4 focus:outline-none focus:bg-white focus:text-gray-900 w-full"
                placeholder="Search"
              />
            </div>
          </div>
          <button onClick={toggleMenu} className="text-white focus:outline-none md:hidden">
            {isMenuOpen ? <FaTimes /> : <FaBars />}
          </button>
        </div>
        <nav className={`md:flex md:items-center ${isMenuOpen ? "block" : "hidden"}`}>
          <ul className="flex flex-col md:flex-row space-x-4 md:space-x-8 md:space-y-0">
            <li>
              <Link to="/marketplace" className="text-white hover:text-gray-400">
                Marketplace
              </Link>
            </li>
            <li>
              <Link to="/organisation" className="text-white hover:text-gray-400">
                Organisation
              </Link>
            </li>
            <li>
              <Link to="/" className="text-white flex items-center">
                <AiOutlineUser className="text-white" size={24} />
              </Link>
            </li>
            <li>
              <Link to="/" className="text-white flex items-center">
                <AiOutlineWallet className="text-white" size={24} />
              </Link>
            </li>
            <li>
              <Link to="/" className="text-white flex items-center">
                <AiOutlineShoppingCart className="text-white" size={24} />
              </Link>
            </li>
          </ul>
        </nav>
      </div>
    </header>
  );
}

export default Header;


