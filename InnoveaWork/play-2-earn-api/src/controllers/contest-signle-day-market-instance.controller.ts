// Uncomment these imports to begin using these cool features!
import moment from 'moment';
import {post, requestBody, response} from '@loopback/openapi-v3';
import {repository, Filter} from '@loopback/repository';
import {
  IpMarketConfigRepository,
  IpMarketInstanceRepository,
  IpMarketStatusRepository,
  IpMarketStatusAuditRepository,
  IpContestTypeConfigRepository,
  IpContestSingleDayInstanceRepository,
  IpContestStatusRepository,
  IpContestStatusAuditRepository,
} from '../repositories';

import {IpMarketConfig, IpContestTypeConfig} from '../models';
import {getDateOfMondayTwoWeeksFromNow} from '../utils';
import {checkMarketClose} from '../utils/holidays';

// import {inject} from '@loopback/core';

interface ContestSingleDayAndMarketInstance {
  startDate: string;
}

const ContestSingleDayAndMarketInstanceSchema = {
  description: 'Create Contest single day and market instance',
  content: {
    'application/json': {
      schema: {
        type: 'object',
        properties: {
          startDate: {type: 'string', format: 'date'},
        },
      },
    } as const,
  },
};

export class ContestSingleDayMarketInstanceController {
  constructor(
    @repository(IpMarketConfigRepository)
    public ipMarketConfigRepository: IpMarketConfigRepository,
    @repository(IpMarketInstanceRepository)
    public ipMarketInstanceRepository: IpMarketInstanceRepository,
    @repository(IpMarketStatusRepository)
    public ipMarketStatusRepository: IpMarketStatusRepository,
    @repository(IpMarketStatusAuditRepository)
    public ipMarketStatusAuditRepository: IpMarketStatusAuditRepository,
    @repository(IpContestTypeConfigRepository)
    public ipContestTypeConfigRepository: IpContestTypeConfigRepository,
    @repository(IpContestSingleDayInstanceRepository)
    public ipContestSingleDayInstanceRepository: IpContestSingleDayInstanceRepository,
    @repository(IpContestStatusRepository)
    public ipContestStatusRepository: IpContestStatusRepository,
    @repository(IpContestStatusAuditRepository)
    public ipContestStatusAuditRepository: IpContestStatusAuditRepository,
  ) {}

  @post('/create-contest-signle-day-and-market-instances')
  @response(200, {
    description: 'Create Contest single day and market instance',
    content: {
      'application/json': {
        schema: {
          type: 'string',
          example: 'Succeed',
        },
      },
    },
  })
  async create(
    @requestBody(ContestSingleDayAndMarketInstanceSchema)
    variable: ContestSingleDayAndMarketInstance,
  ): Promise<String> {
    let message = '';
    try {
      console.log(variable);
      if (variable?.startDate) {
        const day = moment(variable?.startDate).get('day');
        if (day !== 1)
          throw new Error('failed! because provided date is not monday.');
      }

      const mondayDate = variable?.startDate
        ? moment(variable?.startDate).format('YYYY-MM-DD')
        : getDateOfMondayTwoWeeksFromNow();

      const marketConfigFilter: Filter<IpMarketConfig> = {
        where: {isActive: true},
      };
      const marketConfigs = await this.ipMarketConfigRepository.find(
        marketConfigFilter,
      );

      console.log(mondayDate);

      for (const market of marketConfigs) {
        const contestTypeConfigFilter: Filter<IpContestTypeConfig> = {
          where: {isActive: true, marketId: market.ipid},
        };

        const contestTypeConfigs =
          await this.ipContestTypeConfigRepository.find(
            contestTypeConfigFilter,
          );
        // ContestTypeConfigs we have to create instances
        // 6 Configs would be there
        for (let day = 0; day < 5; day++) {
          const populateDate = moment(mondayDate)
            .add(day, 'day')
            .format('YYYY-MM-DD');
          const isMarketClose = checkMarketClose(populateDate);
          console.log({populateDate, isMarketClose});

          let marketInstance;
          if (!isMarketClose) {
            marketInstance = await this.ipMarketInstanceRepository.create({
              sessionDateTime: populateDate,
              marketConfigId: market.ipid,
            });
          }

          for (const contestTypeConfig of contestTypeConfigs) {
            if (!isMarketClose) {
              const startTime = contestTypeConfig.contestStartTime.split(':');
              const endTime = contestTypeConfig.contestEndTime.split(':');

              const createSingleDayContest = {
                contestTypeConfigId: contestTypeConfig.ipid,
                marketInstanceId: marketInstance?.ipid,
                contestSessionStartTime: moment
                  .utc(populateDate)
                  .set({
                    hour: Number(startTime[0] || 0),
                    minute: Number(startTime[1] || 0),
                    second: 0,
                    millisecond: 0,
                  })
                  .format(),
                contestSessionEndTime: moment
                  .utc(populateDate)
                  .set({
                    hour: Number(endTime[0] || 0),
                    minute: Number(endTime[1] || 0),
                    second: 0,
                    millisecond: 0,
                  })
                  .format(),
              };

              await this.ipContestSingleDayInstanceRepository.create(
                createSingleDayContest,
              );
            }
          }
        }
      }

      message = 'Succeed';
    } catch (err) {
      console.log(err);
      message = 'Failed';
    } finally {
      // eslint-disable-next-line no-unsafe-finally
      return message;
    }
  }
}
