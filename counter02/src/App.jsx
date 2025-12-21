import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  let [count,setCounter]=useState(1);
  const addValue =function(){
    //console.log('Clicked' , Math.random()); 
    if(count<20){
      count=count+1;
    }
    if(count>20){
      count=20
    }
    
    setCounter(count)
  }

  const removeValue =function(){
    if(count>0){count-=1;}
    if(count<0){
      count=0;
    }
    
    setCounter(count)
  }
  return (
    <>
      
      <h1>Sandip with Code</h1>
      <h2>Countr Value :{count}</h2>
      <button
      onClick={addValue}
      >Add count: {count}</button>
      <br/>
      <button
      onClick={removeValue}
      >Remove count: {count}</button>
      <footer>Counter Value={count}</footer>
    </>
  )
}

export default App
