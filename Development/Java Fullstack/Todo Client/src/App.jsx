import './App.css';
import {
  createBrowserRouter,
  RouterProvider,
  Outlet,
  Navigate,
} from "react-router-dom";
import Welcome from './pages/Welcome';
import AddTodo from './pages/AddTodo';
import Register from './pages/Register';
import Login from './pages/Login';
import Error from './pages/Error';
import Footer from './components/Footer';
import Header from './components/Header';
import ListTodos from './pages/ListTodos';
import Logout from './pages/Logout';
import {AuthProvider, useAuth} from './security/AuthContext';
import Todo from './components/Todo';


const Layout = () => {
  return (
    <>
      <Header  />
      <Outlet />
      <Footer />
    </>
  )
}

const AuthenticatedRoute = ({children}) => {
  const authContext = useAuth()

  if (authContext.isAuthenticated)
    return children;
  
  return <Navigate to="/login" />
}


const router = createBrowserRouter([
  {
    path: "/",
    element: <Layout/>,
    errorElement: <Error />,
    children: [
      {
        path: "/",
        element: 
        <AuthenticatedRoute>
          <ListTodos/>
        </AuthenticatedRoute>
      },
      {
        path: "/addTodo",
        element: 
        <AuthenticatedRoute>
          <AddTodo/>
        </AuthenticatedRoute>
      },
      {
        path: "/todos",
        element: 
        <AuthenticatedRoute>
          <ListTodos/>
        </AuthenticatedRoute>
      },
      {
        path: "/todo/:id",
        element: 
        <AuthenticatedRoute>
          <Todo/>
        </AuthenticatedRoute>
      },
      {
        path: "/welcome/:username",
        element: 
        <AuthenticatedRoute>
          <Welcome/>
        </AuthenticatedRoute>
      },
      {
        path: "/register",
        element: <Register/>
      },
      {
        path: "/login",
        element: <Login/>
      },
      {
        path: "/logout",
        element: <Logout/>
      }   
    ]
  },

])

function App() {
  return (
    <div className="App">
      <div className="container">
        <AuthProvider>
          <RouterProvider router={router}/>
        </AuthProvider>
      </div>
    </div>
  );
}

export default App;
