import React,{useContext} from "react";
import Usercontext from "../Context/Usercontext";

function Profile() {
  const {user}=useContext(Usercontext)
  if (!user) {
    return <div>Please Login</div>
  }else{
    return <div>Welcome {user.username}</div>
  }
}
export default Profile