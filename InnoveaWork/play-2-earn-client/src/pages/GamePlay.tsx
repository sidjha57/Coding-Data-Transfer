import React, { useState } from "react"
import P2EPopup from "../components/P2EPopup"
import Tabs from "../components/Tabs"
import TabMenu from "../components/TabMenu"
import DailyTab from "../components/GameTab"
import IntradayTab from "../components/IntradayTab"
import { getAppState, updateAppState, appStateKey } from "../lib/appState"
import { useSearchParams } from "react-router-dom"

const GamePlay = () => {

  const [selectedTab, setSelectedTab] = useState("daily")
  const [showAppIntro, setShowAppIntro] = useState(false)
  const [searchParams, setSearchParams] = useSearchParams();

  const tabs = [{ name: "intraday" }, { name: "daily" }]

  React.useEffect(() => {
    const contestType = searchParams.get('contestType')
    setSelectedTab(contestType? contestType : "daily")
  }, [searchParams])

  React.useEffect(() => {
    if (!showAppIntro) {
      getAppState(appStateKey).then((data) =>
        setShowAppIntro(data?.showAppIntro ?? true)
      )
    }
  }, [showAppIntro])

  return (
    <main className="">
      <div className=" bg-white  text-gray-700">
        <div className="fixed w-screen top-16 bg-white z-10">
          <div className="border-b">
            <Tabs>
              {tabs.map((tab) => (
                <TabMenu
                  key={tab.name}
                  name={tab.name}
                  isSelected={
                    tab.name.toLocaleLowerCase() ===
                    selectedTab.toLocaleLowerCase()
                  }
                  changeHandler={setSelectedTab}
                />
              ))}
            </Tabs>
          </div>
        </div>

        {selectedTab === "daily" && <DailyTab />}
        {selectedTab === "intraday" && <DailyTab />}
      </div>

      <P2EPopup showAppIntro={showAppIntro} updateAppState={updateAppState} />
    </main>
  )
}

export default GamePlay
