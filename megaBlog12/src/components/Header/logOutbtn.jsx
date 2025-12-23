import React from "react";
import authService, { AuthService } from "../../Appwrite/auth";
import {useDispatch} from 'react-redux';
import { logout } from "../../Store/authSlice";

function LogOutbtn() {
  const dispatch=useDispatch();
  const logoutHandeler=()=>{
    authService.logout().then(()=>{
    dispatch(logout())
    })
  }
  return(
   <button className="inline-block px-6 py-2 duration-200
   bg-blue-200 rounded-full"
   >Logout</button>
  )
}
export default LogOutbtn;