import { apiClient } from "./ApiClient"

// this api does not exists
export const getContestTypes = (
  catalogId: number,
  contestType: string = "indexDaily"
) =>
  apiClient.get(
    `contest-type-configs?filter[where][contestTypeConfigId]=${catalogId}&filter[where][contestType]=${contestType}`
  )

export const getContestParameter = (parameterId: number) =>
  apiClient.get(`contest-parameters/${parameterId}`)

/*
    contestTypeConfigId's
    indexDaily = 1
    indexIntradayA = 3
    indexIntradayB = 4
    stockDaily = 2
    stockIntradayA = 5
    stockIntradayB = 6
*/
export const getContest = (contestTypeConfigId: number, userId: number) => {
  const query = {
    limit: 2,
    where: {
      contestTypeConfigId: contestTypeConfigId,
      userId: userId,
    },
    fields: {
      contestSessionEndTime: true,
      contestSessionStartTime: true,
      ipid: true,
      contestTypeConfigId: true,
      marketInstanceId: true,
    },

    order: ["contestSessionStartTime ASC"],
    include: [
      {
        relation: "status",
        scope: {
          fields: {
            contestStatus: true,
          },
        },
      },
    ],
  }

  return apiClient.get(`contests?filter=${JSON.stringify(query)}`)
}
