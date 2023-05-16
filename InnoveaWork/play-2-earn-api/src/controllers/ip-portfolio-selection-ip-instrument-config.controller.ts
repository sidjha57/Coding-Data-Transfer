import {
  repository,
} from '@loopback/repository';
import {
  param,
  get,
  getModelSchemaRef,
} from '@loopback/rest';
import {
  IpPortfolioSelection,
  IpInstrumentConfig,
} from '../models';
import {IpPortfolioSelectionRepository} from '../repositories';

export class IpPortfolioSelectionIpInstrumentConfigController {
  constructor(
    @repository(IpPortfolioSelectionRepository)
    public ipPortfolioSelectionRepository: IpPortfolioSelectionRepository,
  ) { }

  @get('/portfolio-selections/{id}/instrument-config', {
    responses: {
      '200': {
        description: 'IpInstrumentConfig belonging to IpPortfolioSelection',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpInstrumentConfig)},
          },
        },
      },
    },
  })
  async getIpInstrumentConfig(
    @param.path.number('id') id: typeof IpPortfolioSelection.prototype.ipid,
  ): Promise<IpInstrumentConfig> {
    return this.ipPortfolioSelectionRepository.instrument(id);
  }
}
