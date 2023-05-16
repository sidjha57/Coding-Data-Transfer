import React from "react"

type TabsProps = {
  children: React.ReactNode //👈 children prop typr
}

function Tabs(props: TabsProps) {
  return (
    <nav className="grid grid-flow-col place-content-center space-x-[72px] text-center" aria-label="Tabs">
      {props.children}
    </nav>
  )
}

export default Tabs
