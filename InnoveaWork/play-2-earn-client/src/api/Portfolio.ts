import { PortfolioCreateType, Selection, Status } from "../interface/Portfolio"
import { apiClient } from "./ApiClient"

const mockedPortfolioRankData = {
  "155": {
    "10": {
      name: "NIFTY BANK",
      score: -217.10600502398236,
      perChange: 1.0855300251199118,
    },
    "11": {
      name: "NIFTY AUTO",
      score: 39.81543643694404,
      perChange: 0.26543624291296025,
    },
    "16": {
      name: "NIFTY FMCG",
      score: 7.016092621083179,
      perChange: 0.0701609262108318,
    },
    "33": {
      name: "NIFTY IT",
      score: 129.15460068643387,
      perChange: -1.2915460068643387,
    },
    total: -41.11987527952128,
    rank: 3,
  },
  "158": {
    "10": {
      name: "NIFTY BANK",
      score: -108.55300251199118,
      perChange: 1.0855300251199118,
    },
    "11": {
      name: "NIFTY AUTO",
      score: 26.543624291296027,
      perChange: 0.26543624291296025,
    },
    "16": {
      name: "NIFTY FMCG",
      score: 10.524138931624769,
      perChange: 0.0701609262108318,
    },
    "33": {
      name: "NIFTY IT",
      score: 258.30920137286773,
      perChange: -1.2915460068643387,
    },
    total: 186.82396208379734,
    rank: 1,
  },
  "159": {
    "33": {
      name: "NIFTY IT",
      score: 193.7319010296508,
      perChange: -1.2915460068643387,
    },
    "36": {
      name: "NIFTY METAL",
      score: -22.730863070684766,
      perChange: 0.22730863070684768,
    },
    "51": {
      name: "NIFTY REALTY",
      score: -96.16526178321291,
      perChange: 0.9616526178321291,
    },
    "58": {
      name: "NIFTY SMLCAP 50",
      score: -65.79024659594215,
      perChange: 0.32895123297971074,
    },
    total: 9.04552957981096,
    rank: 2,
  },
}

const query = {
  where: {
    userId: 1,
    contestSingleDayId: 1,
  },
  fields: {
    ipid: true,
  },
  include: [
    {
      relation: "status",
      scope: {
        fields: {
          ipid: true,
          portfolioStatus: true,
        },
      },
    },
    {
      relation: "portfolioSelections",

      scope: {
        include: [
          {
            relation: "instrument",
            scope: {
              fields: {
                ipid: true,
                instrumentName: true,
                instrumentSymbol: true,
              },
            },
          },
        ],
      },
    },
    {
      relation: "score",
      scope: {
        fields: {
          ipid: true,
          portfolioScore: true,
        },
      },
    },
  ],
}

export const getUserPortfolios = (
  user_id: number,
  contest_instance: number
) => {
  console.log('Contest_Instance',contest_instance)
  query.where.userId = user_id
  query.where.contestSingleDayId = contest_instance
  return apiClient.get(`/portfolio-instances?filter=${JSON.stringify(query)}`)
}

export const createUserPortfolioInstance = (
  user_id: number,
  contestSingleDayId: number,
  status: string,
  selections: Selection[]
) => {
  const data: PortfolioCreateType = {
    portfolioInstance: {
      userId: user_id,
      contestSingleDayId: contestSingleDayId,
    },
    status: {
      portfolioStatus: status,
    },
    selections: selections,
  }

  return apiClient.post(`/add-portfolio`, data)
}

export const updatePortfolioStatusById = (
  status_id: number,
  status: string
) => {
  const data: { portfolioStatus: string } = { portfolioStatus: status }

  return apiClient.patch(`/portfolio-statuses/${status_id}`, data)
}

export const editPortfolioById = (
  portfolio_id: number,
  status: Status,
  selections: Selection[]
) => {
  const data: { status: Status; selections: Selection[] } = {
    status,
    selections,
  }

  return apiClient.patch(`/edit-portfolio/${portfolio_id}`, data)
}

export const deletePortfolioById = (id: number) => {
  return apiClient.delete(`/del-portfolio/${id}`)
}

export const getPortfoliosRank = (contestId: number, weekNumber: number) => {
  return apiClient.get(`/get-portfolio-rank/${contestId}/${weekNumber}`)
}

// export const getContestPortofolios = (contestId: number, portfolioIds: number[]) => {
// 	const query =
// }
