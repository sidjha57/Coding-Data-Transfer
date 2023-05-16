import { useState } from 'react'
import './App.css'
import {
  createBrowserRouter,
  Outlet,
  RouterProvider,
} from "react-router-dom";

import Home from './pages/Home'
import Header from './components/Header';
import Footer from './components/Footer';
import Questions from './pages/Questions';
import Roadmaps from './pages/Roadmaps';
import About from './pages/About';
import Practice from './pages/Practice';

const Layout = () => {

  return (
    <>
    <Header/>
    <Outlet/>
    <Footer/>
    </>
  )
    
}
  


const router = createBrowserRouter([
  {
    path: "/",
    element: <Layout />,
    children: [
      {
        path: "/",
        element: <Home />,
      },
      {
        path: "/home",
        element: <Home />,
      },
      {
        path: "/about",
        element: <About />,
      },
      {
        path: "/practice",
        element: <Practice />,
      },
      {
        path: "/questions",
        element: <Questions />,
      },
      {
        path: "/roadmaps",
        element: <Roadmaps />,
      }

    ],
  },
]);


function App() {

  return (
    <div className="App">
        <RouterProvider router={router}/>    
        </div>
  )
}

export default App
