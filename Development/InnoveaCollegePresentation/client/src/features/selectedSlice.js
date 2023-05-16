import { createSlice } from '@reduxjs/toolkit'
import { addDataIntoCache, getData } from '../js/caching';

export const selectedSlice = createSlice({
  name: 'selected',
  initialState: {
    headerStatus: await getData("headerStatus").then ((res) => {
      return res;
    }).catch ((err) => {}),
    portfolioStatus: await getData("portfolioStatus").then ((res) => {
      return res;
    }).catch ((err) => {}) ,
    footerStatus: await getData("footerStatus").then ((res) => {
      return res;
    }).catch ((err) => {}),
  },
  reducers: {
    SetHeaderStatus: (state, action) => {
      addDataIntoCache("headerStatus", "http://localhost:5173", action.payload);
      state.headerStatus = action.payload; 
    },

    SetPortfolioStatus: (state, action) => {
        addDataIntoCache("portfolioStatus", "http://localhost:5173", action.payload);
        state.portfolioStatus = action.payload;
    },

    SetFooterStatus: (state, action) => {
        addDataIntoCache("footerStatus", "http://localhost:5173", action.payload);
        state.footerStatus = action.payload;
    }
  },
})


// Action creators are generated for each case reducer function
export const { SetHeaderStatus, SetPortfolioStatus, SetFooterStatus } = selectedSlice.actions

export default selectedSlice.reducer