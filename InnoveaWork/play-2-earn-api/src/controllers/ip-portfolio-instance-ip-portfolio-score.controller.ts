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
  IpPortfolioScore,
} from '../models';
import {IpPortfolioInstanceRepository} from '../repositories';

export class IpPortfolioInstanceIpPortfolioScoreController {
  constructor(
    @repository(IpPortfolioInstanceRepository) protected ipPortfolioInstanceRepository: IpPortfolioInstanceRepository,
  ) { }

  @get('/ip-portfolio-instances/{id}/ip-portfolio-score', {
    responses: {
      '200': {
        description: 'IpPortfolioInstance has one IpPortfolioScore',
        content: {
          'application/json': {
            schema: getModelSchemaRef(IpPortfolioScore),
          },
        },
      },
    },
  })
  async get(
    @param.path.number('id') id: number,
    @param.query.object('filter') filter?: Filter<IpPortfolioScore>,
  ): Promise<IpPortfolioScore> {
    return this.ipPortfolioInstanceRepository.score(id).get(filter);
  }

  @post('/ip-portfolio-instances/{id}/ip-portfolio-score', {
    responses: {
      '200': {
        description: 'IpPortfolioInstance model instance',
        content: {'application/json': {schema: getModelSchemaRef(IpPortfolioScore)}},
      },
    },
  })
  async create(
    @param.path.number('id') id: typeof IpPortfolioInstance.prototype.ipid,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioScore, {
            title: 'NewIpPortfolioScoreInIpPortfolioInstance',
            exclude: ['ipid'],
            optional: ['portfolioId']
          }),
        },
      },
    }) ipPortfolioScore: Omit<IpPortfolioScore, 'ipid'>,
  ): Promise<IpPortfolioScore> {
    return this.ipPortfolioInstanceRepository.score(id).create(ipPortfolioScore);
  }

  @patch('/ip-portfolio-instances/{id}/ip-portfolio-score', {
    responses: {
      '200': {
        description: 'IpPortfolioInstance.IpPortfolioScore PATCH success count',
        content: {'application/json': {schema: CountSchema}},
      },
    },
  })
  async patch(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioScore, {partial: true}),
        },
      },
    })
    ipPortfolioScore: Partial<IpPortfolioScore>,
    @param.query.object('where', getWhereSchemaFor(IpPortfolioScore)) where?: Where<IpPortfolioScore>,
  ): Promise<Count> {
    return this.ipPortfolioInstanceRepository.score(id).patch(ipPortfolioScore, where);
  }

  @del('/ip-portfolio-instances/{id}/ip-portfolio-score', {
    responses: {
      '200': {
        description: 'IpPortfolioInstance.IpPortfolioScore DELETE success count',
        content: {'application/json': {schema: CountSchema}},
      },
    },
  })
  async delete(
    @param.path.number('id') id: number,
    @param.query.object('where', getWhereSchemaFor(IpPortfolioScore)) where?: Where<IpPortfolioScore>,
  ): Promise<Count> {
    return this.ipPortfolioInstanceRepository.score(id).delete(where);
  }
}
