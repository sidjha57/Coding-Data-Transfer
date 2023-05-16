import {
  repository,
} from '@loopback/repository';
import {
  param,
  get,
  getModelSchemaRef,
} from '@loopback/rest';
import {
  IpInstrumentPrice,
  IpInstrumentConfig,
} from '../models';
import {IpInstrumentPriceRepository} from '../repositories';

export class IpInstrumentPriceIpInstrumentConfigController {
  constructor(
    @repository(IpInstrumentPriceRepository)
    public ipInstrumentPriceRepository: IpInstrumentPriceRepository,
  ) { }

  @get('/instrument-prices/{id}/instrument-config', {
    responses: {
      '200': {
        description: 'IpInstrumentConfig belonging to IpInstrumentPrice',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpInstrumentConfig)},
          },
        },
      },
    },
  })
  async getIpInstrumentConfig(
    @param.path.number('id') id: typeof IpInstrumentPrice.prototype.ipid,
  ): Promise<IpInstrumentConfig> {
    return this.ipInstrumentPriceRepository.instrument(id);
  }
}
