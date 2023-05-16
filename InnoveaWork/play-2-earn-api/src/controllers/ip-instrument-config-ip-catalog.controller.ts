import {
  repository,
} from '@loopback/repository';
import {
  param,
  get,
  getModelSchemaRef,
} from '@loopback/rest';
import {
  IpInstrumentConfig,
  IpCatalog,
} from '../models';
import {IpInstrumentConfigRepository} from '../repositories';

export class IpInstrumentConfigIpCatalogController {
  constructor(
    @repository(IpInstrumentConfigRepository)
    public ipInstrumentConfigRepository: IpInstrumentConfigRepository,
  ) { }

  @get('/instrument-configs/{id}/catalog', {
    responses: {
      '200': {
        description: 'IpCatalog belonging to IpInstrumentConfig',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpCatalog)},
          },
        },
      },
    },
  })
  async getIpCatalog(
    @param.path.number('id') id: typeof IpInstrumentConfig.prototype.ipid,
  ): Promise<IpCatalog> {
    return this.ipInstrumentConfigRepository.catalog(id);
  }
}
