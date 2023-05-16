import { createSlice } from '@reduxjs/toolkit'
import { getData, getDataFromCache } from '../js/caching';




export const authenticateSlice = createSlice({
  name: 'authenticate',
  initialState: {
    user: await getData("user").then ((res) => {
          return res;
    }),
  },
  reducers: {
    SetUser: (state, action) => {
      state.user = action.payload; 
    }
  },
})

// Action creators are generated for each case reducer function
export const { SetUser } = authenticateSlice.actions

export default authenticateSlice.reducer