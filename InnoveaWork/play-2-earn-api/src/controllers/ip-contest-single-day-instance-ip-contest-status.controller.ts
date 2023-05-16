import {
  Count,
  CountSchema,
  Filter,
  repository,
  Where,
} from '@loopback/repository';
import {
  del,
  get,
  getModelSchemaRef,
  getWhereSchemaFor,
  param,
  patch,
  post,
  requestBody,
} from '@loopback/rest';
import {
  IpContestSingleDayInstance,
  IpContestStatus,
} from '../models';
import {IpContestSingleDayInstanceRepository} from '../repositories';

export class IpContestSingleDayInstanceIpContestStatusController {
  constructor(
    @repository(IpContestSingleDayInstanceRepository) protected ipContestSingleDayInstanceRepository: IpContestSingleDayInstanceRepository,
  ) { }

  @get('/ip-contest-single-day-instances/{id}/ip-contest-status', {
    responses: {
      '200': {
        description: 'IpContestSingleDayInstance has one IpContestStatus',
        content: {
          'application/json': {
            schema: getModelSchemaRef(IpContestStatus),
          },
        },
      },
    },
  })
  async get(
    @param.path.number('id') id: number,
    @param.query.object('filter') filter?: Filter<IpContestStatus>,
  ): Promise<IpContestStatus> {
    return this.ipContestSingleDayInstanceRepository.status(id).get(filter);
  }

  @post('/ip-contest-single-day-instances/{id}/ip-contest-status', {
    responses: {
      '200': {
        description: 'IpContestSingleDayInstance model instance',
        content: {'application/json': {schema: getModelSchemaRef(IpContestStatus)}},
      },
    },
  })
  async create(
    @param.path.number('id') id: typeof IpContestSingleDayInstance.prototype.ipid,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestStatus, {
            title: 'NewIpContestStatusInIpContestSingleDayInstance',
            exclude: ['ipid'],
            optional: ['contestId']
          }),
        },
      },
    }) ipContestStatus: Omit<IpContestStatus, 'ipid'>,
  ): Promise<IpContestStatus> {
    return this.ipContestSingleDayInstanceRepository.status(id).create(ipContestStatus);
  }

  @patch('/ip-contest-single-day-instances/{id}/ip-contest-status', {
    responses: {
      '200': {
        description: 'IpContestSingleDayInstance.IpContestStatus PATCH success count',
        content: {'application/json': {schema: CountSchema}},
      },
    },
  })
  async patch(
    @param.path.number('id') id: number,
    @requestBody({
      content: {
        'application/json': {
          schema: getModelSchemaRef(IpContestStatus, {partial: true}),
        },
      },
    })
    ipContestStatus: Partial<IpContestStatus>,
    @param.query.object('where', getWhereSchemaFor(IpContestStatus)) where?: Where<IpContestStatus>,
  ): Promise<Count> {
    return this.ipContestSingleDayInstanceRepository.status(id).patch(ipContestStatus, where);
  }

  @del('/ip-contest-single-day-instances/{id}/ip-contest-status', {
    responses: {
      '200': {
        description: 'IpContestSingleDayInstance.IpContestStatus DELETE success count',
        content: {'application/json': {schema: CountSchema}},
      },
    },
  })
  async delete(
    @param.path.number('id') id: number,
    @param.query.object('where', getWhereSchemaFor(IpContestStatus)) where?: Where<IpContestStatus>,
  ): Promise<Count> {
    return this.ipContestSingleDayInstanceRepository.status(id).delete(where);
  }
}
