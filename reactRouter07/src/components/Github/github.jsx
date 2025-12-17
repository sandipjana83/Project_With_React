import React, { useEffect, useState }  from "react";

function Github() {
  const [currdata,setData]=useState({});
  useEffect(()=>{
    fetch('https://api.github.com/users/sandipjana83')
    .then((res)=>res.json())
    .then((data)=>setData(data)
    )
  },[])
  return(
    <div className="text-3xl m-4 text-center bg-gray-600 text-white p-4">
      <div className="py-10 ">
        Github Name : {currdata .name}<br/>
        Github Followers : {currdata .followers}<br/>
        Location : {currdata .location}
      </div>
      
      <img src={currdata .avatar_url} alt="gihub img"className="mx-auto rounded-full mb-6" width='300'/>
    </div>
  );
  
}
export default Github;