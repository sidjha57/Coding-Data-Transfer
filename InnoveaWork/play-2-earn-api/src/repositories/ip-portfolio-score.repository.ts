import {inject} from '@loopback/core';
import {DefaultCrudRepository} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpPortfolioScore, IpPortfolioScoreRelations} from '../models';

export class IpPortfolioScoreRepository extends DefaultCrudRepository<
  IpPortfolioScore,
  typeof IpPortfolioScore.prototype.ipid,
  IpPortfolioScoreRelations
> {
  constructor(
    @inject('datasources.db') dataSource: DbDataSource,
  ) {
    super(IpPortfolioScore, dataSource);
  }
}
