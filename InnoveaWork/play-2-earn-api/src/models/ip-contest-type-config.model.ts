import {Entity, model, property, belongsTo} from '@loopback/repository';
import {IpMarketConfig} from './ip-market-config.model';
import {IpContestType} from './ip-contest-type.model';

@model({
  settings: {
    idInjection: false,
    mysql: {schema: 'innov-play', table: 'ip_contest_type_config'}
  }
})
export class IpContestTypeConfig extends Entity {
  @property({
    type: 'string',
    required: true,
    generated: 0,
    mysql: {columnName: 'contest_end_time', dataType: 'time', dataLength: null, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  contestEndTime: string;

  @property({
    type: 'string',
    required: true,
    generated: 0,
    mysql: {columnName: 'contest_extended_time', dataType: 'time', dataLength: null, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  contestExtendedTime: string;

  @property({
    type: 'number',
    required: true,
    precision: 10,
    scale: 0,
    generated: 0,
    mysql: {columnName: 'contest_parameter_id', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 0},
  })
  contestParameterId: number;

  @property({
    type: 'string',
    required: true,
    generated: 0,
    mysql: {columnName: 'contest_start_time', dataType: 'time', dataLength: null, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  contestStartTime: string;
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

  @belongsTo(() => IpMarketConfig, {keyFrom: 'marketId'}, {name: 'market_id'})
  marketId: number;

  @belongsTo(() => IpContestType, {keyFrom: 'contestTypeId'}, {name: 'contest_type_id'})
  contestTypeId: number;
  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpContestTypeConfig>) {
    super(data);
  }
}

export interface IpContestTypeConfigRelations {
  // describe navigational properties here
}

export type IpContestTypeConfigWithRelations = IpContestTypeConfig & IpContestTypeConfigRelations;
