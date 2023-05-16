import { createSlice } from '@reduxjs/toolkit'
import { addDataIntoCache, getData, getDataFromCache } from '../js/caching';
import { createPortfolio, deletePortfolioById, getUserPortfolios, updatePortfolioById} from '../api/Portfolio'


export const portfolioSlice = createSlice({
  name: 'portfolios',
  initialState: {
    portfolios: null,
    instruments: await getData("instruments").then ((res) => {
      return res;
    }).catch ((err) => {
      console.log(err);
      return {
        id: null,
        instrument: []
      }
    }),
  },
  reducers: {
   
    SetPortfolio: (state, action) => {
      state.portfolios = action.payload;
    },

    UpdatePortfolios: (state,action) => {
      const Portfolio = {
        instrument1 : null,
        booster1 : null,
        instrument2 : "",
        booster2 : null,
        instrument3 : "",
        booster3 : null,
        instrument4 : "",
        booster4 : null,
        status : ""
      };      
      Portfolio.status = action.payload.status;
      Portfolio.instrument1 = state.instruments.instrument[0].name;
      Portfolio.booster1 = state.instruments.instrument[0].booster;
      Portfolio.instrument2 = state.instruments.instrument[1].name;
      Portfolio.booster2 = state.instruments.instrument[1].booster;
      Portfolio.instrument3 = state.instruments.instrument[2].name;
      Portfolio.booster3 = state.instruments.instrument[2].booster;
      Portfolio.instrument4 = state.instruments.instrument[3].name;
      Portfolio.booster4 = state.instruments.instrument[3].booster;

      addDataIntoCache("instruments", "http://localhost:5173", {
        id: null,
        instrument: []
      })

      console.log(state.instruments.id)
      if (state.instruments.id) {
        console.log(Portfolio);
        updatePortfolioById(state.instruments.id, Portfolio);
      } else {
        createPortfolio(action.payload.user_id, Portfolio)
          .then((res) => {console.log(res)})
          .catch((err) => {console.log(err)});
      }
    },

    SetInstrument: (state, action) => {
      state.instruments = action.payload;
    },

    EditPortfolioStatus: (state, action) => {
        const index = action.payload.index;
        const status = action.payload.status;
        state.portfolios[index].status = status;
        updatePortfolioById(state.portfolios[index].id, state.portfolios[index])
        .then((res) => console.log(res))
        .catch((err) => console.log(err));
    },

    DeletePortfolio: (state, action) => {
      
      deletePortfolioById(action.payload)
      .then((res) => {
        console.log(res.data);
      })
      .catch((err) => console.log(err))
    },


    AddInstrument : (state, action) => {
      if (!state.instruments.instrument[0]) state.instruments.instrument = [];
      action.payload.booster = Number(action.payload.booster);
      state.instruments.instrument.push(action.payload);
      addDataIntoCache("instruments", "http://localhost:5173",state.instruments)
    },

    EditInstrument : (state, action) => {
      console.log(action.payload.booster);

      const reset = state.instruments.instrument.findIndex((instrument => Math.abs(instrument.booster) == Math.abs(action.payload.booster)));
      console.log(reset);
      if (reset != -1) {
        console.log(state.instruments.instrument[reset].booster);
        if (state.instruments.instrument[reset].booster > 0)
          state.instruments.instrument[reset].booster = 1 
        else
          state.instruments.instrument[reset].booster = -1 
      }
      const idx = state.instruments.instrument.findIndex((instrument => instrument.name == action.payload.name));
      state.instruments.instrument[idx].booster = action.payload.booster;
    
      addDataIntoCache("instruments", "http://localhost:5173",state.instruments)
    },

    DeleteInstrument : (state, action) => {
      const updatedInstrument = state.instruments.instrument.filter((instrument) => instrument.name != action.payload);
      state.instruments.instrument = updatedInstrument;
      addDataIntoCache("instruments", "http://localhost:5173",state.instruments)
    }
  },
})


// Action creators are generated for each case reducer function
export const { SetInstrument, UpdatePortfolios, SetPortfolio, EditPortfolio, EditPortfolioStatus, DeletePortfolio, AddInstrument, DeleteInstrument, EditInstrument } = portfolioSlice.actions

export default portfolioSlice.reducer