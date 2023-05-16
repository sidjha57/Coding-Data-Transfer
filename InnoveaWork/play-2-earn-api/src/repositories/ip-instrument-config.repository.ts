import {inject, Getter} from '@loopback/core';
import {DefaultCrudRepository, repository, BelongsToAccessor} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpInstrumentConfig, IpInstrumentConfigRelations, IpCatalog} from '../models';
import {IpCatalogRepository} from './ip-catalog.repository';

export class IpInstrumentConfigRepository extends DefaultCrudRepository<
  IpInstrumentConfig,
  typeof IpInstrumentConfig.prototype.ipid,
  IpInstrumentConfigRelations
> {

  public readonly catalog: BelongsToAccessor<IpCatalog, typeof IpInstrumentConfig.prototype.ipid>;

  constructor(
    @inject('datasources.db') dataSource: DbDataSource, @repository.getter('IpCatalogRepository') protected ipCatalogRepositoryGetter: Getter<IpCatalogRepository>,
  ) {
    super(IpInstrumentConfig, dataSource);
    this.catalog = this.createBelongsToAccessorFor('catalog', ipCatalogRepositoryGetter,);
    this.registerInclusionResolver('catalog', this.catalog.inclusionResolver);
  }
}
