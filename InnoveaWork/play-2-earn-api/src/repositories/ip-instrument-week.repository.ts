import {inject, Getter} from '@loopback/core';
import {DefaultCrudRepository, repository, BelongsToAccessor} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpInstrumentWeek, IpInstrumentWeekRelations, IpInstrumentConfig} from '../models';
import {IpInstrumentConfigRepository} from './ip-instrument-config.repository';

export class IpInstrumentWeekRepository extends DefaultCrudRepository<
  IpInstrumentWeek,
  typeof IpInstrumentWeek.prototype.ipid,
  IpInstrumentWeekRelations
> {

  public readonly instrument: BelongsToAccessor<IpInstrumentConfig, typeof IpInstrumentWeek.prototype.ipid>;

  constructor(
    @inject('datasources.db') dataSource: DbDataSource, @repository.getter('IpInstrumentConfigRepository') protected ipInstrumentConfigRepositoryGetter: Getter<IpInstrumentConfigRepository>,
  ) {
    super(IpInstrumentWeek, dataSource);
    this.instrument = this.createBelongsToAccessorFor('instrument', ipInstrumentConfigRepositoryGetter,);
    this.registerInclusionResolver('instrument', this.instrument.inclusionResolver);
  }
}
