import React from "react"
import WhiteHomeIcon from "../assets/Images/WhiteHomeIcon.svg"
import BlackHomeIcon from "../assets/Images/BlackHomeIcon.svg"
import WhiteTrophyIcon from "../assets/Images/WhiteTrophyIcon.svg"
import BlackTrophyIcon from "../assets/Images/BlackTrophyIcon.svg"
import WhiteAnalysisIcon from "../assets/Images/WhiteAnalysisIcon.svg"
import BlackAnalysisIcon from "../assets/Images/BlackAnalysisIcon.svg"
import { useNavigate, useLocation, useSearchParams } from "react-router-dom"
import { useAuth } from "../context/AuthContext"

const Footer = () => {
  const navigate = useNavigate()
  const { pathname } = useLocation()
  const [searchParams, setSearchParams] = useSearchParams()

  const footerTabs = [
    {
      name: "Home",
      path: "/home",
      icon: WhiteHomeIcon,
      activeIcon: BlackHomeIcon,
    },
    {
      name: "IndexPlay",
      path: `/index`,
      icon: WhiteTrophyIcon,
      activeIcon: BlackTrophyIcon,
    },
    {
      name: "StockPlay",
      path: "/stock",
      icon: WhiteTrophyIcon,
      activeIcon: BlackTrophyIcon,
    },
    {
      name: "Learn",
      path: "/learn",
      icon: WhiteAnalysisIcon,
      activeIcon: BlackAnalysisIcon,
    },
  ]

  return (
    <footer className="bg-white border-t fixed w-screen bottom-0 h-16 grid grid-flow-col place-content-center justify-evenly">
      {footerTabs.map((tab) => (
        <div className="mt-5" key={tab.name}>
          <div
            onClick={() => {
              searchParams.set("catalogType", tab.path.split("/")[1])
              setSearchParams(searchParams)
              return navigate({
                pathname: tab.path,
                search : searchParams.toString()
              })
            }}
            className={`block cursor-pointer select-none  ${
              tab.path === pathname ? "font-bold" : ""
            }`}
          >
            <img
              className="h-5 w-5 mx-4"
              src={tab.path === pathname ? tab.activeIcon : tab.icon}
              alt=""
            />
            <p className="text-xs my-2 text-center">{tab.name}</p>
          </div>
        </div>
      ))}
    </footer>
  )
}

export default Footer
