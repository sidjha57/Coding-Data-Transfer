import {inject, Getter} from '@loopback/core';
import {DefaultCrudRepository, repository, BelongsToAccessor} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpPortfolioSelection, IpPortfolioSelectionRelations, IpPortfolioInstance, IpInstrumentConfig} from '../models';
import {IpPortfolioInstanceRepository} from './ip-portfolio-instance.repository';
import {IpInstrumentConfigRepository} from './ip-instrument-config.repository';

export class IpPortfolioSelectionRepository extends DefaultCrudRepository<
  IpPortfolioSelection,
  typeof IpPortfolioSelection.prototype.ipid,
  IpPortfolioSelectionRelations
> {

  public readonly portfolio: BelongsToAccessor<IpPortfolioInstance, typeof IpPortfolioSelection.prototype.ipid>;

  public readonly instrument: BelongsToAccessor<IpInstrumentConfig, typeof IpPortfolioSelection.prototype.ipid>;

  constructor(
    @inject('datasources.db') dataSource: DbDataSource, @repository.getter('IpPortfolioInstanceRepository') protected ipPortfolioInstanceRepositoryGetter: Getter<IpPortfolioInstanceRepository>, @repository.getter('IpInstrumentConfigRepository') protected ipInstrumentConfigRepositoryGetter: Getter<IpInstrumentConfigRepository>,
  ) {
    super(IpPortfolioSelection, dataSource);
    this.instrument = this.createBelongsToAccessorFor('instrument', ipInstrumentConfigRepositoryGetter,);
    this.registerInclusionResolver('instrument', this.instrument.inclusionResolver);
    this.portfolio = this.createBelongsToAccessorFor('portfolio', ipPortfolioInstanceRepositoryGetter,);
    this.registerInclusionResolver('portfolio', this.portfolio.inclusionResolver);
  }
}
