import {
  repository,
} from '@loopback/repository';
import {
  param,
  get,
  getModelSchemaRef,
} from '@loopback/rest';
import {
  IpInstrumentWeek,
  IpInstrumentConfig,
} from '../models';
import {IpInstrumentWeekRepository} from '../repositories';

export class IpInstrumentWeekIpInstrumentConfigController {
  constructor(
    @repository(IpInstrumentWeekRepository)
    public ipInstrumentWeekRepository: IpInstrumentWeekRepository,
  ) { }

  @get('/ip-instrument-weeks/{id}/ip-instrument-config', {
    responses: {
      '200': {
        description: 'IpInstrumentConfig belonging to IpInstrumentWeek',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpInstrumentConfig)},
          },
        },
      },
    },
  })
  async getIpInstrumentConfig(
    @param.path.number('id') id: typeof IpInstrumentWeek.prototype.ipid,
  ): Promise<IpInstrumentConfig> {
    return this.ipInstrumentWeekRepository.instrument(id);
  }
}
