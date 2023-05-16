import { Entity, model, property, hasMany, hasOne } from '@loopback/repository';
import { IpPortfolioSelection } from './ip-portfolio-selection.model';
import { IpPortfolioScore } from './ip-portfolio-score.model';
import { IpPortfolioStatus } from './ip-portfolio-status.model';

@model({
  settings: {
    idInjection: false,
    mysql: { schema: 'innov-play', table: 'ip_portfolio_instance' }
  }
})
export class IpPortfolioInstance extends Entity {
  @property({
    type: 'number',
    precision: 10,
    scale: 0,
    generated: 0,
    mysql: { columnName: 'contest_single_day_id', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'Y', generated: 0 },
  })
  contestSingleDayId?: number;

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
    type: 'number',
    precision: 10,
    scale: 0,
    generated: 0,
    mysql: { columnName: 'user_id', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'Y', generated: 0 },
  })
  userId?: number;

  @hasMany(() => IpPortfolioSelection, { keyTo: 'portfolioId' })
  portfolioSelections: IpPortfolioSelection[];

  @hasOne(() => IpPortfolioScore, { keyTo: 'portfolioId' })
  score: IpPortfolioScore;

  @hasOne(() => IpPortfolioStatus, { keyTo: 'portfolioId' })
  status: IpPortfolioStatus;
  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpPortfolioInstance>) {
    super(data);
  }
}

export interface IpPortfolioInstanceRelations {
  // describe navigational properties here
}

export type IpPortfolioInstanceWithRelations = IpPortfolioInstance & IpPortfolioInstanceRelations;
