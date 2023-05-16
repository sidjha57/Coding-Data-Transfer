import {inject, Getter} from '@loopback/core';
import {DefaultCrudRepository, repository, BelongsToAccessor} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpInstrumentPrice, IpInstrumentPriceRelations, IpInstrumentConfig} from '../models';
import {IpInstrumentConfigRepository} from './ip-instrument-config.repository';

export class IpInstrumentPriceRepository extends DefaultCrudRepository<
  IpInstrumentPrice,
  typeof IpInstrumentPrice.prototype.ipid,
  IpInstrumentPriceRelations
> {

  public readonly instrument: BelongsToAccessor<IpInstrumentConfig, typeof IpInstrumentPrice.prototype.ipid>;

  constructor(
    @inject('datasources.db') dataSource: DbDataSource, @repository.getter('IpInstrumentConfigRepository') protected ipInstrumentConfigRepositoryGetter: Getter<IpInstrumentConfigRepository>,
  ) {
    super(IpInstrumentPrice, dataSource);
    this.instrument = this.createBelongsToAccessorFor('instrument', ipInstrumentConfigRepositoryGetter,);
    this.registerInclusionResolver('instrument', this.instrument.inclusionResolver);
  }
}
