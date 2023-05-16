import {inject} from '@loopback/core';
import {DefaultCrudRepository} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpPortfolioStatus, IpPortfolioStatusRelations} from '../models';

export class IpPortfolioStatusRepository extends DefaultCrudRepository<
  IpPortfolioStatus,
  typeof IpPortfolioStatus.prototype.ipid,
  IpPortfolioStatusRelations
> {
  constructor(
    @inject('datasources.db') dataSource: DbDataSource,
  ) {
    super(IpPortfolioStatus, dataSource);
  }
}
