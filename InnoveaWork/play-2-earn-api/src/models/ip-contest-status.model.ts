import {Entity, model, property} from '@loopback/repository';

@model({
  settings: {
    idInjection: false,
    mysql: {schema: 'innov-play', table: 'ip_contest_status'},
  },
})
export class IpContestStatus extends Entity {
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
    precision: 10,
    scale: 0,
    generated: 0,
    mysql: {columnName: 'contest_id', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 0},
  })
  contestId: number;

  @property({
    type: 'date',
    generated: 0,
    mysql: {
      columnName: 'status_update_time_stamp',
      dataType: 'datetime',
      dataLength: null,
      dataPrecision: null,
      dataScale: null,
      nullable: 'Y',
      generated: 0,
    },
  })
  statusUpdateTimeStamp: string;

  @property({
    type: 'string',
    required: true,
    length: 20,
    generated: 0,
    mysql: {columnName: 'contest_status', dataType: 'varchar', dataLength: 20, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  contestStatus: string;

  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpContestStatus>) {
    super(data);
  }
}

export interface IpContestStatusRelations {
  // describe navigational properties here
}

export type IpContestStatusWithRelations = IpContestStatus &
  IpContestStatusRelations;
