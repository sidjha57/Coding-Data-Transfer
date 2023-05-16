// Uncomment these imports to begin using these cool features!

import { del, getModelSchemaRef, param, patch, post, requestBody, response } from "@loopback/openapi-v3";
import { repository, WhereBuilder } from "@loopback/repository";
import { IpPortfolioInstance } from "../models";
import { IpPortfolioInstanceRepository, IpPortfolioSelectionRepository, IpPortfolioStatusAuditRepository, IpPortfolioStatusRepository } from "../repositories";

// import {inject} from '@loopback/core';

interface Portfolio {
  portfolioInstance: {
    ipid?: number,
    userId : number,
    contestSingleDayId: number
  },
  status: {
   ipid?: number,
   portfolioCreateTimeStamp?: string,
   portfolioId?: number,
   portfolioStatus: string 
  },
  selections: 
    {
      ipid?: number,
      boosterSelection: number,
      instrumentSelection: number,
      portfolioId?: number,
      instrumentId: number
    } [] 
}

const PortfolioSchema = {
  description: 'Portfolio',
  required: true,
  content: {
    'application/json': 
    {
      schema: {
        type: 'object',
        properties: {
          portfolioInstance: {
            type: 'object',
            properties: {
              userId: {type: 'number'},
              contestSingleDayId: {type: 'number'}
            }
          },
          status: {
            type: 'object',
            properties: {
              portfolioId : {type:'number'},
              portfolioStatus : {type:'string'}
            }
          },
          selections:{
            type:'array',
            items:{
              type:'object',
              properties:{
                boosterSelection:{type:'number'},
                instrumentSelection:{type:'number'},
                portfolioId:{type:'number'},
                instrumentId:{type:'number'}
              }
            }
          }
        }
      }
    } as const
  }
};


export class IpPortfolioController {
  constructor(
    @repository(IpPortfolioInstanceRepository)
    public ipPortfolioInstanceRepository : IpPortfolioInstanceRepository,
    @repository(IpPortfolioSelectionRepository)
    public ipPortfolioSelectionRepository : IpPortfolioSelectionRepository,
    @repository(IpPortfolioStatusRepository)
    public ipPortfolioStatusRepository : IpPortfolioStatusRepository,
  ) {}

  @post('/add-portfolio')
  @response(200, {
    description: 'Creating a new portfolio',
    // content: {'application/json': {schema: getModelSchemaRef(IpPortfolioInstance)}},
  })
  async create(
    @requestBody(PortfolioSchema) variable: Portfolio

  ): Promise<Portfolio> {
    const result : any = {};

    try {
      const instance = await this.ipPortfolioInstanceRepository.create(variable.portfolioInstance);
    
      result.portfolioInstance = instance;

      variable.status.portfolioId = instance.ipid;
      variable.selections.map((selected) => {
        return selected.portfolioId = instance.ipid
      })

      const status = await this.ipPortfolioStatusRepository.create(variable.status);

      const selections = await this.ipPortfolioSelectionRepository.createAll(variable.selections);

      result.status = status;
      result.selections = selections;

      // console.log(variable);
      return result;

    } catch (err) {
      return err;
    }
  }

  @del('/del-portfolio/{id}')
  @response(204, {
    description: 'IpPortfolioInstance DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    const whereBuilder = new WhereBuilder();
    const where = whereBuilder
    .eq('portfolioId', id)
    .build();

    await this.ipPortfolioStatusRepository.deleteAll(where);
    await this.ipPortfolioSelectionRepository.deleteAll(where);
    await this.ipPortfolioInstanceRepository.deleteById(id);
    
  }

  @patch('/edit-portfolio/{id}')
  @response(204, {
    description: 'IpPortfolioInstance PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      // content: {
      //   'application/json': {
      //     schema: any,
      //   },
      // },
    })
    newPortfolio: any ,
  ): Promise<void> {
    const whereBuilder = new WhereBuilder();
    const where = whereBuilder
    .eq('portfolioId', id)
    .build();
    // console.log(newPortfolio);
    await this.ipPortfolioSelectionRepository.deleteAll(where);
    await this.ipPortfolioSelectionRepository.createAll(newPortfolio.selections);
    await this.ipPortfolioStatusRepository.updateById(newPortfolio.status.ipid, newPortfolio.status);

  }

}





