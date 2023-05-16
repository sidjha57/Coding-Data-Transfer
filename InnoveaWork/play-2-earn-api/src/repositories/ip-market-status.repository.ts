import {inject} from '@loopback/core';
import {DefaultCrudRepository} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpMarketStatus, IpMarketStatusRelations} from '../models';

export class IpMarketStatusRepository extends DefaultCrudRepository<
  IpMarketStatus,
  typeof IpMarketStatus.prototype.ipid,
  IpMarketStatusRelations
> {
  constructor(
    @inject('datasources.db') dataSource: DbDataSource,
  ) {
    super(IpMarketStatus, dataSource);
  }
}
