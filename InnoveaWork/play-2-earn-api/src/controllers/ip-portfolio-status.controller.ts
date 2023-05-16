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
import {IpPortfolioStatus, IpPortfolioStatusAudit} from '../models';
import {IpPortfolioStatusAuditRepository, IpPortfolioStatusRepository} from '../repositories';

export class IpPortfolioStatusController {
  constructor(
    @repository(IpPortfolioStatusRepository)
    public ipPortfolioStatusRepository : IpPortfolioStatusRepository,
    ) {}

  @post('/portfolio-statuses')
  @response(200, {
    description: 'IpPortfolioStatus model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpPortfolioStatus)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioStatus, {
            title: 'NewIpPortfolioStatus',
            exclude: ['ipid'],
            optional: ['portfolio_create_time_stamp']
          }),
        },
      },
    })
    ipPortfolioStatus: Omit<IpPortfolioStatus, 'ipid' | 'portfolioCreateTimeStamp'>,
  ): Promise<IpPortfolioStatus> {
    return this.ipPortfolioStatusRepository.create(ipPortfolioStatus);
  }

  @get('/portfolio-statuses/count')
  @response(200, {
    description: 'IpPortfolioStatus model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpPortfolioStatus) where?: Where<IpPortfolioStatus>,
  ): Promise<Count> {
    return this.ipPortfolioStatusRepository.count(where);
  }

  @get('/portfolio-statuses')
  @response(200, {
    description: 'Array of IpPortfolioStatus model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpPortfolioStatus, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpPortfolioStatus) filter?: Filter<IpPortfolioStatus>,
  ): Promise<IpPortfolioStatus[]> {
    return this.ipPortfolioStatusRepository.find(filter);
  }

  @patch('/portfolio-statuses')
  @response(200, {
    description: 'IpPortfolioStatus PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioStatus, {partial: true}),
        },
      },
    })
    ipPortfolioStatus: IpPortfolioStatus,
    @param.where(IpPortfolioStatus) where?: Where<IpPortfolioStatus>,
  ): Promise<Count> {
    return this.ipPortfolioStatusRepository.updateAll(ipPortfolioStatus, where);
  }

  @get('/portfolio-statuses/{id}')
  @response(200, {
    description: 'IpPortfolioStatus model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpPortfolioStatus, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpPortfolioStatus, {exclude: 'where'}) filter?: FilterExcludingWhere<IpPortfolioStatus>
  ): Promise<IpPortfolioStatus> {
    return this.ipPortfolioStatusRepository.findById(id, filter);
  }

  @patch('/portfolio-statuses/{id}')
  @response(204, {
    description: 'IpPortfolioStatus PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioStatus, {partial: true}),
        },
      },
    })
    ipPortfolioStatus: IpPortfolioStatus,
  ): Promise<void> {
    
    await this.ipPortfolioStatusRepository.updateById(id, ipPortfolioStatus);
  }

  @put('/portfolio-statuses/{id}')
  @response(204, {
    description: 'IpPortfolioStatus PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipPortfolioStatus: IpPortfolioStatus,
  ): Promise<void> {
    await this.ipPortfolioStatusRepository.replaceById(id, ipPortfolioStatus);
  }

  @del('/portfolio-statuses/{id}')
  @response(204, {
    description: 'IpPortfolioStatus DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    
    await this.ipPortfolioStatusRepository.deleteById(id);
  }
}
