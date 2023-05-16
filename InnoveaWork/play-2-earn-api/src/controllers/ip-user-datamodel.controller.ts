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
import {IpUserDatamodel} from '../models';
import {IpUserDatamodelRepository} from '../repositories';

export class IpUserDatamodelController {
  constructor(
    @repository(IpUserDatamodelRepository)
    public ipUserDatamodelRepository : IpUserDatamodelRepository,
  ) {}

  @post('/user-datamodel')
  @response(200, {
    description: 'IpUserDatamodel model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpUserDatamodel)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpUserDatamodel, {
            title: 'NewIpUserDatamodel',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipUserDatamodel: Omit<IpUserDatamodel, 'ipid'>,
  ): Promise<IpUserDatamodel> {
    return this.ipUserDatamodelRepository.create(ipUserDatamodel);
  }

  @get('/user-datamodel/count')
  @response(200, {
    description: 'IpUserDatamodel model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpUserDatamodel) where?: Where<IpUserDatamodel>,
  ): Promise<Count> {
    return this.ipUserDatamodelRepository.count(where);
  }

  @get('/user-datamodel')
  @response(200, {
    description: 'Array of IpUserDatamodel model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpUserDatamodel, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpUserDatamodel) filter?: Filter<IpUserDatamodel>,
  ): Promise<IpUserDatamodel[]> {
    return this.ipUserDatamodelRepository.find(filter);
  }

  @patch('/user-datamodel')
  @response(200, {
    description: 'IpUserDatamodel PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpUserDatamodel, {partial: true}),
        },
      },
    })
    ipUserDatamodel: IpUserDatamodel,
    @param.where(IpUserDatamodel) where?: Where<IpUserDatamodel>,
  ): Promise<Count> {
    return this.ipUserDatamodelRepository.updateAll(ipUserDatamodel, where);
  }

  @get('/user-datamodel/{id}')
  @response(200, {
    description: 'IpUserDatamodel model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpUserDatamodel, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpUserDatamodel, {exclude: 'where'}) filter?: FilterExcludingWhere<IpUserDatamodel>
  ): Promise<IpUserDatamodel> {
    return this.ipUserDatamodelRepository.findById(id, filter);
  }

  @patch('/user-datamodel/{id}')
  @response(204, {
    description: 'IpUserDatamodel PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpUserDatamodel, {partial: true}),
        },
      },
    })
    ipUserDatamodel: IpUserDatamodel,
  ): Promise<void> {
    await this.ipUserDatamodelRepository.updateById(id, ipUserDatamodel);
  }

  @put('/user-datamodel/{id}')
  @response(204, {
    description: 'IpUserDatamodel PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipUserDatamodel: IpUserDatamodel,
  ): Promise<void> {
    await this.ipUserDatamodelRepository.replaceById(id, ipUserDatamodel);
  }

  @del('/user-datamodel/{id}')
  @response(204, {
    description: 'IpUserDatamodel DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipUserDatamodelRepository.deleteById(id);
  }
}
