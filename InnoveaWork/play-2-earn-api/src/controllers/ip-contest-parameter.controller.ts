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
import {IpContestParameter} from '../models';
import {IpContestParameterRepository} from '../repositories';

export class IpContestParameterController {
  constructor(
    @repository(IpContestParameterRepository)
    public ipContestParameterRepository : IpContestParameterRepository,
  ) {}

  @post('/contest-parameters')
  @response(200, {
    description: 'IpContestParameter model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpContestParameter)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestParameter, {
            title: 'NewIpContestParameter',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipContestParameter: Omit<IpContestParameter, 'ipid'>,
  ): Promise<IpContestParameter> {
    return this.ipContestParameterRepository.create(ipContestParameter);
  }

  @get('/contest-parameters/count')
  @response(200, {
    description: 'IpContestParameter model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpContestParameter) where?: Where<IpContestParameter>,
  ): Promise<Count> {
    return this.ipContestParameterRepository.count(where);
  }

  @get('/contest-parameters')
  @response(200, {
    description: 'Array of IpContestParameter model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpContestParameter, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpContestParameter) filter?: Filter<IpContestParameter>,
  ): Promise<IpContestParameter[]> {
    return this.ipContestParameterRepository.find(filter);
  }

  @patch('/contest-parameters')
  @response(200, {
    description: 'IpContestParameter PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestParameter, {partial: true}),
        },
      },
    })
    ipContestParameter: IpContestParameter,
    @param.where(IpContestParameter) where?: Where<IpContestParameter>,
  ): Promise<Count> {
    return this.ipContestParameterRepository.updateAll(ipContestParameter, where);
  }

  @get('/contest-parameters/{id}')
  @response(200, {
    description: 'IpContestParameter model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpContestParameter, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpContestParameter, {exclude: 'where'}) filter?: FilterExcludingWhere<IpContestParameter>
  ): Promise<IpContestParameter> {
    return this.ipContestParameterRepository.findById(id, filter);
  }

  @patch('/contest-parameters/{id}')
  @response(204, {
    description: 'IpContestParameter PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestParameter, {partial: true}),
        },
      },
    })
    ipContestParameter: IpContestParameter,
  ): Promise<void> {
    await this.ipContestParameterRepository.updateById(id, ipContestParameter);
  }

  @put('/contest-parameters/{id}')
  @response(204, {
    description: 'IpContestParameter PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipContestParameter: IpContestParameter,
  ): Promise<void> {
    await this.ipContestParameterRepository.replaceById(id, ipContestParameter);
  }

  @del('/contest-parameters/{id}')
  @response(204, {
    description: 'IpContestParameter DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipContestParameterRepository.deleteById(id);
  }
}
