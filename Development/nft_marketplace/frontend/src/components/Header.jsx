import { FaSearch, FaBars, FaTimes } from "react-icons/fa";
import { GiPistolGun } from "react-icons/gi";
import { AiOutlineUser, AiOutlineShoppingCart, AiOutlineWallet } from "react-icons/ai";
import { Link } from "react-router-dom";
import { useState } from "react";
import { ethers, Signer} from "ethers";
import MarketplaceAddress from "../../../backend/scriptscontractsData/Marketplace-address.json"
import MarketplaceAbi from "../../../backend/scriptscontractsData/Marketplace.json"
import NFTAddress from "../../../backend/scriptscontractsData/NFT-address.json"
import NFTAbi from "../../../backend/scriptscontractsData/NFT.json"
import { addDataIntoCache, getDataFromCache } from "../caching/caches";

function Header() {
  const [isMenuOpen, setIsMenuOpen] = useState(false);
  const toggleMenu = () => {
    setIsMenuOpen(!isMenuOpen);
  };

  const [loading, setLoading] = useState(true)
  const [account, setAccount] = useState(null)
  const [nft, setNFT] = useState({})
  const [marketplace, setMarketplace] = useState({})

  // MetaMask Login/Connect
  const web3Handler = async () => {
    const accounts = await window.ethereum.request({ method: 'eth_requestAccounts' });
    addDataIntoCache("account", "http://localhost:5174", accounts[0]);
    setAccount(accounts[0]);
    // Get provider from Metamask
    
    const provider = new ethers.providers.Web3Provider(window.ethereum);
    console.log(provider);
    // Set signer
    const signer = provider.getSigner();

    window.ethereum.on('chainChanged', (chainId) => {
      window.location.reload();
    })

    window.ethereum.on('accountsChanged', async function (accounts) {
      addDataIntoCache("account", "http://localhost:5174", accounts[0]);
      setAccount(accounts[0])
      await web3Handler()
    })
    loadContracts(signer)
  }
  const loadContracts = async (signer) => {
    // Get deployed copies of contracts


    const marketplace = new ethers.Contract(MarketplaceAddress.address, MarketplaceAbi.abi, signer)
    addDataIntoCache("Marketplace", "http://localhost:5174", marketplace);
    setMarketplace(marketplace)
    

    const nft = new ethers.Contract(NFTAddress.address, NFTAbi.abi, signer)
    setNFT(nft)
    addDataIntoCache("nft", "http://localhost:5174", nft);


    setLoading(false)
  }

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
              <Link to="/create" className="text-white hover:text-gray-400">
                Create
              </Link>
            </li>
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
              {
                account ? 
                <div className="text-white">Name</div> 
                :
                <div onClick={web3Handler} className="text-white flex items-center">
                <AiOutlineUser className="text-white" size={24} />
              </div>
              }
             
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


