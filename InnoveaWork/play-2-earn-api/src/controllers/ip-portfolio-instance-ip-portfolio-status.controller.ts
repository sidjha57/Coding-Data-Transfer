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
  IpPortfolioStatus,
} from '../models';
import {IpPortfolioInstanceRepository} from '../repositories';

export class IpPortfolioInstanceIpPortfolioStatusController {
  constructor(
    @repository(IpPortfolioInstanceRepository) protected ipPortfolioInstanceRepository: IpPortfolioInstanceRepository,
  ) { }

  @get('/ip-portfolio-instances/{id}/ip-portfolio-status', {
    responses: {
      '200': {
        description: 'IpPortfolioInstance has one IpPortfolioStatus',
        content: {
          'application/json': {
            schema: getModelSchemaRef(IpPortfolioStatus),
          },
        },
      },
    },
  })
  async get(
    @param.path.number('id') id: number,
    @param.query.object('filter') filter?: Filter<IpPortfolioStatus>,
  ): Promise<IpPortfolioStatus> {
    return this.ipPortfolioInstanceRepository.status(id).get(filter);
  }

  @post('/ip-portfolio-instances/{id}/ip-portfolio-status', {
    responses: {
      '200': {
        description: 'IpPortfolioInstance model instance',
        content: {'application/json': {schema: getModelSchemaRef(IpPortfolioStatus)}},
      },
    },
  })
  async create(
    @param.path.number('id') id: typeof IpPortfolioInstance.prototype.ipid,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioStatus, {
            title: 'NewIpPortfolioStatusInIpPortfolioInstance',
            exclude: ['ipid'],
            optional: ['portfolioId']
          }),
        },
      },
    }) ipPortfolioStatus: Omit<IpPortfolioStatus, 'ipid'>,
  ): Promise<IpPortfolioStatus> {
    return this.ipPortfolioInstanceRepository.status(id).create(ipPortfolioStatus);
  }

  @patch('/ip-portfolio-instances/{id}/ip-portfolio-status', {
    responses: {
      '200': {
        description: 'IpPortfolioInstance.IpPortfolioStatus PATCH success count',
        content: {'application/json': {schema: CountSchema}},
      },
    },
  })
  async patch(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioStatus, {partial: true}),
        },
      },
    })
    ipPortfolioStatus: Partial<IpPortfolioStatus>,
    @param.query.object('where', getWhereSchemaFor(IpPortfolioStatus)) where?: Where<IpPortfolioStatus>,
  ): Promise<Count> {
    return this.ipPortfolioInstanceRepository.status(id).patch(ipPortfolioStatus, where);
  }

  @del('/ip-portfolio-instances/{id}/ip-portfolio-status', {
    responses: {
      '200': {
        description: 'IpPortfolioInstance.IpPortfolioStatus DELETE success count',
        content: {'application/json': {schema: CountSchema}},
      },
    },
  })
  async delete(
    @param.path.number('id') id: number,
    @param.query.object('where', getWhereSchemaFor(IpPortfolioStatus)) where?: Where<IpPortfolioStatus>,
  ): Promise<Count> {
    return this.ipPortfolioInstanceRepository.status(id).delete(where);
  }
}
