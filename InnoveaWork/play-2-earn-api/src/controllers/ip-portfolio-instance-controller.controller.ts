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
import {IpPortfolioInstance} from '../models';
import {IpPortfolioInstanceRepository} from '../repositories';

export class IpPortfolioInstanceControllerController {
  constructor(
    @repository(IpPortfolioInstanceRepository)
    public ipPortfolioInstanceRepository : IpPortfolioInstanceRepository,
  ) {}

  @post('/portfolio-instances')
  @response(200, {
    description: 'IpPortfolioInstance model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpPortfolioInstance)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioInstance, {
            title: 'NewIpPortfolioInstance',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipPortfolioInstance: Omit<IpPortfolioInstance, 'ipid'>,
  ): Promise<IpPortfolioInstance> {
    return this.ipPortfolioInstanceRepository.create(ipPortfolioInstance);
  }

  @get('/portfolio-instances/count')
  @response(200, {
    description: 'IpPortfolioInstance model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpPortfolioInstance) where?: Where<IpPortfolioInstance>,
  ): Promise<Count> {
    return this.ipPortfolioInstanceRepository.count(where);
  }

  @get('/portfolio-instances')
  @response(200, {
    description: 'Array of IpPortfolioInstance model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpPortfolioInstance, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpPortfolioInstance) filter?: Filter<IpPortfolioInstance>,
  ): Promise<IpPortfolioInstance[]> {
    return this.ipPortfolioInstanceRepository.find(filter);
  }


  // @get('/portfolio-instances-join/{uid}/{status}')
  // @response(200, {
  //   description: 'Array of IpPortfolioInstance model instances',
  //   content: {
  //     'application/json': {
  //       schema: {
  //         type: 'array',
  //         items: getModelSchemaRef(IpPortfolioInstance, {includeRelations: true}),
  //       },
  //     },
  //   },
  // })
  // async findJoin(
  //   @param.path.number('uid') uid: number,
  //   @param.path.string('status') status: string,

  //   @param.filter(IpPortfolioInstance) filter?: Filter<IpPortfolioInstance>,
  // ): Promise<any> {

  //   console.log(uid,status);
  //   const sqlQuery = `
  //     select *
  //     from ip_portfolio_instance
  //     inner join ip_portfolio_status
  //     on ip_portfolio_instance.ipid = ip_portfolio_status.portfolio_id
  //     where
  //     ip_portfolio_instance.user_id = ${uid}
  //     and
  //     ip_portfolio_status.portfolio_status = '${status}'
  //   `;

  //   return this.ipPortfolioInstanceRepository.execute(sqlQuery);
  // }

  @patch('/portfolio-instances')
  @response(200, {
    description: 'IpPortfolioInstance PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioInstance, {partial: true}),
        },
      },
    })
    ipPortfolioInstance: IpPortfolioInstance,
    @param.where(IpPortfolioInstance) where?: Where<IpPortfolioInstance>,
  ): Promise<Count> {
    return this.ipPortfolioInstanceRepository.updateAll(ipPortfolioInstance, where);
  }

  @get('/portfolio-instances/{id}')
  @response(200, {
    description: 'IpPortfolioInstance model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpPortfolioInstance, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpPortfolioInstance, {exclude: 'where'}) filter?: FilterExcludingWhere<IpPortfolioInstance>
  ): Promise<IpPortfolioInstance> {
    return this.ipPortfolioInstanceRepository.findById(id, filter);
  }

  @patch('/portfolio-instances/{id}')
  @response(204, {
    description: 'IpPortfolioInstance PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpPortfolioInstance, {partial: true}),
        },
      },
    })
    ipPortfolioInstance: IpPortfolioInstance,
  ): Promise<void> {
    await this.ipPortfolioInstanceRepository.updateById(id, ipPortfolioInstance);
  }

  @put('/portfolio-instances/{id}')
  @response(204, {
    description: 'IpPortfolioInstance PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipPortfolioInstance: IpPortfolioInstance,
  ): Promise<void> {
    await this.ipPortfolioInstanceRepository.replaceById(id, ipPortfolioInstance);
  }

  @del('/portfolio-instances/{id}')
  @response(204, {
    description: 'IpPortfolioInstance DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipPortfolioInstanceRepository.deleteById(id);
  }
}
