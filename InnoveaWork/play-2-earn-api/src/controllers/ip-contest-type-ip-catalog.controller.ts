import {
  repository,
} from '@loopback/repository';
import {
  param,
  get,
  getModelSchemaRef,
} from '@loopback/rest';
import {
  IpContestType,
  IpCatalog,
} from '../models';
import {IpContestTypeRepository} from '../repositories';

export class IpContestTypeIpCatalogController {
  constructor(
    @repository(IpContestTypeRepository)
    public ipContestTypeRepository: IpContestTypeRepository,
  ) { }

  @get('/contest-types/{id}/catalog', {
    responses: {
      '200': {
        description: 'IpCatalog belonging to IpContestType',
        content: {
          'application/json': {
            schema: {type: 'array', items: getModelSchemaRef(IpCatalog)},
          },
        },
      },
    },
  })
  async getIpCatalog(
    @param.path.number('id') id: typeof IpContestType.prototype.ipid,
  ): Promise<IpCatalog> {
    return this.ipContestTypeRepository.catalog(id);
  }
}
