import {
  Count,
  CountSchema,
  Filter,
  repository,
  Where,
} from '@loopback/repository';
import {
  del,
  get,
  getModelSchemaRef,
  getWhereSchemaFor,
  param,
  patch,
  post,
  requestBody,
} from '@loopback/rest';
import {
  IpCatalog,
  IpInstrumentConfig,
} from '../models';
import {IpCatalogRepository} from '../repositories';

export class IpCatalogIpInstrumentConfigController {
  constructor(
    @repository(IpCatalogRepository) protected ipCatalogRepository: IpCatalogRepository,
  ) { }

  @get('/catalogs/{id}/instrument-configs', {
    responses: {
      '200': {
        description: 'Array of IpCatalog has many IpInstrumentConfig',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpInstrumentConfig)},
          },
        },
      },
    },
  })
  async find(
    @param.path.number('id') id: number,
    @param.query.object('filter') filter?: Filter<IpInstrumentConfig>,
  ): Promise<IpInstrumentConfig[]> {
    return this.ipCatalogRepository.InstrumentConfig(id).find(filter);
  }

  @post('/catalogs/{id}/instrument-configs', {
    responses: {
      '200': {
        description: 'IpCatalog model instance',
        content: {'application/json': {schema: getModelSchemaRef(IpInstrumentConfig)}},
      },
    },
  })
  async create(
    @param.path.number('id') id: typeof IpCatalog.prototype.ipid,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpInstrumentConfig, {
            title: 'NewIpInstrumentConfigInIpCatalog',
            exclude: ['ipid'],
            optional: ['catalogId']
          }),
        },
      },
    }) ipInstrumentConfig: Omit<IpInstrumentConfig, 'ipid'>,
  ): Promise<IpInstrumentConfig> {
    return this.ipCatalogRepository.InstrumentConfig(id).create(ipInstrumentConfig);
  }

  @patch('/catalogs/{id}/instrument-configs', {
    responses: {
      '200': {
        description: 'IpCatalog.IpInstrumentConfig PATCH success count',
        content: {'application/json': {schema: CountSchema}},
      },
    },
  })
  async patch(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpInstrumentConfig, {partial: true}),
        },
      },
    })
    ipInstrumentConfig: Partial<IpInstrumentConfig>,
    @param.query.object('where', getWhereSchemaFor(IpInstrumentConfig)) where?: Where<IpInstrumentConfig>,
  ): Promise<Count> {
    return this.ipCatalogRepository.InstrumentConfig(id).patch(ipInstrumentConfig, where);
  }

  @del('/catalogs/{id}/instrument-configs', {
    responses: {
      '200': {
        description: 'IpCatalog.IpInstrumentConfig DELETE success count',
        content: {'application/json': {schema: CountSchema}},
      },
    },
  })
  async delete(
    @param.path.number('id') id: number,
    @param.query.object('where', getWhereSchemaFor(IpInstrumentConfig)) where?: Where<IpInstrumentConfig>,
  ): Promise<Count> {
    return this.ipCatalogRepository.InstrumentConfig(id).delete(where);
  }
}
