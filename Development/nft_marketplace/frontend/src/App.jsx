import {
  createBrowserRouter,
  RouterProvider,
  Outlet,
  Navigate,
} from "react-router-dom";
import Footer from './components/Footer';
import Header from './components/Header';
import Home from './pages/Home';
import Create from './pages/Create';


const Layout = ({account, Web3Provider}) => {
  return (
    <>
      <Header />
      <Outlet />
      <Footer />
    </>
  )
}

const router = createBrowserRouter ([
  {
    path: "/",
    element: <Layout/>,
    children: [
      {
        path: "/",
        element: <Home/>
      },
      {
        path: "/home",
        element: <Home/>
      },
      {
        path: "/create",
        element: <Create/>
      }
    ]
  }
 
])

function App() {
  return (
    <div className="App h-screen relative">
      <RouterProvider router={router}/>
    </div>
  )
}

export default App
