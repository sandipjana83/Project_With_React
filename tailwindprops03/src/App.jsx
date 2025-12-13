import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import Card from './components/card'

function App() {
  //const [count, setCount] = useState(0)
  
  return (
    <>
    <h1 className='bg-amber-200 text-blue-300'>Sandip With Koyel</h1>
    <br/>
    < Card username="koyel" btnText='About Koyel'/>
    < Card username="Samu" btnText='About Samu'/>
    </>
    
  )
}

export default App
