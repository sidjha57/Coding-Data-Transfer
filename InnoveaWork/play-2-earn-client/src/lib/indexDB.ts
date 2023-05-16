import Dexie from "dexie"
import { InstrumentType } from "../interface/Intrument"

export interface AppState {
  id?: number
  catalogId?: number
  parameterId?: number
  showAppIntro?: boolean
  selectedInstruments?: InstrumentType[]
}

export const defaultAppState = {
  id: 1,
  catalogId: 0,
  parameterId: 0,
  showAppIntro: true,
  selectedInstruments: [],
}

const db = new Dexie("play-2-earn")
db.version(1).stores({
  appState: "id, catalogId, parameterId, showAppIntro, selectedInstruments",
})

export default db
