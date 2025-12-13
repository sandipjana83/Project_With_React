import { useCallback, useState,useEffect ,useRef} from 'react'
// import reactLogo from './assets/react.svg'
// import viteLogo from '/vite.svg'
// import './App.css'

function App() {
  const [length, setLength] = useState(8)
  const [numAllowed,setnumAllowed]=useState(false)
  const [charAllowed ,setcharAllowed] =useState(false)
  const [password,setPassword]= useState("");

  const passgenerator=useCallback(()=>{
    let pass=""
    let str= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    if(numAllowed) str+="0123456789";
    if(charAllowed) str+="!@#$%^&*_";
    for (let i = 0; i < length; i++) {
      let char = Math.floor(Math.random()* str.length +1);
      pass +=str.charAt(char)
    }

    setPassword(pass)
  },[length,numAllowed,charAllowed,setPassword]);
  useEffect(()=>{
      passgenerator()
  },[length,numAllowed,charAllowed,setPassword])

  const passref=useRef(null);

  const copyclipboard=useCallback(()=>{
      passref.current?.select()
      window.navigator.clipboard.writeText(password)
    },[password])

  const text=()=>{
    const para=document.getElementById('text');
    para.innerText='Copied successfully!'
    setTimeout(()=>{para.innerText="";
    },1200);
    
  }
  
  return (
   <div
   className='w-full max-w-md mx-auto shadow-md rounded-lg px-4
    py-3.3 my-8 bg-gray-700 text-orange-400'
   >
     <h1 className='text-white text-center'>Password Generator</h1>
     <div className='flex shadow-2xs rounded-lg overflow-hidden mb-4'>
          <input
          type='text'
          placeholder='Password'
          value={password}
          className='outline-none px-2 py-1 w-full rounded-lg bg-amber-50'
          readOnly
          ref={passref}
          />
          <button
          onClick={()=>{copyclipboard(),text()}}
          className='outline-blue-100 bg-blue-500 px-2 py-.5 shrink-0 rounded-2xl
          text-white'
          >Copy</button>
     </div>
     <div className='shadow-2xs text-xs text-blue-400 text-center overflow-hidden' id='text'>
     </div>
     <div className='flex text-sm gap-x-2'>
      <div className='flex items-center gap-x-1'>
          <input
          className='cursor-pointer'
          type='range'
          min={8}
          max={64}
          value={length}
          onChange={(e)=>{setLength(e.target.value)}}
          />
          <label className='text-6xs'>Length : <span className='text-green-500'>{length}</span></label>

        <input
        type='checkbox'
        defaultChecked={numAllowed}
        id='numIp'
        onChange={()=> setnumAllowed((prev)=> !prev)}
        />
        <label className='text-6xs'>Numbers</label>  
        
        <input
        type='checkbox'
        defaultChecked={charAllowed}
        id='charIp'
        onChange={()=> setcharAllowed((prev)=> !prev)}
        />
        <label className='text-6xs'>Characters</label>
      </div>
        
     </div>
   </div>
  )
}

export default App
