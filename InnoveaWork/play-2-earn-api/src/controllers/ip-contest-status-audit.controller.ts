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
import {IpContestStatusAudit} from '../models';
import {IpContestStatusAuditRepository} from '../repositories';

export class IpContestStatusAuditController {
  constructor(
    @repository(IpContestStatusAuditRepository)
    public ipContestStatusAuditRepository : IpContestStatusAuditRepository,
  ) {}

  @post('/contest-status-audits')
  @response(200, {
    description: 'IpContestStatusAudit model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpContestStatusAudit)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestStatusAudit, {
            title: 'NewIpContestStatusAudit',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipContestStatusAudit: Omit<IpContestStatusAudit, 'ipid'>,
  ): Promise<IpContestStatusAudit> {
    return this.ipContestStatusAuditRepository.create(ipContestStatusAudit);
  }

  @get('/contest-status-audits/count')
  @response(200, {
    description: 'IpContestStatusAudit model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpContestStatusAudit) where?: Where<IpContestStatusAudit>,
  ): Promise<Count> {
    return this.ipContestStatusAuditRepository.count(where);
  }

  @get('/contest-status-audits')
  @response(200, {
    description: 'Array of IpContestStatusAudit model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpContestStatusAudit, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpContestStatusAudit) filter?: Filter<IpContestStatusAudit>,
  ): Promise<IpContestStatusAudit[]> {
    return this.ipContestStatusAuditRepository.find(filter);
  }

  @patch('/contest-status-audits')
  @response(200, {
    description: 'IpContestStatusAudit PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestStatusAudit, {partial: true}),
        },
      },
    })
    ipContestStatusAudit: IpContestStatusAudit,
    @param.where(IpContestStatusAudit) where?: Where<IpContestStatusAudit>,
  ): Promise<Count> {
    return this.ipContestStatusAuditRepository.updateAll(ipContestStatusAudit, where);
  }

  @get('/contest-status-audits/{id}')
  @response(200, {
    description: 'IpContestStatusAudit model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpContestStatusAudit, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpContestStatusAudit, {exclude: 'where'}) filter?: FilterExcludingWhere<IpContestStatusAudit>
  ): Promise<IpContestStatusAudit> {
    return this.ipContestStatusAuditRepository.findById(id, filter);
  }

  @patch('/contest-status-audits/{id}')
  @response(204, {
    description: 'IpContestStatusAudit PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestStatusAudit, {partial: true}),
        },
      },
    })
    ipContestStatusAudit: IpContestStatusAudit,
  ): Promise<void> {
    await this.ipContestStatusAuditRepository.updateById(id, ipContestStatusAudit);
  }

  @put('/contest-status-audits/{id}')
  @response(204, {
    description: 'IpContestStatusAudit PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipContestStatusAudit: IpContestStatusAudit,
  ): Promise<void> {
    await this.ipContestStatusAuditRepository.replaceById(id, ipContestStatusAudit);
  }

  @del('/contest-status-audits/{id}')
  @response(204, {
    description: 'IpContestStatusAudit DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipContestStatusAuditRepository.deleteById(id);
  }
}
