import { configureStore } from '@reduxjs/toolkit'
import authenticateSlice from '../features/authenticateSlice'
import selectedSlice from '../features/selectedSlice'
import portfolioSlice from '../features/portfolioSlice'

export default configureStore({
  reducer: {
    authenticate: authenticateSlice,
    selected: selectedSlice,
    portfolios: portfolioSlice
  },
})