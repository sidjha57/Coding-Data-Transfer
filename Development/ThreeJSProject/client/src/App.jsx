import { useState } from 'react'
import Home from './pages/Home'
import Customizer from './pages/Customizer'
import Canvas from './canvas/Index'

function App() {

  return (
    <main className="app transition-all">
      <Home />
      <Canvas />
      <Customizer />
    </main>
  )
}

export default App
