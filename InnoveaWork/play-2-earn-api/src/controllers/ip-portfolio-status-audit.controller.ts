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
import {IpPortfolioStatusAudit} from '../models';
import {IpPortfolioStatusAuditRepository} from '../repositories';

export class IpPortfolioStatusAuditController {
  constructor(
    @repository(IpPortfolioStatusAuditRepository)
    public ipPortfolioStatusAuditRepository : IpPortfolioStatusAuditRepository,
  ) {}

  @post('/portfolio-status-audits')
  @response(200, {
    description: 'IpPortfolioStatusAudit model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpPortfolioStatusAudit)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioStatusAudit, {
            title: 'NewIpPortfolioStatusAudit',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipPortfolioStatusAudit: Omit<IpPortfolioStatusAudit, 'ipid'>,
  ): Promise<IpPortfolioStatusAudit> {
    return this.ipPortfolioStatusAuditRepository.create(ipPortfolioStatusAudit);
  }

  @get('/portfolio-status-audits/count')
  @response(200, {
    description: 'IpPortfolioStatusAudit model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpPortfolioStatusAudit) where?: Where<IpPortfolioStatusAudit>,
  ): Promise<Count> {
    return this.ipPortfolioStatusAuditRepository.count(where);
  }

  @get('/portfolio-status-audits')
  @response(200, {
    description: 'Array of IpPortfolioStatusAudit model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpPortfolioStatusAudit, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpPortfolioStatusAudit) filter?: Filter<IpPortfolioStatusAudit>,
  ): Promise<IpPortfolioStatusAudit[]> {
    return this.ipPortfolioStatusAuditRepository.find(filter);
  }

  @patch('/portfolio-status-audits')
  @response(200, {
    description: 'IpPortfolioStatusAudit PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioStatusAudit, {partial: true}),
        },
      },
    })
    ipPortfolioStatusAudit: IpPortfolioStatusAudit,
    @param.where(IpPortfolioStatusAudit) where?: Where<IpPortfolioStatusAudit>,
  ): Promise<Count> {
    return this.ipPortfolioStatusAuditRepository.updateAll(ipPortfolioStatusAudit, where);
  }

  @get('/portfolio-status-audits/{id}')
  @response(200, {
    description: 'IpPortfolioStatusAudit model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpPortfolioStatusAudit, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpPortfolioStatusAudit, {exclude: 'where'}) filter?: FilterExcludingWhere<IpPortfolioStatusAudit>
  ): Promise<IpPortfolioStatusAudit> {
    return this.ipPortfolioStatusAuditRepository.findById(id, filter);
  }

  @patch('/portfolio-status-audits/{id}')
  @response(204, {
    description: 'IpPortfolioStatusAudit PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioStatusAudit, {partial: true}),
        },
      },
    })
    ipPortfolioStatusAudit: IpPortfolioStatusAudit,
  ): Promise<void> {
    await this.ipPortfolioStatusAuditRepository.updateById(id, ipPortfolioStatusAudit);
  }

  @put('/portfolio-status-audits/{id}')
  @response(204, {
    description: 'IpPortfolioStatusAudit PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipPortfolioStatusAudit: IpPortfolioStatusAudit,
  ): Promise<void> {
    await this.ipPortfolioStatusAuditRepository.replaceById(id, ipPortfolioStatusAudit);
  }

  @del('/portfolio-status-audits/{id}')
  @response(204, {
    description: 'IpPortfolioStatusAudit DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipPortfolioStatusAuditRepository.deleteById(id);
  }
}
