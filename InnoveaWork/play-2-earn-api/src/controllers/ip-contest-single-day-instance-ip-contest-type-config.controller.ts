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
  IpContestTypeConfig,
} from '../models';
import {IpContestSingleDayInstanceRepository} from '../repositories';

export class IpContestSingleDayInstanceIpContestTypeConfigController {
  constructor(
    @repository(IpContestSingleDayInstanceRepository)
    public ipContestSingleDayInstanceRepository: IpContestSingleDayInstanceRepository,
  ) { }

  @get('/contest-single-day-instances/{id}/contest-type-config', {
    responses: {
      '200': {
        description: 'IpContestTypeConfig belonging to IpContestSingleDayInstance',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpContestTypeConfig)},
          },
        },
      },
    },
  })
  async getIpContestTypeConfig(
    @param.path.number('id') id: typeof IpContestSingleDayInstance.prototype.ipid,
  ): Promise<IpContestTypeConfig> {
    return this.ipContestSingleDayInstanceRepository.contestTypeConfig(id);
  }
}
