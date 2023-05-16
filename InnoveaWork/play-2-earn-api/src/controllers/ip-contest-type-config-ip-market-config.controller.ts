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
  IpMarketConfig,
} from '../models';
import {IpContestTypeConfigRepository} from '../repositories';

export class IpContestTypeConfigIpMarketConfigController {
  constructor(
    @repository(IpContestTypeConfigRepository)
    public ipContestTypeConfigRepository: IpContestTypeConfigRepository,
  ) { }

  @get('/contest-type-configs/{id}/market-config', {
    responses: {
      '200': {
        description: 'IpMarketConfig belonging to IpContestTypeConfig',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpMarketConfig)},
          },
        },
      },
    },
  })
  async getIpMarketConfig(
    @param.path.number('id') id: typeof IpContestTypeConfig.prototype.ipid,
  ): Promise<IpMarketConfig> {
    return this.ipContestTypeConfigRepository.market(id);
  }
}
