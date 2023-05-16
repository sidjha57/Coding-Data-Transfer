import {Entity, model, property, belongsTo} from '@loopback/repository';
import {IpInstrumentConfig} from './ip-instrument-config.model';

@model({
  settings: {idInjection: false, mysql: {schema: 'innov-play', table: 'ip_instrument_week'}}
})
export class IpInstrumentWeek extends Entity {
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
    mysql: {columnName: 'week_number', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 0},
  })
  weekNumber: number;

  @belongsTo(() => IpInstrumentConfig, {keyFrom: 'instrumentId'},
  {name: 'instrument_id'})
  instrumentId: number;
  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpInstrumentWeek>) {
    super(data);
  }
}

export interface IpInstrumentWeekRelations {
  // describe navigational properties here
}

export type IpInstrumentWeekWithRelations = IpInstrumentWeek & IpInstrumentWeekRelations;
