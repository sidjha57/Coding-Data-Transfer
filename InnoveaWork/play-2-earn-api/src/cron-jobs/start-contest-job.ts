import {CronJob, cronJob} from '@loopback/cron';
import {inject, Context} from '@loopback/context';

import {ContestStatusUpdateController} from '../controllers';

// Activate contests that start at 9:15 am IST
@cronJob()
export class StartContest915am extends CronJob {
  constructor(
    @inject.context() private ctx: Context,
    @inject('ContestStatusUpdateController')
    private contestStatusUpdateController: ContestStatusUpdateController,
  ) {
    super({
      name: 'activate-contest-9-15-am',
      onTick: () => {
        console.log(new Date());
        this.contestStatusUpdateController
          .start({
            startTime: '09:15',
          })
          .catch(err => {
            console.log('Error', err);
          });
      },
      cronTime: '0 15 9 * * *',
      timeZone: 'Asia/Kolkata',
      start: true,
    });
  }
}

// Activate contests that start at 10:00 am IST
@cronJob()
export class StartContest10am extends CronJob {
  constructor(
    @inject.context() private ctx: Context,
    @inject('ContestStatusUpdateController')
    private contestStatusUpdateController: ContestStatusUpdateController,
  ) {
    super({
      name: 'activate-contest-10-am',
      onTick: () => {
        console.log(new Date());
        this.contestStatusUpdateController
          .start({
            startTime: '10:00',
          })
          .catch(err => {
            console.log('Error', err);
          });
      },
      cronTime: '0 0 10 * * *',
      timeZone: 'Asia/Kolkata',
      start: true,
    });
  }
}

// Activate contests that start at 1:00 pm IST
@cronJob()
export class StartContest1pm extends CronJob {
  constructor(
    @inject.context() private ctx: Context,
    @inject('ContestStatusUpdateController')
    private contestStatusUpdateController: ContestStatusUpdateController,
  ) {
    super({
      name: 'activate-contest-1-pm',
      onTick: () => {
        console.log(new Date());
        this.contestStatusUpdateController
          .start({
            startTime: '13:00',
          })
          .catch(err => {
            console.log('Error', err);
          });
      },
      cronTime: '0 0 13 * * *',
      timeZone: 'Asia/Kolkata',
      start: true,
    });
  }
}
