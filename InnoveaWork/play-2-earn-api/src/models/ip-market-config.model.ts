import {Entity, model, property, hasMany} from '@loopback/repository';
import {IpMarketInstance} from './ip-market-instance.model';

@model({
  settings: {idInjection: false, mysql: {schema: 'innov-play', table: 'ip_market_config'}}
})
export class IpMarketConfig extends Entity {
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
    required: true,
    precision: 3,
    scale: 0,
    generated: 0,
    mysql: {columnName: 'is_active', dataType: 'tinyint', dataLength: null, dataPrecision: 3, dataScale: 0, nullable: 'N', generated: 0},
  })
  isActive: number;

  @property({
    type: 'string',
    required: true,
    length: 10,
    generated: 0,
    mysql: {columnName: 'market_name', dataType: 'varchar', dataLength: 10, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  marketName: string;

  @property({
    type: 'string',
    required: true,
    generated: 0,
    mysql: {columnName: 'market_session_end_time', dataType: 'time', dataLength: null, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  marketSessionEndTime: string;

  @property({
    type: 'string',
    required: true,
    generated: 0,
    mysql: {columnName: 'market_session_extended_time', dataType: 'time', dataLength: null, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  marketSessionExtendedTime: string;

  @property({
    type: 'string',
    required: true,
    generated: 0,
    mysql: {columnName: 'market_session_start_time', dataType: 'time', dataLength: null, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  marketSessionStartTime: string;

  @hasMany(() => IpMarketInstance, {keyTo: 'marketConfigId'})
  marketInstances: IpMarketInstance[];
  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpMarketConfig>) {
    super(data);
  }
}

export interface IpMarketConfigRelations {
  // describe navigational properties here
}

export type IpMarketConfigWithRelations = IpMarketConfig & IpMarketConfigRelations;
