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
import {IpCatalog} from '../models';
import {IpCatalogRepository} from '../repositories';

export class IpCatalogController {
  constructor(
    @repository(IpCatalogRepository)
    public ipCatalogRepository : IpCatalogRepository,
  ) {}

  @post('/catalogs')
  @response(200, {
    description: 'IpCatalog model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpCatalog)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpCatalog, {
            title: 'NewIpCatalog',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipCatalog: Omit<IpCatalog, 'ipid'>,
  ): Promise<IpCatalog> {
    return this.ipCatalogRepository.create(ipCatalog);
  }

  @get('/catalogs/count')
  @response(200, {
    description: 'IpCatalog model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpCatalog) where?: Where<IpCatalog>,
  ): Promise<Count> {
    return this.ipCatalogRepository.count(where);
  }

  @get('/catalogs')
  @response(200, {
    description: 'Array of IpCatalog model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpCatalog, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpCatalog) filter?: Filter<IpCatalog>,
  ): Promise<IpCatalog[]> {
    return this.ipCatalogRepository.find(filter);
  }

  @patch('/catalogs')
  @response(200, {
    description: 'IpCatalog PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpCatalog, {partial: true}),
        },
      },
    })
    ipCatalog: IpCatalog,
    @param.where(IpCatalog) where?: Where<IpCatalog>,
  ): Promise<Count> {
    return this.ipCatalogRepository.updateAll(ipCatalog, where);
  }

  @get('/catalogs/{id}')
  @response(200, {
    description: 'IpCatalog model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpCatalog, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpCatalog, {exclude: 'where'}) filter?: FilterExcludingWhere<IpCatalog>
  ): Promise<IpCatalog> {
    return this.ipCatalogRepository.findById(id, filter);
  }

  @patch('/catalogs/{id}')
  @response(204, {
    description: 'IpCatalog PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpCatalog, {partial: true}),
        },
      },
    })
    ipCatalog: IpCatalog,
  ): Promise<void> {
    await this.ipCatalogRepository.updateById(id, ipCatalog);
  }

  @put('/catalogs/{id}')
  @response(204, {
    description: 'IpCatalog PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipCatalog: IpCatalog,
  ): Promise<void> {
    await this.ipCatalogRepository.replaceById(id, ipCatalog);
  }

  @del('/catalogs/{id}')
  @response(204, {
    description: 'IpCatalog DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipCatalogRepository.deleteById(id);
  }
}
