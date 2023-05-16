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
  IpPortfolioInstance,
  IpPortfolioSelection,
} from '../models';
import {IpPortfolioInstanceRepository} from '../repositories';

export class IpPortfolioInstanceIpPortfolioSelectionController {
  constructor(
    @repository(IpPortfolioInstanceRepository) protected ipPortfolioInstanceRepository: IpPortfolioInstanceRepository,
  ) { }

  @get('/ip-portfolio-instances/{id}/ip-portfolio-selections', {
    responses: {
      '200': {
        description: 'Array of IpPortfolioInstance has many IpPortfolioSelection',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpPortfolioSelection)},
          },
        },
      },
    },
  })
  async find(
    @param.path.number('id') id: number,
    @param.query.object('filter') filter?: Filter<IpPortfolioSelection>,
  ): Promise<IpPortfolioSelection[]> {
    return this.ipPortfolioInstanceRepository.portfolioSelections(id).find(filter);
  }

  @post('/ip-portfolio-instances/{id}/ip-portfolio-selections', {
    responses: {
      '200': {
        description: 'IpPortfolioInstance model instance',
        content: {'application/json': {schema: getModelSchemaRef(IpPortfolioSelection)}},
      },
    },
  })
  async create(
    @param.path.number('id') id: typeof IpPortfolioInstance.prototype.ipid,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioSelection, {
            title: 'NewIpPortfolioSelectionInIpPortfolioInstance',
            exclude: ['ipid'],
            optional: ['portfolioId']
          }),
        },
      },
    }) ipPortfolioSelection: Omit<IpPortfolioSelection, 'ipid'>,
  ): Promise<IpPortfolioSelection> {
    return this.ipPortfolioInstanceRepository.portfolioSelections(id).create(ipPortfolioSelection);
  }

  @patch('/ip-portfolio-instances/{id}/ip-portfolio-selections', {
    responses: {
      '200': {
        description: 'IpPortfolioInstance.IpPortfolioSelection PATCH success count',
        content: {'application/json': {schema: CountSchema}},
      },
    },
  })
  async patch(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioSelection, {partial: true}),
        },
      },
    })
    ipPortfolioSelection: Partial<IpPortfolioSelection>,
    @param.query.object('where', getWhereSchemaFor(IpPortfolioSelection)) where?: Where<IpPortfolioSelection>,
  ): Promise<Count> {
    return this.ipPortfolioInstanceRepository.portfolioSelections(id).patch(ipPortfolioSelection, where);
  }

  @del('/ip-portfolio-instances/{id}/ip-portfolio-selections', {
    responses: {
      '200': {
        description: 'IpPortfolioInstance.IpPortfolioSelection DELETE success count',
        content: {'application/json': {schema: CountSchema}},
      },
    },
  })
  async delete(
    @param.path.number('id') id: number,
    @param.query.object('where', getWhereSchemaFor(IpPortfolioSelection)) where?: Where<IpPortfolioSelection>,
  ): Promise<Count> {
    return this.ipPortfolioInstanceRepository.portfolioSelections(id).delete(where);
  }
}
