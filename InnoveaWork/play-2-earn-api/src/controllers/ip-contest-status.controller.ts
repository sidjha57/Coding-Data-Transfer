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
import {IpContestStatus} from '../models';
import {IpContestStatusRepository} from '../repositories';

export class IpContestStatusController {
  constructor(
    @repository(IpContestStatusRepository)
    public ipContestStatusRepository : IpContestStatusRepository,
  ) {}

  @post('/contest-statuses')
  @response(200, {
    description: 'IpContestStatus model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpContestStatus)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestStatus, {
            title: 'NewIpContestStatus',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipContestStatus: Omit<IpContestStatus, 'ipid'>,
  ): Promise<IpContestStatus> {
    return this.ipContestStatusRepository.create(ipContestStatus);
  }

  @get('/contest-statuses/count')
  @response(200, {
    description: 'IpContestStatus model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpContestStatus) where?: Where<IpContestStatus>,
  ): Promise<Count> {
    return this.ipContestStatusRepository.count(where);
  }

  @get('/contest-statuses')
  @response(200, {
    description: 'Array of IpContestStatus model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpContestStatus, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpContestStatus) filter?: Filter<IpContestStatus>,
  ): Promise<IpContestStatus[]> {
    return this.ipContestStatusRepository.find(filter);
  }

  @patch('/contest-statuses')
  @response(200, {
    description: 'IpContestStatus PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestStatus, {partial: true}),
        },
      },
    })
    ipContestStatus: IpContestStatus,
    @param.where(IpContestStatus) where?: Where<IpContestStatus>,
  ): Promise<Count> {
    return this.ipContestStatusRepository.updateAll(ipContestStatus, where);
  }

  @get('/contest-statuses/{id}')
  @response(200, {
    description: 'IpContestStatus model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpContestStatus, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpContestStatus, {exclude: 'where'}) filter?: FilterExcludingWhere<IpContestStatus>
  ): Promise<IpContestStatus> {
    return this.ipContestStatusRepository.findById(id, filter);
  }

  @patch('/contest-statuses/{id}')
  @response(204, {
    description: 'IpContestStatus PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestStatus, {partial: true}),
        },
      },
    })
    ipContestStatus: IpContestStatus,
  ): Promise<void> {
    await this.ipContestStatusRepository.updateById(id, ipContestStatus);
  }

  @put('/contest-statuses/{id}')
  @response(204, {
    description: 'IpContestStatus PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipContestStatus: IpContestStatus,
  ): Promise<void> {
    await this.ipContestStatusRepository.replaceById(id, ipContestStatus);
  }

  @del('/contest-statuses/{id}')
  @response(204, {
    description: 'IpContestStatus DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipContestStatusRepository.deleteById(id);
  }
}
