import {inject} from '@loopback/core';
import {DefaultCrudRepository} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpContestStatusAudit, IpContestStatusAuditRelations} from '../models';

export class IpContestStatusAuditRepository extends DefaultCrudRepository<
  IpContestStatusAudit,
  typeof IpContestStatusAudit.prototype.ipid,
  IpContestStatusAuditRelations
> {
  constructor(
    @inject('datasources.db') dataSource: DbDataSource,
  ) {
    super(IpContestStatusAudit, dataSource);
  }
}
