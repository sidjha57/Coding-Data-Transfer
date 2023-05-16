import {CronJob, cronJob} from '@loopback/cron';
import {inject} from '@loopback/core';

import {ContestStatusUpdateController} from '../controllers';

// End contests at 3:30 pm IST
@cronJob()
export class EndContest330pm extends CronJob {
  constructor(
    @inject('ContestStatusUpdateController')
    protected contestStatusUpdateController: ContestStatusUpdateController,
  ) {
    super({
      name: 'end-contest-3-30-pm',
      onTick: () => {
        console.log(new Date());
        this.contestStatusUpdateController
          .end({
            endTime: '15:30',
          })
          .catch(err => {
            console.log('Error', err);
          });
      },
      cronTime: '0 30 15 * * *',
      timeZone: 'Asia/Kolkata',
      start: true,
    });
  }
}

// End contests at 12:00 pm IST
@cronJob()
export class EndContest12pm extends CronJob {
  constructor(
    @inject('ContestStatusUpdateController')
    protected contestStatusUpdateController: ContestStatusUpdateController,
  ) {
    super({
      name: 'end-contest-3-30-pm',
      onTick: () => {
        console.log(new Date());
        this.contestStatusUpdateController
          .end({
            endTime: '12:00',
          })
          .catch(err => {
            console.log('Error', err);
          });
      },
      cronTime: '0 0 12 * * *',
      timeZone: 'Asia/Kolkata',
      start: true,
    });
  }
}

// End contests at 3:00 pm IST
@cronJob()
export class EndContest3pm extends CronJob {
  constructor(
    @inject('ContestStatusUpdateController')
    protected contestStatusUpdateController: ContestStatusUpdateController,
  ) {
    super({
      name: 'end-contest-3-30-pm',
      onTick: () => {
        console.log(new Date());
        this.contestStatusUpdateController
          .end({
            endTime: '15:00',
          })
          .catch(err => {
            console.log('Error', err);
          });
      },
      cronTime: '0 0 15 * * *',
      timeZone: 'Asia/Kolkata',
      start: true,
    });
  }
}
