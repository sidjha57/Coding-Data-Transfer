import {
  repository,
} from '@loopback/repository';
import {
  param,
  get,
  getModelSchemaRef,
} from '@loopback/rest';
import {
  IpPortfolioScore,
  IpPortfolioInstance,
} from '../models';
import {IpPortfolioScoreRepository} from '../repositories';

export class IpPortfolioScoreIpPortfolioInstanceController {
  constructor(
    @repository(IpPortfolioScoreRepository)
    public ipPortfolioScoreRepository: IpPortfolioScoreRepository,
  ) { }

  // @get('/portfolio-scores/{id}/portfolio-instance', {
  //   responses: {
  //     '200': {
  //       description: 'IpPortfolioInstance belonging to IpPortfolioScore',
  //       content: {
  //         'application/json': {
  //           schema: {type: 'array', items: getModelSchemaRef(IpPortfolioInstance)},
  //         },
  //       },
  //     },
  //   },
  // })
  // async getIpPortfolioInstance(
  //   @param.path.number('id') id: typeof IpPortfolioScore.prototype.ipid,
  // ): Promise<IpPortfolioInstance> {
  //   return this.ipPortfolioScoreRepository.portfolio_id(id);
  // }
}
