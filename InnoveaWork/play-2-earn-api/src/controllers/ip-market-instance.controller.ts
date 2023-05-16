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
import {IpMarketInstance} from '../models';
import {IpMarketInstanceRepository} from '../repositories';
import moment from 'moment';

export class IpMarketInstanceController {
  constructor(
    @repository(IpMarketInstanceRepository)
    public ipMarketInstanceRepository: IpMarketInstanceRepository,
  ) {}

  @post('/market-instances')
  @response(200, {
    description: 'IpMarketInstance model instance',
    content: {
      'application/json': {schema: getModelSchemaRef(IpMarketInstance)},
    },
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketInstance, {
            title: 'NewIpMarketInstance',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipMarketInstance: Omit<IpMarketInstance, 'ipid'>,
  ): Promise<IpMarketInstance> {
    // ipMarketInstance.sessionDateTime = moment(ipMarketInstance?.sessionDateTime)
    //   .startOf('day')
    //   .toISOString(true);
    return this.ipMarketInstanceRepository.create(ipMarketInstance);
  }

  @get('/market-instances/count')
  @response(200, {
    description: 'IpMarketInstance model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpMarketInstance) where?: Where<IpMarketInstance>,
  ): Promise<Count> {
    return this.ipMarketInstanceRepository.count(where);
  }

  @get('/market-instances')
  @response(200, {
    description: 'Array of IpMarketInstance model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpMarketInstance, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpMarketInstance) filter?: Filter<IpMarketInstance>,
  ): Promise<IpMarketInstance[]> {
    return this.ipMarketInstanceRepository.find(filter);
  }

  @patch('/market-instances')
  @response(200, {
    description: 'IpMarketInstance PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketInstance, {partial: true}),
        },
      },
    })
    ipMarketInstance: IpMarketInstance,
    @param.where(IpMarketInstance) where?: Where<IpMarketInstance>,
  ): Promise<Count> {
    return this.ipMarketInstanceRepository.updateAll(ipMarketInstance, where);
  }

  @get('/market-instances/{id}')
  @response(200, {
    description: 'IpMarketInstance model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpMarketInstance, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpMarketInstance, {exclude: 'where'})
    filter?: FilterExcludingWhere<IpMarketInstance>,
  ): Promise<IpMarketInstance> {
    return this.ipMarketInstanceRepository.findById(id, filter);
  }

  @patch('/market-instances/{id}')
  @response(204, {
    description: 'IpMarketInstance PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketInstance, {partial: true}),
        },
      },
    })
    ipMarketInstance: IpMarketInstance,
  ): Promise<void> {
    await this.ipMarketInstanceRepository.updateById(id, ipMarketInstance);
  }

  @put('/market-instances/{id}')
  @response(204, {
    description: 'IpMarketInstance PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipMarketInstance: IpMarketInstance,
  ): Promise<void> {
    await this.ipMarketInstanceRepository.replaceById(id, ipMarketInstance);
  }

  @del('/market-instances/{id}')
  @response(204, {
    description: 'IpMarketInstance DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipMarketInstanceRepository.deleteById(id);
  }
}
