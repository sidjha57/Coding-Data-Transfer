import {inject} from '@loopback/core';
import {DefaultCrudRepository} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpContestParameter, IpContestParameterRelations} from '../models';

export class IpContestParameterRepository extends DefaultCrudRepository<
  IpContestParameter,
  typeof IpContestParameter.prototype.ipid,
  IpContestParameterRelations
> {
  constructor(
    @inject('datasources.db') dataSource: DbDataSource,
  ) {
    super(IpContestParameter, dataSource);
  }
}
