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
import {IpPortfolioScore} from '../models';
import {IpPortfolioScoreRepository} from '../repositories';

export class IpPortfolioScoreController {
  constructor(
    @repository(IpPortfolioScoreRepository)
    public ipPortfolioScoreRepository : IpPortfolioScoreRepository,
  ) {}

  @post('/portfolio-scores')
  @response(200, {
    description: 'IpPortfolioScore model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpPortfolioScore)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioScore, {
            title: 'NewIpPortfolioScore',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipPortfolioScore: Omit<IpPortfolioScore, 'ipid'>,
  ): Promise<IpPortfolioScore> {
    return this.ipPortfolioScoreRepository.create(ipPortfolioScore);
  }

  @get('/portfolio-scores/count')
  @response(200, {
    description: 'IpPortfolioScore model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpPortfolioScore) where?: Where<IpPortfolioScore>,
  ): Promise<Count> {
    return this.ipPortfolioScoreRepository.count(where);
  }

  @get('/portfolio-scores')
  @response(200, {
    description: 'Array of IpPortfolioScore model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpPortfolioScore, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpPortfolioScore) filter?: Filter<IpPortfolioScore>,
  ): Promise<IpPortfolioScore[]> {
    return this.ipPortfolioScoreRepository.find(filter);
  }

  @patch('/portfolio-scores')
  @response(200, {
    description: 'IpPortfolioScore PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioScore, {partial: true}),
        },
      },
    })
    ipPortfolioScore: IpPortfolioScore,
    @param.where(IpPortfolioScore) where?: Where<IpPortfolioScore>,
  ): Promise<Count> {
    return this.ipPortfolioScoreRepository.updateAll(ipPortfolioScore, where);
  }

  @get('/portfolio-scores/{id}')
  @response(200, {
    description: 'IpPortfolioScore model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpPortfolioScore, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpPortfolioScore, {exclude: 'where'}) filter?: FilterExcludingWhere<IpPortfolioScore>
  ): Promise<IpPortfolioScore> {
    return this.ipPortfolioScoreRepository.findById(id, filter);
  }

  @patch('/portfolio-scores/{id}')
  @response(204, {
    description: 'IpPortfolioScore PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioScore, {partial: true}),
        },
      },
    })
    ipPortfolioScore: IpPortfolioScore,
  ): Promise<void> {
    await this.ipPortfolioScoreRepository.updateById(id, ipPortfolioScore);
  }

  @put('/portfolio-scores/{id}')
  @response(204, {
    description: 'IpPortfolioScore PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipPortfolioScore: IpPortfolioScore,
  ): Promise<void> {
    await this.ipPortfolioScoreRepository.replaceById(id, ipPortfolioScore);
  }

  @del('/portfolio-scores/{id}')
  @response(204, {
    description: 'IpPortfolioScore DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipPortfolioScoreRepository.deleteById(id);
  }
}
