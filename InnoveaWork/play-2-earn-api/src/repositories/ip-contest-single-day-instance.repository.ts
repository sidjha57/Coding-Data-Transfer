import {inject, Getter} from '@loopback/core';
import {DefaultCrudRepository, repository, BelongsToAccessor, HasOneRepositoryFactory} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpContestSingleDayInstance, IpContestSingleDayInstanceRelations, IpContestTypeConfig, IpMarketInstance, IpContestStatus} from '../models';
import {IpContestTypeConfigRepository} from './ip-contest-type-config.repository';
import {IpMarketInstanceRepository} from './ip-market-instance.repository';
import {IpContestStatusRepository} from './ip-contest-status.repository';

export class IpContestSingleDayInstanceRepository extends DefaultCrudRepository<
  IpContestSingleDayInstance,
  typeof IpContestSingleDayInstance.prototype.ipid,
  IpContestSingleDayInstanceRelations
> {

  public readonly contestTypeConfig: BelongsToAccessor<IpContestTypeConfig, typeof IpContestSingleDayInstance.prototype.ipid>;

  public readonly marketInstance: BelongsToAccessor<IpMarketInstance, typeof IpContestSingleDayInstance.prototype.ipid>;

  public readonly status: HasOneRepositoryFactory<IpContestStatus, typeof IpContestSingleDayInstance.prototype.ipid>;

  constructor(
    @inject('datasources.db') dataSource: DbDataSource, @repository.getter('IpContestTypeConfigRepository') protected ipContestTypeConfigRepositoryGetter: Getter<IpContestTypeConfigRepository>, @repository.getter('IpMarketInstanceRepository') protected ipMarketInstanceRepositoryGetter: Getter<IpMarketInstanceRepository>, @repository.getter('IpContestStatusRepository') protected ipContestStatusRepositoryGetter: Getter<IpContestStatusRepository>,
  ) {
    super(IpContestSingleDayInstance, dataSource);
    this.status = this.createHasOneRepositoryFactoryFor('status', ipContestStatusRepositoryGetter);
    this.registerInclusionResolver('status', this.status.inclusionResolver);
    this.marketInstance = this.createBelongsToAccessorFor('marketInstance', ipMarketInstanceRepositoryGetter,);
    this.registerInclusionResolver('marketInstance', this.marketInstance.inclusionResolver);
    this.contestTypeConfig = this.createBelongsToAccessorFor('contestTypeConfig', ipContestTypeConfigRepositoryGetter,);
    this.registerInclusionResolver('contestTypeConfig', this.contestTypeConfig.inclusionResolver);
  }
}
