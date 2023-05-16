import {inject, Getter} from '@loopback/core';
import {DefaultCrudRepository, repository, HasManyRepositoryFactory, HasOneRepositoryFactory} from '@loopback/repository';
import {DbDataSource} from '../datasources';
import {IpPortfolioInstance, IpPortfolioInstanceRelations, IpPortfolioSelection, IpPortfolioScore, IpPortfolioStatus} from '../models';
import {IpPortfolioSelectionRepository} from './ip-portfolio-selection.repository';
import {IpPortfolioScoreRepository} from './ip-portfolio-score.repository';
import {IpPortfolioStatusRepository} from './ip-portfolio-status.repository';

export class IpPortfolioInstanceRepository extends DefaultCrudRepository<
  IpPortfolioInstance,
  typeof IpPortfolioInstance.prototype.ipid,
  IpPortfolioInstanceRelations
> {

  public readonly portfolioSelections: HasManyRepositoryFactory<IpPortfolioSelection, typeof IpPortfolioInstance.prototype.ipid>;

  public readonly score: HasOneRepositoryFactory<IpPortfolioScore, typeof IpPortfolioInstance.prototype.ipid>;

  public readonly status: HasOneRepositoryFactory<IpPortfolioStatus, typeof IpPortfolioInstance.prototype.ipid>;

  constructor(
    @inject('datasources.db') dataSource: DbDataSource, @repository.getter('IpPortfolioSelectionRepository') protected ipPortfolioSelectionRepositoryGetter: Getter<IpPortfolioSelectionRepository>, @repository.getter('IpPortfolioScoreRepository') protected ipPortfolioScoreRepositoryGetter: Getter<IpPortfolioScoreRepository>, @repository.getter('IpPortfolioStatusRepository') protected ipPortfolioStatusRepositoryGetter: Getter<IpPortfolioStatusRepository>,
  ) {
    super(IpPortfolioInstance, dataSource);
    this.status = this.createHasOneRepositoryFactoryFor('status', ipPortfolioStatusRepositoryGetter);
    this.registerInclusionResolver('status', this.status.inclusionResolver);
    this.score = this.createHasOneRepositoryFactoryFor('score', ipPortfolioScoreRepositoryGetter);
    this.registerInclusionResolver('score', this.score.inclusionResolver);
    this.portfolioSelections = this.createHasManyRepositoryFactoryFor('portfolioSelections', ipPortfolioSelectionRepositoryGetter,);
    this.registerInclusionResolver('portfolioSelections', this.portfolioSelections.inclusionResolver);
  }
}
