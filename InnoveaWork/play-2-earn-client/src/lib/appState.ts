import indexDB, { AppState, defaultAppState } from "./indexDB"

export const appStateKey = 1

export const getAppState = (key: number) => indexDB.table("appState").get(key)

export const updateAppState = async (appState: AppState, key: number) => {
  const currentAppStates = await getAppState(key)
  const _appState = currentAppStates || defaultAppState
  // console.log(_appState)
  indexDB.table("appState").put({ ..._appState, ...appState, id: key })
}
