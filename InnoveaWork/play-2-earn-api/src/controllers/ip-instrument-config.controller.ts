import {
  Count,
  CountSchema,
  Filter,
  FilterExcludingWhere,
  repository,
  Where,
} from '@loopback/repository';
import {
  post,
  param,
  get,
  getModelSchemaRef,
  patch,
  put,
  del,
  requestBody,
  response,
} from '@loopback/rest';
import {IpInstrumentConfig} from '../models';
import {IpInstrumentConfigRepository} from '../repositories';

export class IpInstrumentConfigController {
  constructor(
    @repository(IpInstrumentConfigRepository)
    public ipInstrumentConfigRepository : IpInstrumentConfigRepository,
  ) {}

  @post('/instrument-configs')
  @response(200, {
    description: 'IpInstrumentConfig model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpInstrumentConfig)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpInstrumentConfig, {
            title: 'NewIpInstrumentConfig',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipInstrumentConfig: Omit<IpInstrumentConfig, 'ipid'>,
  ): Promise<IpInstrumentConfig> {
    return this.ipInstrumentConfigRepository.create(ipInstrumentConfig);
  }

  @get('/instrument-configs/count')
  @response(200, {
    description: 'IpInstrumentConfig model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpInstrumentConfig) where?: Where<IpInstrumentConfig>,
  ): Promise<Count> {
    return this.ipInstrumentConfigRepository.count(where);
  }

  @get('/instrument-configs')
  @response(200, {
    description: 'Array of IpInstrumentConfig model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpInstrumentConfig, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpInstrumentConfig) filter?: Filter<IpInstrumentConfig>,
  ): Promise<IpInstrumentConfig[]> {
    return this.ipInstrumentConfigRepository.find(filter);
  }

  @patch('/instrument-configs')
  @response(200, {
    description: 'IpInstrumentConfig PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpInstrumentConfig, {partial: true}),
        },
      },
    })
    ipInstrumentConfig: IpInstrumentConfig,
    @param.where(IpInstrumentConfig) where?: Where<IpInstrumentConfig>,
  ): Promise<Count> {
    return this.ipInstrumentConfigRepository.updateAll(ipInstrumentConfig, where);
  }

  @get('/instrument-configs/{id}')
  @response(200, {
    description: 'IpInstrumentConfig model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpInstrumentConfig, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpInstrumentConfig, {exclude: 'where'}) filter?: FilterExcludingWhere<IpInstrumentConfig>
  ): Promise<IpInstrumentConfig> {
    return this.ipInstrumentConfigRepository.findById(id, filter);
  }

  @patch('/instrument-configs/{id}')
  @response(204, {
    description: 'IpInstrumentConfig PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpInstrumentConfig, {partial: true}),
        },
      },
    })
    ipInstrumentConfig: IpInstrumentConfig,
  ): Promise<void> {
    await this.ipInstrumentConfigRepository.updateById(id, ipInstrumentConfig);
  }

  @put('/instrument-configs/{id}')
  @response(204, {
    description: 'IpInstrumentConfig PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipInstrumentConfig: IpInstrumentConfig,
  ): Promise<void> {
    await this.ipInstrumentConfigRepository.replaceById(id, ipInstrumentConfig);
  }

  @del('/instrument-configs/{id}')
  @response(204, {
    description: 'IpInstrumentConfig DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipInstrumentConfigRepository.deleteById(id);
  }
}
