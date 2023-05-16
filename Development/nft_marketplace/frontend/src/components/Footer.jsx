import { FaEnvelope, FaPhone } from "react-icons/fa";
import { GiPistolGun } from "react-icons/gi";
import { Link } from "react-router-dom";

function Footer() {
  return (
    <footer className="bg-gray-900">
      <div className="container mx-auto px-4 py-8">
        <div className="flex flex-wrap">
            
        <div className="w-full md:w-1/4 p-4">
          <Link to="/" className="text-white flex items-center flex-shrink-0 mr-4 mb-10">
            <GiPistolGun className="text-white mr-2" size={24} />
            <span className="font-bold text-xl">TopGUN</span>
          </Link>

          <div className="flex items-center mb-2">
            <FaPhone className="text-gray-500 mr-2" />
            <span className="text-white">+91 8600187098</span>
          </div>

          <div className="flex items-center">
            <FaEnvelope className="text-gray-500 mr-2" />
            <span className="text-white">contact@topgun.com</span>
          </div>
        </div>
          <div className="w-full md:w-1/4 p-4">
            <div className="conatiner mx-auto mb-8">
                <h2 className="text-white mb-4">Team Members</h2>
                <p className="text-gray-400">Siddharth Jha</p>
                <p className="text-gray-400">Siddhesh Jadhav</p>
                <p className="text-gray-400">Aditya</p>
                <p className="text-gray-400">Shivam Jha</p>

            </div>
            <h2 className="text-white mb-4">Links</h2>
            <ul className="list-unstyled">
              <li>
                <Link to="/" className="text-gray-400 hover:text-white">Home</Link>
              </li>
              <li>
                <Link to="/marketplace" className="text-gray-400 hover:text-white">Marketplace</Link>
              </li>
              <li>
                <Link to="/organisation" className="text-gray-400 hover:text-white">Organisation</Link>
              </li>
            </ul>
          </div>
          <div className="w-full md:w-2/5 p-4">
            <h2 className="text-white mb-4">Contact Us</h2>
            
            <form>
            <div className="mb-4 flex">
                <input
                    className="bg-gray-900  text-white rounded-md py-2 px-3 border border-gray-400 focus:outline-none focus:bg-white focus:text-gray-900 w-full mr-1"
                    type="text"
                    name="name"
                    placeholder="Enter Your Name"
                    id="name"
                />

              <input
                className="bg-gray-900  text-white rounded-md py-2 px-3 border border-gray-400 focus:outline-none focus:bg-white focus:text-gray-900 w-full ml-1"
                type="email"
                name="email"
                placeholder="Enter Your Email"
                id="email"
              />
            </div>
            <div className="mb-4">
              <textarea
                className="bg-gray-900  text-white rounded-md py-2 px-3 border border-gray-400 focus:outline-none focus:bg-white focus:text-gray-900 w-full"
                name="message"
                id="message"
                placeholder="Enter Your Message"
                rows="3"
              ></textarea>
            </div>
            <button
              className="bg-gray-700 hover:bg-gray-600 text-white py-2 px-4 rounded-md"
              type="submit"
            >
              Send Message
            </button>
          </form>

          </div>
        </div>
      </div>
      <div className="bg-gray-800 py-4">
        <div className="container mx-auto px-4">
          <p className="text-gray-400 text-center">&copy; 2023 TopGUN. All rights reserved.</p>
        </div>
      </div>
    </footer>
  );
}

export default Footer;
