export interface PortfolioType {
  contestSingleDayId: number
  ipid: number
  userId: number
  portfolioSelections: [
    {
      boosterSelection: number
      instrumentSelection: number
      ipid: number
      portfolioId: number
      instrumentId: number
      instrument: {
        ipid: number
        instrumentName: string
        instrumentSymbol: string
        instrumentToken?: 0
        isActive?: 0
        catalogId?: 0
      }
    }
  ]
  status: {
    contestCreateTimeStamp: Date
    ipid: number
    portfolioId: number
    portfolioStatus: string
  }
  score?: {
    ipid: number
    portfolioScore: number
    updatedTimeStamp: Date
    portfolioId: number
    portfolio_id: string
  }
}

export interface Selection {
  ipid?: number
  boosterSelection: number
  instrumentSelection: number
  portfolioId?: number
  instrumentId: number
}

export interface Status {
  ipid?: number
  portfolioCreateTimeStamp?: string
  portfolioId?: number
  portfolioStatus: string
}

export interface PortfolioCreateType {
  portfolioInstance: {
    ipid?: number
    userId: number
    contestSingleDayId: number
  }
  status: Status
  selections: Selection[]
}

export interface JoinedPortfolioType extends PortfolioType {
  points?: number
  rank?: number
  returnX?: string
}

export interface PortfolioIntrumentData {
  name: string
  score: number
  perChange: number
}
export interface PortfolioIntrumentKey {
  [key: number]: PortfolioIntrumentData
}
export interface PortfolioRankType {
  [key: number]: PortfolioIntrumentKey
  total: number
  rank: number
}
