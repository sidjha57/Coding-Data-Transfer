import {Entity, model, property, hasMany} from '@loopback/repository';
import {IpInstrumentConfig} from './ip-instrument-config.model';

@model({
  settings: {idInjection: false, mysql: {schema: 'innov-play', table: 'ip_catalog'}}
})
export class IpCatalog extends Entity {
  @property({
    type: 'string',
    required: true,
    length: 10,
    generated: 0,
    mysql: {columnName: 'catalog', dataType: 'varchar', dataLength: 10, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  catalog: string;

  @property({
    type: 'number',
    precision: 10,
    scale: 0,
    generated: 1,
    id: 1,
    mysql: { columnName: 'ipid', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 1 },
  })
  ipid?: number;

  @hasMany(() => IpInstrumentConfig, {keyTo: 'catalogId'})
  InstrumentConfig: IpInstrumentConfig[];
  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpCatalog>) {
    super(data);
  }
}

export interface IpCatalogRelations {
  // describe navigational properties here
}

export type IpCatalogWithRelations = IpCatalog & IpCatalogRelations;
