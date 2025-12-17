import React from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
//import App from './App.jsx'
import { createBrowserRouter, createRoutesFromElements, Route, RouterProvider } from 'react-router-dom'
import Layout from './Layout'
import Home from './components/Home/home'
import About from './components/About/about'
import Contact from './components/contact'
import Github from './components/Github/github'
import User from './components/User/user'

const router= createBrowserRouter([
  {
    path:'/',
    element:<Layout/>,
    children :[
      {path:"/Home",
        element:<Home/>
      },
      {
        path:"About",
        element: <About/>
      },
      {
        path:"/contact",
        element:<Contact/>
      },
      {
        path:"user/:userid",
        element:<User/>
      },
      {
        path:"github",
        element:<Github />
      }
      ]
    }
  
])



createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <RouterProvider router={router}/>
  </React.StrictMode>,
)
