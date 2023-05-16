import {Entity, model, property, belongsTo} from '@loopback/repository';
import {IpCatalog} from './ip-catalog.model';

@model({
  settings: {
    idInjection: false,
    mysql: {schema: 'innov-play', table: 'ip_instrument_config'}
  }
})
export class IpInstrumentConfig extends Entity {
  @property({
    type: 'string',
    required: true,
    length: 50,
    generated: 0,
    mysql: {columnName: 'instrument_name', dataType: 'varchar', dataLength: 50, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  instrumentName: string;

  @property({
    type: 'string',
    required: true,
    length: 30,
    generated: 0,
    mysql: {columnName: 'instrument_symbol', dataType: 'varchar', dataLength: 30, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  instrumentSymbol: string;

  @property({
    type: 'string',
    required: true,
    precision: 10,
    scale: 0,
    generated: 0,
    mysql: {columnName: 'Instrument_token', dataType: 'varchar', dataLength: 50, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  instrumentToken: string;

  @property({
    type: 'number',
    precision: 10,
    scale: 0,
    generated: 1,
    id: 1,
    mysql: {columnName: 'ipid', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 1},
  })
  ipid?: number;

  @belongsTo(() => IpCatalog,{keyFrom: "catalogId"},{name:"catalog_id"})
  catalogId: number;
  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpInstrumentConfig>) {
    super(data);
  }
}

export interface IpInstrumentConfigRelations {
  // describe navigational properties here
}

export type IpInstrumentConfigWithRelations = IpInstrumentConfig & IpInstrumentConfigRelations;
