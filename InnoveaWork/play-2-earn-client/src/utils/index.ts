import moment from "moment"
import { getInstruments } from "../api/Instruments"
import { getPortfoliosRank } from "../api/Portfolio"
import { JoinedPortfolioType, PortfolioType } from "../interface/Portfolio"
import { getReturnX } from "./returnX"

export const formatJoinedPortfoliosData = async (
  portfolioRanks: any,
  joinedPortfolios: any
) => {
  let _joinedPortfolios = []
  for (const joinedPortfolio of joinedPortfolios) {
    const portfolioRank = portfolioRanks[joinedPortfolio.ipid]
    _joinedPortfolios.push({
      ...joinedPortfolio,
      points: portfolioRank?.total || null,
      rank: portfolioRank?.rank || null,
      returnX: getReturnX(portfolioRank?.rank),
    })
  }
  return _joinedPortfolios
}

export const fetchWeekInstruments = async (
  catalogId: number,
  weekNumber: number,
  contestId: number,
  joinedPortfolios: PortfolioType[] | JoinedPortfolioType[]
) => {
  const { data } = await getInstruments(catalogId, weekNumber)
  const { data: portfolioRanks } = await getPortfoliosRank(
    contestId,
    data.length ? weekNumber : 1
  )
  const _joinedPortfolios = await formatJoinedPortfoliosData(
    portfolioRanks,
    joinedPortfolios
  )
  console.log("Fetch Call1", portfolioRanks, _joinedPortfolios)
  const totalEntries = Object.keys(portfolioRanks).length;
  console.log("Total Entries", totalEntries)
  return { _joinedPortfolios, totalEntries }
}

export const getPortfoliosResults = (portfolios: PortfolioType[]) => {
  const uniqueScores = portfolios
    .map((obj) => obj?.score?.portfolioScore || 0)
    .sort((a, b) => b - a)

  const scoreToRankMap = uniqueScores.reduce((map, score, index) => {
    const rank = portfolios.filter(
      (obj) => (obj?.score?.portfolioScore || 0) >= score
    ).length
    map[score] = rank + 1
    return map
  }, {} as { [key: number]: number })

  return portfolios.map((obj) => ({
    ...obj,
    rank: scoreToRankMap[obj?.score?.portfolioScore || 0],
    points: obj?.score?.portfolioScore || 0,
    returnX: getReturnX(scoreToRankMap[obj?.score?.portfolioScore || 0]),
  }))
}

export const getCurrentTimeString = () => {
  return moment().format("HH:mm:ss")
}
export const getWeekNumber = () => {
  return moment().week()
}
