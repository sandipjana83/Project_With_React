import { useState } from 'react'
// import reactLogo from './assets/react.svg'
// import viteLogo from '/vite.svg'
// import './App.css'

function App() {
  const [color, setColor] = useState('olive')
  const [textColor,settextColor] =useState('black')
  return (
    <div className='w-full h-screen duration-300'
    style={{backgroundColor:color}}
    >
      <h1 className='flex-wrap text-4xl py-60 px-160'
      style={{color:textColor}}
      ><i className='justify-center'>Playing With Color</i></h1>
      <div 
      className='fixed flex flex-wrap justify-center bottom-12 inset-x-0 px-2'>
        <div className='flex flex-wrap justify-center gap-4 shadow-lg bg-amber-100
        px-2.5 py-2 rounded-xl'>
          <button onClick={()=>{setColor("red"),settextColor('blue')}}
            className='outline-black px-3 py-1 rounded-2xl text-amber-50 shadow-2xl transition-transform 
            duration-300 hover:scale-116'
            style={{backgroundColor:"red"}}
          >Red</button>

          <button onClick={()=>{setColor("blue"),settextColor("orange")}}
            className='outline-black px-3 py-1 rounded-2xl text-amber-50 shadow-2xl
            transition-transform 
            duration-300 hover:scale-116'
            style={{backgroundColor:"blue"}}
          >Blue</button>

          <button
            onClick={()=>{setColor("violet"),settextColor('green')}}
            className='outline-black px-3 py-1 rounded-2xl text-amber-50 shadow-2xl
            transition-transform 
            duration-300 hover:scale-116'
            style={{backgroundColor:"violet"}}
          >violet</button>

          <button
            onClick={()=>{setColor("black"),settextColor('brown')}}
            className='outline-black px-3 py-1 rounded-2xl text-amber-50 shadow-2xl
            transition-transform 
            duration-300 hover:scale-116'
            style={{backgroundColor:"black"}}
          >Black</button>
        </div>
      </div>
    </div>
  )
}

export default App
