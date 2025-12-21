import { configureStore } from "@reduxjs/toolkit";
import reducer from "../Features/features/todo/todoSlice.js";
export const store = configureStore({
  reducer: {
    todo: reducer   // 👈 KEY NAME MUST MATCH
  }
});
