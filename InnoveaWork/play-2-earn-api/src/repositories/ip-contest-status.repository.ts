import {inject} from '@loopback/core';
import {DefaultCrudRepository} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpContestStatus, IpContestStatusRelations} from '../models';

export class IpContestStatusRepository extends DefaultCrudRepository<
  IpContestStatus,
  typeof IpContestStatus.prototype.ipid,
  IpContestStatusRelations
> {
  constructor(
    @inject('datasources.db') dataSource: DbDataSource,
  ) {
    super(IpContestStatus, dataSource);
  }
}
