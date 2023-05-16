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
import {IpContestSingleDayInstance} from '../models';
import {IpContestSingleDayInstanceRepository} from '../repositories';

export class IpContestSingleDayInstanceController {
  constructor(
    @repository(IpContestSingleDayInstanceRepository)
    public ipContestSingleDayInstanceRepository : IpContestSingleDayInstanceRepository,
  ) {}

  @post('/contest-single-day-instances')
  @response(200, {
    description: 'IpContestSingleDayInstance model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpContestSingleDayInstance)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestSingleDayInstance, {
            title: 'NewIpContestSingleDayInstance',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipContestSingleDayInstance: Omit<IpContestSingleDayInstance, 'ipid'>,
  ): Promise<IpContestSingleDayInstance> {
    return this.ipContestSingleDayInstanceRepository.create(ipContestSingleDayInstance);
  }

  @get('/contest-single-day-instances/count')
  @response(200, {
    description: 'IpContestSingleDayInstance model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpContestSingleDayInstance) where?: Where<IpContestSingleDayInstance>,
  ): Promise<Count> {
    return this.ipContestSingleDayInstanceRepository.count(where);
  }

  @get('/contest-single-day-instances')
  @response(200, {
    description: 'Array of IpContestSingleDayInstance model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpContestSingleDayInstance, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpContestSingleDayInstance) filter?: Filter<IpContestSingleDayInstance>,
  ): Promise<IpContestSingleDayInstance[]> {
    return this.ipContestSingleDayInstanceRepository.find(filter);
  }

  @patch('/contest-single-day-instances')
  @response(200, {
    description: 'IpContestSingleDayInstance PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestSingleDayInstance, {partial: true}),
        },
      },
    })
    ipContestSingleDayInstance: IpContestSingleDayInstance,
    @param.where(IpContestSingleDayInstance) where?: Where<IpContestSingleDayInstance>,
  ): Promise<Count> {
    return this.ipContestSingleDayInstanceRepository.updateAll(ipContestSingleDayInstance, where);
  }

  @get('/contest-single-day-instances/{id}')
  @response(200, {
    description: 'IpContestSingleDayInstance model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpContestSingleDayInstance, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpContestSingleDayInstance, {exclude: 'where'}) filter?: FilterExcludingWhere<IpContestSingleDayInstance>
  ): Promise<IpContestSingleDayInstance> {
    return this.ipContestSingleDayInstanceRepository.findById(id, filter);
  }

  @patch('/contest-single-day-instances/{id}')
  @response(204, {
    description: 'IpContestSingleDayInstance PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestSingleDayInstance, {partial: true}),
        },
      },
    })
    ipContestSingleDayInstance: IpContestSingleDayInstance,
  ): Promise<void> {
    await this.ipContestSingleDayInstanceRepository.updateById(id, ipContestSingleDayInstance);
  }

  @put('/contest-single-day-instances/{id}')
  @response(204, {
    description: 'IpContestSingleDayInstance PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipContestSingleDayInstance: IpContestSingleDayInstance,
  ): Promise<void> {
    await this.ipContestSingleDayInstanceRepository.replaceById(id, ipContestSingleDayInstance);
  }

  @del('/contest-single-day-instances/{id}')
  @response(204, {
    description: 'IpContestSingleDayInstance DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipContestSingleDayInstanceRepository.deleteById(id);
  }
}
