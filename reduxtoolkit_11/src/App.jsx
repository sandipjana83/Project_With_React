import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import AddTodo from './Components/addTodo'
import Todos from './Components/Todos'

function App() {
  
  return (
    <>
      <h1 className='text-2xl text-green-600'>Learn about redux toolkit</h1>
      <AddTodo />
      <Todos />
    </>
  )
}

export default App