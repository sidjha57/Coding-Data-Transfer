import {Entity, model, property, belongsTo} from '@loopback/repository';
import {IpInstrumentConfig} from './ip-instrument-config.model';

@model({
  settings: {
    idInjection: false,
    mysql: {schema: 'innov-play', table: 'ip_instrument_price'}
  }
})
export class IpInstrumentPrice extends Entity {
  @property({
    type: 'number',
    precision: 22,
    generated: 0,
    mysql: {columnName: 'instrument_price', dataType: 'double', dataLength: null, dataPrecision: 22, dataScale: null, nullable: 'Y', generated: 0},
  })
  instrumentPrice?: number;

  @property({
    type: 'number',
    precision: 10,
    scale: 0,
    generated: 1,
    id: 1,
    mysql: { columnName: 'ipid', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 1 },
  })
  ipid?: number;

  @property({
    type: 'date',
    required: true,
    generated: 0,
    mysql: {columnName: 'updated_time_stamp', dataType: 'datetime', dataLength: null, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  updatedTimeStamp: string;

  @belongsTo(() => IpInstrumentConfig)
  instrumentId: number;
  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpInstrumentPrice>) {
    super(data);
  }
}

export interface IpInstrumentPriceRelations {
  // describe navigational properties here
}

export type IpInstrumentPriceWithRelations = IpInstrumentPrice & IpInstrumentPriceRelations;
