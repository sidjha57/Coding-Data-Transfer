import {Entity, model, property, belongsTo, hasOne} from '@loopback/repository';
import {IpContestTypeConfig} from './ip-contest-type-config.model';
import {IpMarketInstance} from './ip-market-instance.model';
import {IpContestStatus} from './ip-contest-status.model';

@model({
  settings: {
    idInjection: false,
    mysql: {schema: 'innov-play', table: 'ip_contest_single_day_instance'},
  },
})
export class IpContestSingleDayInstance extends Entity {
  @property({
    type: 'date',
    required: true,
    generated: 0,
    mysql: {
      columnName: 'contest_session_end_time',
      dataType: 'datetime',
      dataLength: null,
      dataPrecision: null,
      dataScale: null,
      nullable: 'N',
      generated: 0,
    },
  })
  contestSessionEndTime: string;

  @property({
    type: 'date',
    required: true,
    generated: 0,
    mysql: {
      columnName: 'contest_session_start_time',
      dataType: 'datetime',
      dataLength: null,
      dataPrecision: null,
      dataScale: null,
      nullable: 'N',
      generated: 0,
    },
  })
  contestSessionStartTime: string;

  @property({
    type: 'date',
    generated: 0,
    mysql: {
      columnName: 'contest_session_extended_time',
      dataType: 'datetime',
      dataLength: null,
      dataPrecision: null,
      dataScale: null,
      nullable: 'Y',
      generated: 0,
    },
  })
  contestSessionExtendedTime: string;

  @property({
    type: 'number',
    precision: 10,
    scale: 0,
    generated: 1,
    id: 1,
    mysql: {
      columnName: 'ipid',
      dataType: 'int',
      dataLength: null,
      dataPrecision: 10,
      dataScale: 0,
      nullable: 'N',
      generated: 1,
    },
  })
  ipid?: number;

  @belongsTo(
    () => IpContestTypeConfig,
    {keyFrom: 'contestTypeConfigId'},
    {name: 'contest_type_config_id'},
  )
  contestTypeConfigId: number;

  @belongsTo(
    () => IpMarketInstance,
    {keyFrom: 'marketInstanceId'},
    {name: 'market_instance_id'},
  )
  marketInstanceId: number;

  @hasOne(() => IpContestStatus, {keyTo: 'contestId'})
  status: IpContestStatus;
  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpContestSingleDayInstance>) {
    super(data);
  }
}

export interface IpContestSingleDayInstanceRelations {
  // describe navigational properties here
}

export type IpContestSingleDayInstanceWithRelations =
  IpContestSingleDayInstance & IpContestSingleDayInstanceRelations;
