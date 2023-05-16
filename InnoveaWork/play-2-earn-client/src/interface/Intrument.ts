export interface InstrumentType {
  ipid: number
  instrumentName: string
  instrumentSymbol: string
  isActive: number
  portfolioId?: number
  instrumentSelection?: string
  boosterSelection?: number
}

export interface WeekInstrumentType {
  ipid: number
  weekNumber: number
  instrumentId: number
}
