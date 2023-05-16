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
import {IpPortfolioSelection} from '../models';
import {IpPortfolioSelectionRepository} from '../repositories';

export class IpPortfolioSelectionController {
  constructor(
    @repository(IpPortfolioSelectionRepository)
    public ipPortfolioSelectionRepository : IpPortfolioSelectionRepository,
  ) {}

  @post('/portfolio-selections')
  @response(200, {
    description: 'IpPortfolioSelection model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpPortfolioSelection)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioSelection, {
            title: 'NewIpPortfolioSelection',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipPortfolioSelection: Omit<IpPortfolioSelection, 'ipid'>,
  ): Promise<IpPortfolioSelection> {
    return this.ipPortfolioSelectionRepository.create(ipPortfolioSelection);
  }

  @get('/portfolio-selections/count')
  @response(200, {
    description: 'IpPortfolioSelection model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpPortfolioSelection) where?: Where<IpPortfolioSelection>,
  ): Promise<Count> {
    return this.ipPortfolioSelectionRepository.count(where);
  }

  @get('/portfolio-selections')
  @response(200, {
    description: 'Array of IpPortfolioSelection model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpPortfolioSelection, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpPortfolioSelection) filter?: Filter<IpPortfolioSelection>,
  ): Promise<IpPortfolioSelection[]> {
    return this.ipPortfolioSelectionRepository.find(filter);
  }

  @patch('/portfolio-selections')
  @response(200, {
    description: 'IpPortfolioSelection PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioSelection, {partial: true}),
        },
      },
    })
    ipPortfolioSelection: IpPortfolioSelection,
    @param.where(IpPortfolioSelection) where?: Where<IpPortfolioSelection>,
  ): Promise<Count> {
    return this.ipPortfolioSelectionRepository.updateAll(ipPortfolioSelection, where);
  }

  @get('/portfolio-selections/{id}')
  @response(200, {
    description: 'IpPortfolioSelection model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpPortfolioSelection, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpPortfolioSelection, {exclude: 'where'}) filter?: FilterExcludingWhere<IpPortfolioSelection>
  ): Promise<IpPortfolioSelection> {
    return this.ipPortfolioSelectionRepository.findById(id, filter);
  }

  @patch('/portfolio-selections/{id}')
  @response(204, {
    description: 'IpPortfolioSelection PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioSelection, {partial: true}),
        },
      },
    })
    ipPortfolioSelection: IpPortfolioSelection,
  ): Promise<void> {
    await this.ipPortfolioSelectionRepository.updateById(id, ipPortfolioSelection);
  }

  @put('/portfolio-selections/{id}')
  @response(204, {
    description: 'IpPortfolioSelection PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipPortfolioSelection: IpPortfolioSelection,
  ): Promise<void> {
    await this.ipPortfolioSelectionRepository.replaceById(id, ipPortfolioSelection);
  }

  @del('/portfolio-selections/{id}')
  @response(204, {
    description: 'IpPortfolioSelection DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipPortfolioSelectionRepository.deleteById(id);
  }
}
