import {inject} from '@loopback/core';
import {DefaultCrudRepository} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpPortfolioStatusAudit, IpPortfolioStatusAuditRelations} from '../models';

export class IpPortfolioStatusAuditRepository extends DefaultCrudRepository<
  IpPortfolioStatusAudit,
  typeof IpPortfolioStatusAudit.prototype.ipid,
  IpPortfolioStatusAuditRelations
> {
  constructor(
    @inject('datasources.db') dataSource: DbDataSource,
  ) {
    super(IpPortfolioStatusAudit, dataSource);
  }
}
