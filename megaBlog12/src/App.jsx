import { useState,useEffect } from 'react'
import {useDispatch} from 'react-redux'
import './App.css'
import authService from './Appwrite/auth';
import { login, logout } from './Store/authSlice';
import Header from './components/Header/header';
import Footer from './components/Footer/footer';

function App() {
  const  [load,setLoad]=useState(true);
  const dispatch=useDispatch();
  useEffect(()=>{
    authService.currUser()
    .then((userData)=>{
      if (userData) {
        dispatch(login({userData}));
      }
      else{
        dispatch(logout())
      }
      
    })
    .finally(()=>setLoad(false))
  },[])
  
  return !load ? (
    <div className='min-h-screen flex flex-wrap content-between
    bg-gray-400'><div className='w-full block'>
      <Header/>
      <main>
        Todo
      </main>
      <Footer/>
      </div></div>
  ): null
}

export default App
