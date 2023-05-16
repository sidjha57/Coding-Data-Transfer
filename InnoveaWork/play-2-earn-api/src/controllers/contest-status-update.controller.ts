import {repository} from '@loopback/repository';
import {
  IpContestSingleDayInstanceRepository,
  IpContestStatusRepository,
} from '../repositories';
import {post, requestBody, response} from '@loopback/openapi-v3';
import moment from 'moment';

// import {inject} from '@loopback/core';
const StartContestSchema = {
  description: 'Start Contest',
  content: {
    'application/json': {
      schema: {
        type: 'object',
        properties: {
          startTime: {
            type: 'string',
          },
          status: {
            type: 'string',
          },
        },
      },
    } as const,
  },
};

interface StartContest {
  startTime: string; // optional string formatted as a date
  status?: string; // one of these two strings
}

const EndContestSchema = {
  description: 'End Contest',
  content: {
    'application/json': {
      schema: {
        type: 'object',
        properties: {
          endTime: {
            type: 'string',
          },
          status: {
            type: 'string',
          },
        },
      },
    } as const,
  },
};

interface EndContest {
  endTime: string; // optional string formatted as a date
  status?: string; // one of these two strings
}

export class ContestStatusUpdateController {
  constructor(
    @repository(IpContestSingleDayInstanceRepository)
    public ipContestSingleDayInstanceRepository: IpContestSingleDayInstanceRepository,
    @repository(IpContestStatusRepository)
    public ipContestStatusRepository: IpContestStatusRepository,
  ) {}

  @post('/start-contest')
  @response(200, {
    description: 'Start Instance',
    content: {
      'application/json': {
        schema: {
          type: 'string',
          example: 'Succeed',
        },
      },
    },
  })
  async start(
    @requestBody(StartContestSchema)
    variable: Partial<StartContest>,
  ): Promise<String> {
    try {
      if (!variable?.status) {
        variable.status = 'LIVE';
      }
      const date = moment().format('YYYY-MM-DD');
      const time = variable.startTime;
      const dateTime = moment.utc(`${date}T${time}`).toISOString();
      console.log(dateTime);

      const filter = {
        fields: {
          ipid: true,
        },
        where: {
          contestSessionStartTime: dateTime,
        },
      };
      const ipids = await this.ipContestSingleDayInstanceRepository.find(
        filter,
      );

      const contestIds = <number[]>ipids.map(ip => ip.ipid);
      console.log(contestIds);
      await this.ipContestStatusRepository.updateAll(
        {contestStatus: variable.status},
        {contestId: {inq: contestIds}},
      );

      return 'Succeed';
    } catch (err) {
      console.log(err);
      return 'Failed';
    }
  }

  @post('/end-contest')
  @response(200, {
    description: 'End Instance',
    content: {
      'application/json': {
        schema: {
          type: 'string',
          example: 'Succeed',
        },
      },
    },
  })
  async end(
    @requestBody(EndContestSchema)
    variable: Partial<EndContest>,
  ): Promise<String> {
    try {
      console.log(variable);
      if (!variable?.status) {
        variable.status = 'COMPLETED';
      }
      const date = moment().format('YYYY-MM-DD');
      const time = variable.endTime;
      const dateTime = moment.utc(`${date}T${time}`).toISOString();
      console.log(dateTime);

      const filter = {
        fields: {
          ipid: true,
        },
        where: {
          contestSessionEndTime: dateTime,
        },
      };
      const ipids = await this.ipContestSingleDayInstanceRepository.find(
        filter,
      );

      const contestIds = <number[]>ipids.map(ip => ip.ipid);
      console.log(contestIds);
      await this.ipContestStatusRepository.updateAll(
        {contestStatus: variable.status},
        {contestId: {inq: contestIds}},
      );

      return 'Succeed';
    } catch (err) {
      console.log(err);
      return 'Failed';
    }
  }
}
