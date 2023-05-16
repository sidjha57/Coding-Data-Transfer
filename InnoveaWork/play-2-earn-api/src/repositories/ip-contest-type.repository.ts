import {inject, Getter} from '@loopback/core';
import {DefaultCrudRepository, repository, BelongsToAccessor} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpContestType, IpContestTypeRelations, IpCatalog} from '../models';
import {IpCatalogRepository} from './ip-catalog.repository';

export class IpContestTypeRepository extends DefaultCrudRepository<
  IpContestType,
  typeof IpContestType.prototype.ipid,
  IpContestTypeRelations
> {

  public readonly catalog: BelongsToAccessor<IpCatalog, typeof IpContestType.prototype.ipid>;

  constructor(
    @inject('datasources.db') dataSource: DbDataSource, @repository.getter('IpCatalogRepository') protected ipCatalogRepositoryGetter: Getter<IpCatalogRepository>,
  ) {
    super(IpContestType, dataSource);
    this.catalog = this.createBelongsToAccessorFor('catalog', ipCatalogRepositoryGetter,);
    this.registerInclusionResolver('catalog', this.catalog.inclusionResolver);
  }
}
