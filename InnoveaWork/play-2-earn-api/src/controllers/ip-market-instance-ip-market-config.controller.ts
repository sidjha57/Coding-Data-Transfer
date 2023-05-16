import {
  repository,
} from '@loopback/repository';
import {
  param,
  get,
  getModelSchemaRef,
} from '@loopback/rest';
import {
  IpMarketInstance,
  IpMarketConfig,
} from '../models';
import {IpMarketInstanceRepository} from '../repositories';

export class IpMarketInstanceIpMarketConfigController {
  constructor(
    @repository(IpMarketInstanceRepository)
    public ipMarketInstanceRepository: IpMarketInstanceRepository,
  ) { }

  @get('/market-instances/{id}/market-config', {
    responses: {
      '200': {
        description: 'IpMarketConfig belonging to IpMarketInstance',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpMarketConfig)},
          },
        },
      },
    },
  })
  async getIpMarketConfig(
    @param.path.number('id') id: typeof IpMarketInstance.prototype.ipid,
  ): Promise<IpMarketConfig> {
    return this.ipMarketInstanceRepository.marketConfig(id);
  }
}
