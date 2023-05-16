import {inject, Getter} from '@loopback/core';
import {DefaultCrudRepository, repository, BelongsToAccessor} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpMarketInstance, IpMarketInstanceRelations, IpMarketConfig} from '../models';
import {IpMarketConfigRepository} from './ip-market-config.repository';

export class IpMarketInstanceRepository extends DefaultCrudRepository<
  IpMarketInstance,
  typeof IpMarketInstance.prototype.ipid,
  IpMarketInstanceRelations
> {

  public readonly marketConfig: BelongsToAccessor<IpMarketConfig, typeof IpMarketInstance.prototype.ipid>;

  constructor(
    @inject('datasources.db') dataSource: DbDataSource, @repository.getter('IpMarketConfigRepository') protected ipMarketConfigRepositoryGetter: Getter<IpMarketConfigRepository>,
  ) {
    super(IpMarketInstance, dataSource);
    this.marketConfig = this.createBelongsToAccessorFor('marketConfig', ipMarketConfigRepositoryGetter,);
    this.registerInclusionResolver('marketConfig', this.marketConfig.inclusionResolver);
  }
}
