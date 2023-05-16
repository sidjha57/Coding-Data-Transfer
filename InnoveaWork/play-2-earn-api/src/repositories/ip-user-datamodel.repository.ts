import {inject} from '@loopback/core';
import {DefaultCrudRepository} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpUserDatamodel, IpUserDatamodelRelations} from '../models';

export class IpUserDatamodelRepository extends DefaultCrudRepository<
  IpUserDatamodel,
  typeof IpUserDatamodel.prototype.ipid,
  IpUserDatamodelRelations
> {
  constructor(
    @inject('datasources.db') dataSource: DbDataSource,
  ) {
    super(IpUserDatamodel, dataSource);
  }
}
