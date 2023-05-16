// Uncomment these imports to begin using these cool features!

import { Filter, repository } from "@loopback/repository";
import { IpContestSingleDayInstanceRepository, IpContestStatusRepository, IpPortfolioInstanceRepository } from "../repositories";
import moment from "moment";
import { get, getModelSchemaRef, param, post, requestBody, response } from "@loopback/openapi-v3";
import { IpContestSingleDayInstance } from "../models";

// import {inject} from '@loopback/core';
const ContestSchema = {
  description: 'Start Contest',
  content: {
    'application/json': 
    {
      schema: {
        type: 'object',
        properties: {
          userId: {type: 'number'},
          contestTypeConfigId: {type: 'number' }
        },
      },
    } as const,
  },
};


interface Contest {
  startTime: string; // optional string formatted as a date
  status?: string; // one of these two strings
}

export class IpGetContestInstanceController {
  constructor(
    @repository(IpContestSingleDayInstanceRepository)
    public ipContestSingleDayInstanceRepository: IpContestSingleDayInstanceRepository,
    @repository(IpContestStatusRepository)
    public ipContestStatusRepository: IpContestStatusRepository,
    @repository(IpPortfolioInstanceRepository)
    public ipPortfolioInstanceRepository: IpPortfolioInstanceRepository,
  ) {}
  @get('/contests')
  @response(200, {
    description: 'Array of IpContestSingleDayInstance model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpContestSingleDayInstance, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpContestSingleDayInstance) filter?: Filter<IpContestSingleDayInstance>,
  ): Promise<IpContestSingleDayInstance[]> {
    //  console.log(moment().startOf('day'))
    //  console.log(moment.utc().startOf('day'))
     filter = {
      ...filter,
      where: {
        ...filter?.where,
        contestSessionStartTime: {gte: moment().startOf('day')}
      }
     }
     

    const variable : any =  await this.ipContestSingleDayInstanceRepository.find(filter);
    
    if (variable[0].status.contestStatus === "UPCOMING") {
      return variable[0]
    } else {
      const where : any = filter.where
      const userId : any = where?.userId
      const contestInstance : any = variable[0].ipid;
      // console.log(userId, contestInstance)
      const query = `
        SELECT ip_portfolio_instance.ipid FROM ip_portfolio_instance
        INNER JOIN ip_portfolio_status
        ON ip_portfolio_instance.ipid = ip_portfolio_status.portfolio_id
        WHERE ip_portfolio_instance.user_id = ${userId} AND 
        ip_portfolio_instance.contest_single_day_id = ${contestInstance} AND
        ip_portfolio_status.portfolio_status = 'JOINED'
        LIMIT 1
      
      `
      const portfolioInstances = await this.ipPortfolioInstanceRepository.execute(query)

      if (portfolioInstances.length > 0) {
        console.log("Joined")
        return variable[0]
      } else {
        console.log("Not Joined")
        return variable[1]
      }
      // console.log(portfolioInstances)
    }
    // return variable
  }
  
}


// Upcoming contest pagable 2 => date >= 
