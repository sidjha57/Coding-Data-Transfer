import {Entity, model, property} from '@loopback/repository';

@model({
  settings: {idInjection: false, mysql: {schema: 'innov-play', table: 'ip_portfolio_score'}}
})
export class IpPortfolioScore extends Entity {
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
    mysql: {columnName: 'portfolio_id', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 0},
  })
  portfolioId: number;

  @property({
    type: 'number',
    precision: 22,
    generated: 0,
    mysql: {columnName: 'portfolio_score', dataType: 'double', dataLength: null, dataPrecision: 22, dataScale: null, nullable: 'Y', generated: 0},
  })
  portfolioScore?: number;

  @property({
    type: 'date',
    generated: 0,
    mysql: {columnName: 'updated_time_stamp', dataType: 'datetime', dataLength: null, dataPrecision: null, dataScale: null, nullable: 'Y', generated: 0},
  })
  updatedTimeStamp?: string;

  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpPortfolioScore>) {
    super(data);
  }
}

export interface IpPortfolioScoreRelations {
  // describe navigational properties here
}

export type IpPortfolioScoreWithRelations = IpPortfolioScore & IpPortfolioScoreRelations;
