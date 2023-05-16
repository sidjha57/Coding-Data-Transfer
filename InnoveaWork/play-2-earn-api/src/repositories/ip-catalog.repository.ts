import {inject, Getter} from '@loopback/core';
import {DefaultCrudRepository, repository, HasManyRepositoryFactory} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpCatalog, IpCatalogRelations, IpInstrumentConfig} from '../models';
import {IpInstrumentConfigRepository} from './ip-instrument-config.repository';

export class IpCatalogRepository extends DefaultCrudRepository<
  IpCatalog,
  typeof IpCatalog.prototype.ipid,
  IpCatalogRelations
> {

  public readonly InstrumentConfig: HasManyRepositoryFactory<IpInstrumentConfig, typeof IpCatalog.prototype.ipid>;

  constructor(
    @inject('datasources.db') dataSource: DbDataSource, @repository.getter('IpInstrumentConfigRepository') protected ipInstrumentConfigRepositoryGetter: Getter<IpInstrumentConfigRepository>,
  ) {
    super(IpCatalog, dataSource);
    this.InstrumentConfig = this.createHasManyRepositoryFactoryFor('InstrumentConfig', ipInstrumentConfigRepositoryGetter,);
    this.registerInclusionResolver('InstrumentConfig', this.InstrumentConfig.inclusionResolver);
  }
}
