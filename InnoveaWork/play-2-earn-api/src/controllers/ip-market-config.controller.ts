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
import {IpMarketConfig} from '../models';
import {IpMarketConfigRepository} from '../repositories';

export class IpMarketConfigController {
  constructor(
    @repository(IpMarketConfigRepository)
    public ipMarketConfigRepository : IpMarketConfigRepository,
  ) {}

  @post('/market-configs')
  @response(200, {
    description: 'IpMarketConfig model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpMarketConfig)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketConfig, {
            title: 'NewIpMarketConfig',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipMarketConfig: Omit<IpMarketConfig, 'ipid'>,
  ): Promise<IpMarketConfig> {
    return this.ipMarketConfigRepository.create(ipMarketConfig);
  }

  @get('/market-configs/count')
  @response(200, {
    description: 'IpMarketConfig model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpMarketConfig) where?: Where<IpMarketConfig>,
  ): Promise<Count> {
    return this.ipMarketConfigRepository.count(where);
  }

  @get('/market-configs')
  @response(200, {
    description: 'Array of IpMarketConfig model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpMarketConfig, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpMarketConfig) filter?: Filter<IpMarketConfig>,
  ): Promise<IpMarketConfig[]> {
    return this.ipMarketConfigRepository.find(filter);
  }

  @patch('/market-configs')
  @response(200, {
    description: 'IpMarketConfig PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketConfig, {partial: true}),
        },
      },
    })
    ipMarketConfig: IpMarketConfig,
    @param.where(IpMarketConfig) where?: Where<IpMarketConfig>,
  ): Promise<Count> {
    return this.ipMarketConfigRepository.updateAll(ipMarketConfig, where);
  }

  @get('/market-configs/{id}')
  @response(200, {
    description: 'IpMarketConfig model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpMarketConfig, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpMarketConfig, {exclude: 'where'}) filter?: FilterExcludingWhere<IpMarketConfig>
  ): Promise<IpMarketConfig> {
    return this.ipMarketConfigRepository.findById(id, filter);
  }

  @patch('/market-configs/{id}')
  @response(204, {
    description: 'IpMarketConfig PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketConfig, {partial: true}),
        },
      },
    })
    ipMarketConfig: IpMarketConfig,
  ): Promise<void> {
    await this.ipMarketConfigRepository.updateById(id, ipMarketConfig);
  }

  @put('/market-configs/{id}')
  @response(204, {
    description: 'IpMarketConfig PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipMarketConfig: IpMarketConfig,
  ): Promise<void> {
    await this.ipMarketConfigRepository.replaceById(id, ipMarketConfig);
  }

  @del('/market-configs/{id}')
  @response(204, {
    description: 'IpMarketConfig DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipMarketConfigRepository.deleteById(id);
  }
}
