import { useState , useRef} from 'react'
import {
  createBrowserRouter,
  RouterProvider,
  Outlet,
  Navigate,
} from "react-router-dom";
import Footer from './components/Footer';
import Header from './components/Header';
import Instrument from './components/Instrument';
import Boosters from './pages/Boosters';
import Instruments from './pages/Instruments';
import Results from './pages/Results';
import Verification from './pages/Verification'
import Portfolio_Performance from './pages/Portfolio_Performance'
import Leaderboard from './pages/Leaderboard';
import ComingSoon from './pages/ComingSoon';
import DailyIndex from './pages/DailyIndex';
import Home from './pages/Home';
import { addDataIntoCache, getDataFromCache } from './js/caching';
import { getRanks, getTotalEntries, updatePoints } from './api/Ranks';
import moment from 'moment';
import { endContest, startContest } from './api/ContestClient';


addDataIntoCache("instruments", "http://localhost:5173", {
  id: null,
  instrument: []
});

let contestStatus = null;

const hour = Number(moment().format('HH:mm').toString().split(":")[0])
console.log(hour)

// at 9 am we start the contest and 3 pm we close the contest

if (hour >= -1 && hour <= 25) {
  contestStatus = "live";
  startContest();
} else {
  contestStatus = "upcoming";
  // endContest();
}


const Layout = () => {
  return (
    <>
      <Header />
      <Outlet />
      <Footer />
    </>
  )
}



const router = createBrowserRouter([
  {
    path: "/",
    errorElement: <ComingSoon />,
    children: [
      {
        path: "/",
        element: <Verification />
      },  
      {
        path: "/verify",
        element: <Verification />
      },
      {
        path: "/instruments",
        element: <Instruments />
      }, 
      {
        path: "/boosters",
        element: <Boosters />
      }, 
      {
        path: "/results",
        element: <Results contestStatus={contestStatus}/>
      }, 
      {
        path: "/performance",
        element: <Portfolio_Performance/>
      }, 

      {
        path: "/leaderboard",
        element: <Leaderboard contestStatus={contestStatus}/>
      }
    ]
  },
  {
    path: "/",
    element: <Layout />,
    errorElement: <ComingSoon />,
    children: [
      {
        path: "/",
        element: <Home contestStatus={contestStatus}/>
      },
      {
        path: "/index",
        element: <DailyIndex  contestStatus={contestStatus}/>
      },
      {
        path: "/coming",
        element: <ComingSoon />
      },
      {
        path: "/home",
        element: <Home contestStatus={contestStatus}/>
      },
      // {
      //   path: "/leaderboard",
      //   element: <Leaderboard contestStatus={contestStatus}/>
      // }
    ]

  }
])

function App() {
  return (
    <div className="App font-manrope flex flex-col h-screen bg-background overflow-auto">
        <RouterProvider router={router}/>

       {/* <Verification/> */}
       {/* <Daily/>  */}
       {/* <Instruments /> */}
       {/* <Boosters /> */}
       {/* <Results /> */}
       {/* <Portfolio_Performance /> */}
       {/* <Leaderboard /> */}
    </div>
  )
}

export default App;
