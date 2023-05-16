import {inject, Getter} from '@loopback/core';
import {DefaultCrudRepository, repository, BelongsToAccessor} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpContestTypeConfig, IpContestTypeConfigRelations, IpMarketConfig, IpContestType} from '../models';
import {IpMarketConfigRepository} from './ip-market-config.repository';
import {IpContestTypeRepository} from './ip-contest-type.repository';

export class IpContestTypeConfigRepository extends DefaultCrudRepository<
  IpContestTypeConfig,
  typeof IpContestTypeConfig.prototype.ipid,
  IpContestTypeConfigRelations
> {

  public readonly market: BelongsToAccessor<IpMarketConfig, typeof IpContestTypeConfig.prototype.ipid>;

  public readonly contestType: BelongsToAccessor<IpContestType, typeof IpContestTypeConfig.prototype.ipid>;

  constructor(
    @inject('datasources.db') dataSource: DbDataSource, @repository.getter('IpMarketConfigRepository') protected ipMarketConfigRepositoryGetter: Getter<IpMarketConfigRepository>, @repository.getter('IpContestTypeRepository') protected ipContestTypeRepositoryGetter: Getter<IpContestTypeRepository>,
  ) {
    super(IpContestTypeConfig, dataSource);
    this.contestType = this.createBelongsToAccessorFor('contestType', ipContestTypeRepositoryGetter,);
    this.registerInclusionResolver('contestType', this.contestType.inclusionResolver);
    this.market = this.createBelongsToAccessorFor('market', ipMarketConfigRepositoryGetter,);
    this.registerInclusionResolver('market', this.market.inclusionResolver);
  }
}
