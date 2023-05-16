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
  IpMarketConfig,
  IpMarketInstance,
} from '../models';
import {IpMarketConfigRepository} from '../repositories';

export class IpMarketConfigIpMarketInstanceController {
  constructor(
    @repository(IpMarketConfigRepository) protected ipMarketConfigRepository: IpMarketConfigRepository,
  ) { }

  @get('/market-configs/{id}/market-instances', {
    responses: {
      '200': {
        description: 'Array of IpMarketConfig has many IpMarketInstance',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpMarketInstance)},
          },
        },
      },
    },
  })
  async find(
    @param.path.number('id') id: number,
    @param.query.object('filter') filter?: Filter<IpMarketInstance>,
  ): Promise<IpMarketInstance[]> {
    return this.ipMarketConfigRepository.marketInstances(id).find(filter);
  }

  @post('/market-configs/{id}/market-instances', {
    responses: {
      '200': {
        description: 'IpMarketConfig model instance',
        content: {'application/json': {schema: getModelSchemaRef(IpMarketInstance)}},
      },
    },
  })
  async create(
    @param.path.number('id') id: typeof IpMarketConfig.prototype.ipid,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketInstance, {
            title: 'NewIpMarketInstanceInIpMarketConfig',
            exclude: ['ipid'],
            optional: ['marketConfigId']
          }),
        },
      },
    }) ipMarketInstance: Omit<IpMarketInstance, 'ipid'>,
  ): Promise<IpMarketInstance> {
    return this.ipMarketConfigRepository.marketInstances(id).create(ipMarketInstance);
  }

  @patch('/market-configs/{id}/market-instances', {
    responses: {
      '200': {
        description: 'IpMarketConfig.IpMarketInstance PATCH success count',
        content: {'application/json': {schema: CountSchema}},
      },
    },
  })
  async patch(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketInstance, {partial: true}),
        },
      },
    })
    ipMarketInstance: Partial<IpMarketInstance>,
    @param.query.object('where', getWhereSchemaFor(IpMarketInstance)) where?: Where<IpMarketInstance>,
  ): Promise<Count> {
    return this.ipMarketConfigRepository.marketInstances(id).patch(ipMarketInstance, where);
  }

  @del('/market-configs/{id}/market-instances', {
    responses: {
      '200': {
        description: 'IpMarketConfig.IpMarketInstance DELETE success count',
        content: {'application/json': {schema: CountSchema}},
      },
    },
  })
  async delete(
    @param.path.number('id') id: number,
    @param.query.object('where', getWhereSchemaFor(IpMarketInstance)) where?: Where<IpMarketInstance>,
  ): Promise<Count> {
    return this.ipMarketConfigRepository.marketInstances(id).delete(where);
  }
}
