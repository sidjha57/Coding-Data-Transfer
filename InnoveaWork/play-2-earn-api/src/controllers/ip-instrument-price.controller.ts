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
import {IpInstrumentPrice} from '../models';
import {IpInstrumentPriceRepository} from '../repositories';

export class IpInstrumentPriceController {
  constructor(
    @repository(IpInstrumentPriceRepository)
    public ipInstrumentPriceRepository : IpInstrumentPriceRepository,
  ) {}

  @post('/instrument-prices')
  @response(200, {
    description: 'IpInstrumentPrice model instance',
    content: {'application/json': {schema: getModelSchemaRef(IpInstrumentPrice)}},
  })
  async create(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpInstrumentPrice, {
            title: 'NewIpInstrumentPrice',
            exclude: ['ipid'],
          }),
        },
      },
    })
    ipInstrumentPrice: Omit<IpInstrumentPrice, 'ipid'>,
  ): Promise<IpInstrumentPrice> {
    return this.ipInstrumentPriceRepository.create(ipInstrumentPrice);
  }

  @get('/instrument-prices/count')
  @response(200, {
    description: 'IpInstrumentPrice model count',
    content: {'application/json': {schema: CountSchema}},
  })
  async count(
    @param.where(IpInstrumentPrice) where?: Where<IpInstrumentPrice>,
  ): Promise<Count> {
    return this.ipInstrumentPriceRepository.count(where);
  }

  @get('/instrument-prices')
  @response(200, {
    description: 'Array of IpInstrumentPrice model instances',
    content: {
      'application/json': {
        schema: {
          type: 'array',
          items: getModelSchemaRef(IpInstrumentPrice, {includeRelations: true}),
        },
      },
    },
  })
  async find(
    @param.filter(IpInstrumentPrice) filter?: Filter<IpInstrumentPrice>,
  ): Promise<IpInstrumentPrice[]> {
    return this.ipInstrumentPriceRepository.find(filter);
  }

  @patch('/instrument-prices')
  @response(200, {
    description: 'IpInstrumentPrice PATCH success count',
    content: {'application/json': {schema: CountSchema}},
  })
  async updateAll(
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpInstrumentPrice, {partial: true}),
        },
      },
    })
    ipInstrumentPrice: IpInstrumentPrice,
    @param.where(IpInstrumentPrice) where?: Where<IpInstrumentPrice>,
  ): Promise<Count> {
    return this.ipInstrumentPriceRepository.updateAll(ipInstrumentPrice, where);
  }

  @get('/instrument-prices/{id}')
  @response(200, {
    description: 'IpInstrumentPrice model instance',
    content: {
      'application/json': {
        schema: getModelSchemaRef(IpInstrumentPrice, {includeRelations: true}),
      },
    },
  })
  async findById(
    @param.path.number('id') id: number,
    @param.filter(IpInstrumentPrice, {exclude: 'where'}) filter?: FilterExcludingWhere<IpInstrumentPrice>
  ): Promise<IpInstrumentPrice> {
    return this.ipInstrumentPriceRepository.findById(id, filter);
  }

  @patch('/instrument-prices/{id}')
  @response(204, {
    description: 'IpInstrumentPrice PATCH success',
  })
  async updateById(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpInstrumentPrice, {partial: true}),
        },
      },
    })
    ipInstrumentPrice: IpInstrumentPrice,
  ): Promise<void> {
    await this.ipInstrumentPriceRepository.updateById(id, ipInstrumentPrice);
  }

  @put('/instrument-prices/{id}')
  @response(204, {
    description: 'IpInstrumentPrice PUT success',
  })
  async replaceById(
    @param.path.number('id') id: number,
    @requestBody() ipInstrumentPrice: IpInstrumentPrice,
  ): Promise<void> {
    await this.ipInstrumentPriceRepository.replaceById(id, ipInstrumentPrice);
  }

  @del('/instrument-prices/{id}')
  @response(204, {
    description: 'IpInstrumentPrice DELETE success',
  })
  async deleteById(@param.path.number('id') id: number): Promise<void> {
    await this.ipInstrumentPriceRepository.deleteById(id);
  }
}
