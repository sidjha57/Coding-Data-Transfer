import {Entity, model, property, belongsTo} from '@loopback/repository';
import {IpMarketConfig} from './ip-market-config.model';

@model({
  settings: {idInjection: false, mysql: {schema: 'innov-play', table: 'ip_market_instance'}}
})
export class IpMarketInstance extends Entity {
  @property({
    type: 'number',
    precision: 10,
    scale: 0,
    generated: 1,
    id: 1,
    mysql: {columnName: 'ipid', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 1},
  })
  ipid?: number;

  @property({
    type: 'number',
    precision: 3,
    scale: 0,
    generated: 0,
    default: 0,
    mysql: {columnName: 'is_market_cancelled', dataType: 'tinyint', dataLength: null, dataPrecision: 3, dataScale: 0, nullable: 'Y', generated: 0},
  })
  isMarketCancelled?: number;

  @property({
    type: 'number',
    precision: 3,
    scale: 0,
    generated: 0,
    default: 0,
    mysql: {columnName: 'is_market_extended', dataType: 'tinyint', dataLength: null, dataPrecision: 3, dataScale: 0, nullable: 'Y', generated: 0},
  })
  isMarketExtended?: number;

  @property({
    type: 'number',
    precision: 3,
    scale: 0,
    generated: 0,
    default: 0,
    mysql: {columnName: 'is_market_paused', dataType: 'tinyint', dataLength: null, dataPrecision: 3, dataScale: 0, nullable: 'Y', generated: 0},
  })
  isMarketPaused?: number;
  @property({
    type: 'date',
    required: true,
    generated: 0,
    mysql: {columnName: 'session_date_time', dataType: 'datetime', dataLength: null, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  sessionDateTime: string;

  @belongsTo(() => IpMarketConfig,  
  {keyFrom: 'marketConfigId'},
  {name: 'market_config_id'},)
  marketConfigId: number;
  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpMarketInstance>) {
    super(data);
  }
}

export interface IpMarketInstanceRelations {
  // describe navigational properties here
}

export type IpMarketInstanceWithRelations = IpMarketInstance & IpMarketInstanceRelations;
