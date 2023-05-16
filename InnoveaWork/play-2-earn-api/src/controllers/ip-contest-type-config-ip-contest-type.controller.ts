import {
  repository,
} from '@loopback/repository';
import {
  param,
  get,
  getModelSchemaRef,
} from '@loopback/rest';
import {
  IpContestTypeConfig,
  IpContestType,
} from '../models';
import {IpContestTypeConfigRepository} from '../repositories';

export class IpContestTypeConfigIpContestTypeController {
  constructor(
    @repository(IpContestTypeConfigRepository)
    public ipContestTypeConfigRepository: IpContestTypeConfigRepository,
  ) { }

  @get('/contest-type-configs/{id}/contest-type', {
    responses: {
      '200': {
        description: 'IpContestType belonging to IpContestTypeConfig',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpContestType)},
          },
        },
      },
    },
  })
  async getIpContestType(
    @param.path.number('id') id: typeof IpContestTypeConfig.prototype.ipid,
  ): Promise<IpContestType> {
    return this.ipContestTypeConfigRepository.contestType(id);
  }
}
