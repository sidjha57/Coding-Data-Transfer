import {Entity, model, property, belongsTo} from '@loopback/repository';
import {IpPortfolioInstance} from './ip-portfolio-instance.model';
import {IpInstrumentConfig} from './ip-instrument-config.model';

@model({
  settings: {
    idInjection: false,
    mysql: {schema: 'innov-play', table: 'ip_portfolio_selection'}
  }
})
export class IpPortfolioSelection extends Entity {
  @property({
    type: 'number',
    required: true,
    precision: 22,
    generated: 0,
    jsonSchema: {
      minimum: 1,
      errorMessage: {
        minimum: "Minimum booster selection cannot be less than 1"
      }
    },
    mysql: {columnName: 'booster_selection', dataType: 'double', dataLength: null, dataPrecision: 22, dataScale: null, nullable: 'N', generated: 0},
  })
  boosterSelection: number;
  @property({
    type: 'number',
    required: true,
    precision: 10,
    scale: 0,
    generated: 0,
    jsonSchema: {
      minimum: -1,
      maximum: 1,
      errorMessage: {
        minimum: "Instrument selection can be only -1 and 1"
      }
    },
    mysql: {columnName: 'instrument_selection', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 0},
  })
  instrumentSelection: number;

  @property({
    type: 'number',
    precision: 10,
    scale: 0,
    generated: 1,
    id: 1,
    mysql: { columnName: 'ipid', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 1 },
  })
  ipid?: number;

  @belongsTo(() => IpPortfolioInstance,
    {keyFrom: 'portfolioId'},
    {name: 'portfolio_id'})
  portfolioId: number;

  @belongsTo(() => IpInstrumentConfig,  
  {keyFrom: 'instrumentId'},
  {name: 'instrument_id'})
  instrumentId: number;
  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpPortfolioSelection>) {
    super(data);
  }
}

export interface IpPortfolioSelectionRelations {
  // describe navigational properties here
}

export type IpPortfolioSelectionWithRelations = IpPortfolioSelection & IpPortfolioSelectionRelations;
