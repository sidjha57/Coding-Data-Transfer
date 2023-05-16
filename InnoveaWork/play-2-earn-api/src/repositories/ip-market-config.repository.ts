import {inject, Getter} from '@loopback/core';
import {DefaultCrudRepository, repository, HasManyRepositoryFactory} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpMarketConfig, IpMarketConfigRelations, IpMarketInstance} from '../models';
import {IpMarketInstanceRepository} from './ip-market-instance.repository';

export class IpMarketConfigRepository extends DefaultCrudRepository<
  IpMarketConfig,
  typeof IpMarketConfig.prototype.ipid,
  IpMarketConfigRelations
> {

  public readonly marketInstances: HasManyRepositoryFactory<IpMarketInstance, typeof IpMarketConfig.prototype.ipid>;

  constructor(
    @inject('datasources.db') dataSource: DbDataSource, @repository.getter('IpMarketInstanceRepository') protected ipMarketInstanceRepositoryGetter: Getter<IpMarketInstanceRepository>,
  ) {
    super(IpMarketConfig, dataSource);
    this.marketInstances = this.createHasManyRepositoryFactoryFor('marketInstances', ipMarketInstanceRepositoryGetter,);
    this.registerInclusionResolver('marketInstances', this.marketInstances.inclusionResolver);
  }
}
