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
import {IpMarketStatus} from '../models';
import {IpMarketStatusRepository} from '../repositories';

export class IpMarketStatusController {
  constructor(
    @repository(IpMarketStatusRepository)
    public ipMarketStatusRepository : IpMarketStatusRepository,
  ) {}

  @post('/market-statuses')
  @response(200, {
    description: 'IpMarketStatus model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpMarketStatus)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketStatus, {
            title: 'NewIpMarketStatus',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipMarketStatus: Omit<IpMarketStatus, 'ipid'>,
  ): Promise<IpMarketStatus> {
    return this.ipMarketStatusRepository.create(ipMarketStatus);
  }

  @get('/market-statuses/count')
  @response(200, {
    description: 'IpMarketStatus model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpMarketStatus) where?: Where<IpMarketStatus>,
  ): Promise<Count> {
    return this.ipMarketStatusRepository.count(where);
  }

  @get('/market-statuses')
  @response(200, {
    description: 'Array of IpMarketStatus model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpMarketStatus, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpMarketStatus) filter?: Filter<IpMarketStatus>,
  ): Promise<IpMarketStatus[]> {
    return this.ipMarketStatusRepository.find(filter);
  }

  @patch('/market-statuses')
  @response(200, {
    description: 'IpMarketStatus PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketStatus, {partial: true}),
        },
      },
    })
    ipMarketStatus: IpMarketStatus,
    @param.where(IpMarketStatus) where?: Where<IpMarketStatus>,
  ): Promise<Count> {
    return this.ipMarketStatusRepository.updateAll(ipMarketStatus, where);
  }

  @get('/market-statuses/{id}')
  @response(200, {
    description: 'IpMarketStatus model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpMarketStatus, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpMarketStatus, {exclude: 'where'}) filter?: FilterExcludingWhere<IpMarketStatus>
  ): Promise<IpMarketStatus> {
    return this.ipMarketStatusRepository.findById(id, filter);
  }

  @patch('/market-statuses/{id}')
  @response(204, {
    description: 'IpMarketStatus PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketStatus, {partial: true}),
        },
      },
    })
    ipMarketStatus: IpMarketStatus,
  ): Promise<void> {
    await this.ipMarketStatusRepository.updateById(id, ipMarketStatus);
  }

  @put('/market-statuses/{id}')
  @response(204, {
    description: 'IpMarketStatus PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipMarketStatus: IpMarketStatus,
  ): Promise<void> {
    await this.ipMarketStatusRepository.replaceById(id, ipMarketStatus);
  }

  @del('/market-statuses/{id}')
  @response(204, {
    description: 'IpMarketStatus DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipMarketStatusRepository.deleteById(id);
  }
}
