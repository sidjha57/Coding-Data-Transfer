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
import {IpContestType} from '../models';
import {IpContestTypeRepository} from '../repositories';

export class IpContestTypeController {
  constructor(
    @repository(IpContestTypeRepository)
    public ipContestTypeRepository : IpContestTypeRepository,
  ) {}

  @post('/contest-types')
  @response(200, {
    description: 'IpContestType model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpContestType)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestType, {
            title: 'NewIpContestType',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipContestType: Omit<IpContestType, 'ipid'>,
  ): Promise<IpContestType> {
    return this.ipContestTypeRepository.create(ipContestType);
  }

  @get('/contest-types/count')
  @response(200, {
    description: 'IpContestType model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpContestType) where?: Where<IpContestType>,
  ): Promise<Count> {
    return this.ipContestTypeRepository.count(where);
  }

  @get('/contest-types')
  @response(200, {
    description: 'Array of IpContestType model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpContestType, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpContestType) filter?: Filter<IpContestType>,
  ): Promise<IpContestType[]> {
    return this.ipContestTypeRepository.find(filter);
  }

  @patch('/contest-types')
  @response(200, {
    description: 'IpContestType PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestType, {partial: true}),
        },
      },
    })
    ipContestType: IpContestType,
    @param.where(IpContestType) where?: Where<IpContestType>,
  ): Promise<Count> {
    return this.ipContestTypeRepository.updateAll(ipContestType, where);
  }

  @get('/contest-types/{id}')
  @response(200, {
    description: 'IpContestType model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpContestType, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpContestType, {exclude: 'where'}) filter?: FilterExcludingWhere<IpContestType>
  ): Promise<IpContestType> {
    return this.ipContestTypeRepository.findById(id, filter);
  }

  @patch('/contest-types/{id}')
  @response(204, {
    description: 'IpContestType PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestType, {partial: true}),
        },
      },
    })
    ipContestType: IpContestType,
  ): Promise<void> {
    await this.ipContestTypeRepository.updateById(id, ipContestType);
  }

  @put('/contest-types/{id}')
  @response(204, {
    description: 'IpContestType PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipContestType: IpContestType,
  ): Promise<void> {
    await this.ipContestTypeRepository.replaceById(id, ipContestType);
  }

  @del('/contest-types/{id}')
  @response(204, {
    description: 'IpContestType DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipContestTypeRepository.deleteById(id);
  }
}
