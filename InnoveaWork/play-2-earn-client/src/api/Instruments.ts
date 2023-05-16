import { apiClient } from "./ApiClient"

export const getInstruments = (catalogId: number = 1, weekNumber: number = 1) =>
  apiClient.get(
    `instrument-weeks-by-catalog?filter[where][catalogId]=${catalogId}&filter[where][weekNumber]=${weekNumber}`
  )

export const getWeekInstruments = (weekNumber: number = 1) =>
  apiClient.get(`instrument-weeks?filter[where][weekNumber]=${weekNumber}`)
