import { useEffect, useState } from 'react'
import { ThemeProvider } from './Contex/theme'
import './App.css'
import ThemeBtn from './Components/themebtn'
import Card from './Components/card'


function App() {
  const[themeMode,setThememode]=useState('light')
  const lightTheme=()=> setThememode('light')
  const darkTheme =()=>setThememode('dark')

  useEffect(()=>{
    document.querySelector('html').classList.remove('light','dark')
    document.querySelector('html').classList.add(themeMode)
  },[themeMode])
  return (
    <ThemeProvider value={{themeMode,lightTheme,darkTheme}}>
    <div className="flex flex-wrap min-h-screen items-center">
          <div className="w-full">
              <div className="w-full max-w-sm mx-auto flex justify-end mb-4">
                  <ThemeBtn />
              </div>

              <div className="w-full max-w-sm mx-auto">
                  <Card />
              </div>
          </div>
    </div>
    </ThemeProvider>
  )
}

export default App
