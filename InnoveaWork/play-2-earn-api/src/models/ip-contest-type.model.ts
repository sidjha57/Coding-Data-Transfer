import {Entity, model, property, belongsTo} from '@loopback/repository';
import {IpCatalog} from './ip-catalog.model';

@model({
  settings: {idInjection: false, mysql: {schema: 'innov-play', table: 'ip_contest_type'}}
})
export class IpContestType extends Entity {
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
    type: 'string',
    required: true,
    length: 15,
    generated: 0,
    mysql: {columnName: 'name', dataType: 'varchar', dataLength: 15, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  name: string;

  @belongsTo(() => IpCatalog, {keyFrom: 'catalogId'}, {name: 'catalog_id'})
  catalogId: number;
  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpContestType>) {
    super(data);
  }
}

export interface IpContestTypeRelations {
  // describe navigational properties here
}

export type IpContestTypeWithRelations = IpContestType & IpContestTypeRelations;
