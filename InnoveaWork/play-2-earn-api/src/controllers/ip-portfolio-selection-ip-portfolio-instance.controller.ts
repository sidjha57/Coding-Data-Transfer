import {
  repository,
} from '@loopback/repository';
import {
  param,
  get,
  getModelSchemaRef,
} from '@loopback/rest';
import {
  IpPortfolioSelection,
  IpPortfolioInstance,
} from '../models';
import {IpPortfolioSelectionRepository} from '../repositories';

export class IpPortfolioSelectionIpPortfolioInstanceController {
  constructor(
    @repository(IpPortfolioSelectionRepository)
    public ipPortfolioSelectionRepository: IpPortfolioSelectionRepository,
  ) { }

  @get('/portfolio-selections/{id}/portfolio-instance', {
    responses: {
      '200': {
        description: 'IpPortfolioInstance belonging to IpPortfolioSelection',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpPortfolioInstance)},
          },
        },
      },
    },
  })
  async getIpPortfolioInstance(
    @param.path.number('id') id: typeof IpPortfolioSelection.prototype.ipid,
  ): Promise<IpPortfolioInstance> {
    return this.ipPortfolioSelectionRepository.portfolio(id);
  }
}
