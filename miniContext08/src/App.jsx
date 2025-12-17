import { useState } from 'react'
import UsercontextProvider from './Context/Usercontextprovider'
import './App.css'
import Login from './Components/login'
import Profile from './Components/profile'

function App() {

  return (
    <UsercontextProvider>
      <h1>React with Mini context</h1>
      <Login/>
      <Profile/>
    </UsercontextProvider>
  )
}

export default App
