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
import {IpInstrumentWeek} from '../models';
import {IpInstrumentWeekRepository} from '../repositories';

export class IpInstrumentWeekControllerController {
  constructor(
    @repository(IpInstrumentWeekRepository)
    public ipInstrumentWeekRepository : IpInstrumentWeekRepository,
  ) {}

  @post('/instrument-weeks')
  @response(200, {
    description: 'IpInstrumentWeek model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpInstrumentWeek)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpInstrumentWeek, {
            title: 'NewIpInstrumentWeek',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipInstrumentWeek: Omit<IpInstrumentWeek, 'ipid'>,
  ): Promise<IpInstrumentWeek> {
    return this.ipInstrumentWeekRepository.create(ipInstrumentWeek);
  }

  @get('/instrument-weeks/count')
  @response(200, {
    description: 'IpInstrumentWeek model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpInstrumentWeek) where?: Where<IpInstrumentWeek>,
  ): Promise<Count> {
    return this.ipInstrumentWeekRepository.count(where);
  }

  @get('/instrument-weeks')
  @response(200, {
    description: 'Array of IpInstrumentWeek model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpInstrumentWeek, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpInstrumentWeek) filter?: Filter<IpInstrumentWeek>,
  ): Promise<IpInstrumentWeek[]> {
    return this.ipInstrumentWeekRepository.find(filter);
  }

  @get('/instrument-weeks-by-catalog')
  @response(200, {
    description: 'Array of IpInstrumentWeek model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpInstrumentWeek, {includeRelations: true}),
        },
      },
    },
  })
  async findByCatalog(
    @param.filter(IpInstrumentWeek) filter?: any,
  ): Promise<any> {
    // console.log(filter?.where)
    const week_number : number = filter?.where?.weekNumber;
    const catalog_id : number = filter?.where?.catalogId;
    // console.log(week_number, catalog_id);

    const query : string = `       
      select ip_instrument_config.instrument_name as instrumentName, ip_instrument_config.instrument_symbol as instrumentSymbol, ip_instrument_config.ipid
      from ip_instrument_config 
      inner join ip_instrument_week 
      on ip_instrument_config.ipid = ip_instrument_week.instrument_id
      where
      ip_instrument_config.catalog_id = ${catalog_id}
      and
      ip_instrument_week.week_number = ${week_number}`

    return this.ipInstrumentWeekRepository.execute(query);
  }

  @patch('/instrument-weeks')
  @response(200, {
    description: 'IpInstrumentWeek PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpInstrumentWeek, {partial: true}),
        },
      },
    })
    ipInstrumentWeek: IpInstrumentWeek,
    @param.where(IpInstrumentWeek) where?: Where<IpInstrumentWeek>,
  ): Promise<Count> {
    return this.ipInstrumentWeekRepository.updateAll(ipInstrumentWeek, where);
  }

  @get('/instrument-weeks/{id}')
  @response(200, {
    description: 'IpInstrumentWeek model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpInstrumentWeek, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpInstrumentWeek, {exclude: 'where'}) filter?: FilterExcludingWhere<IpInstrumentWeek>
  ): Promise<IpInstrumentWeek> {
    return this.ipInstrumentWeekRepository.findById(id, filter);
  }

  @patch('/instrument-weeks/{id}')
  @response(204, {
    description: 'IpInstrumentWeek PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpInstrumentWeek, {partial: true}),
        },
      },
    })
    ipInstrumentWeek: IpInstrumentWeek,
  ): Promise<void> {
    await this.ipInstrumentWeekRepository.updateById(id, ipInstrumentWeek);
  }

  @put('/instrument-weeks/{id}')
  @response(204, {
    description: 'IpInstrumentWeek PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipInstrumentWeek: IpInstrumentWeek,
  ): Promise<void> {
    await this.ipInstrumentWeekRepository.replaceById(id, ipInstrumentWeek);
  }

  @del('/instrument-weeks/{id}')
  @response(204, {
    description: 'IpInstrumentWeek DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipInstrumentWeekRepository.deleteById(id);
  }
}
