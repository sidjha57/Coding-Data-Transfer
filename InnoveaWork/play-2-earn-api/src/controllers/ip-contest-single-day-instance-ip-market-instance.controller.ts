import {
  repository,
} from '@loopback/repository';
import {
  param,
  get,
  getModelSchemaRef,
} from '@loopback/rest';
import {
  IpContestSingleDayInstance,
  IpMarketInstance,
} from '../models';
import {IpContestSingleDayInstanceRepository} from '../repositories';

export class IpContestSingleDayInstanceIpMarketInstanceController {
  constructor(
    @repository(IpContestSingleDayInstanceRepository)
    public ipContestSingleDayInstanceRepository: IpContestSingleDayInstanceRepository,
  ) { }

  @get('/contest-single-day-instances/{id}/market-instance', {
    responses: {
      '200': {
        description: 'IpMarketInstance belonging to IpContestSingleDayInstance',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpMarketInstance)},
          },
        },
      },
    },
  })
  async getIpMarketInstance(
    @param.path.number('id') id: typeof IpContestSingleDayInstance.prototype.ipid,
  ): Promise<IpMarketInstance> {
    return this.ipContestSingleDayInstanceRepository.marketInstance(id);
  }
}
