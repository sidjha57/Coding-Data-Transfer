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
import {IpMarketStatusAudit} from '../models';
import {IpMarketStatusAuditRepository} from '../repositories';

export class IpMarketStatusAuditController {
  constructor(
    @repository(IpMarketStatusAuditRepository)
    public ipMarketStatusAuditRepository : IpMarketStatusAuditRepository,
  ) {}

  @post('/market-status-audits')
  @response(200, {
    description: 'IpMarketStatusAudit model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpMarketStatusAudit)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketStatusAudit, {
            title: 'NewIpMarketStatusAudit',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipMarketStatusAudit: Omit<IpMarketStatusAudit, 'ipid'>,
  ): Promise<IpMarketStatusAudit> {
    return this.ipMarketStatusAuditRepository.create(ipMarketStatusAudit);
  }

  @get('/market-status-audits/count')
  @response(200, {
    description: 'IpMarketStatusAudit model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpMarketStatusAudit) where?: Where<IpMarketStatusAudit>,
  ): Promise<Count> {
    return this.ipMarketStatusAuditRepository.count(where);
  }

  @get('/market-status-audits')
  @response(200, {
    description: 'Array of IpMarketStatusAudit model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpMarketStatusAudit, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpMarketStatusAudit) filter?: Filter<IpMarketStatusAudit>,
  ): Promise<IpMarketStatusAudit[]> {
    return this.ipMarketStatusAuditRepository.find(filter);
  }

  @patch('/market-status-audits')
  @response(200, {
    description: 'IpMarketStatusAudit PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketStatusAudit, {partial: true}),
        },
      },
    })
    ipMarketStatusAudit: IpMarketStatusAudit,
    @param.where(IpMarketStatusAudit) where?: Where<IpMarketStatusAudit>,
  ): Promise<Count> {
    return this.ipMarketStatusAuditRepository.updateAll(ipMarketStatusAudit, where);
  }

  @get('/market-status-audits/{id}')
  @response(200, {
    description: 'IpMarketStatusAudit model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpMarketStatusAudit, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpMarketStatusAudit, {exclude: 'where'}) filter?: FilterExcludingWhere<IpMarketStatusAudit>
  ): Promise<IpMarketStatusAudit> {
    return this.ipMarketStatusAuditRepository.findById(id, filter);
  }

  @patch('/market-status-audits/{id}')
  @response(204, {
    description: 'IpMarketStatusAudit PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpMarketStatusAudit, {partial: true}),
        },
      },
    })
    ipMarketStatusAudit: IpMarketStatusAudit,
  ): Promise<void> {
    await this.ipMarketStatusAuditRepository.updateById(id, ipMarketStatusAudit);
  }

  @put('/market-status-audits/{id}')
  @response(204, {
    description: 'IpMarketStatusAudit PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipMarketStatusAudit: IpMarketStatusAudit,
  ): Promise<void> {
    await this.ipMarketStatusAuditRepository.replaceById(id, ipMarketStatusAudit);
  }

  @del('/market-status-audits/{id}')
  @response(204, {
    description: 'IpMarketStatusAudit DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipMarketStatusAuditRepository.deleteById(id);
  }
}
