import {inject} from '@loopback/core';
import {DefaultCrudRepository} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpMarketStatusAudit, IpMarketStatusAuditRelations} from '../models';

export class IpMarketStatusAuditRepository extends DefaultCrudRepository<
  IpMarketStatusAudit,
  typeof IpMarketStatusAudit.prototype.ipid,
  IpMarketStatusAuditRelations
> {
  constructor(
    @inject('datasources.db') dataSource: DbDataSource,
  ) {
    super(IpMarketStatusAudit, dataSource);
  }
}
