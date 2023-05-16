import {CronJob, cronJob} from '@loopback/cron';
import {inject} from '@loopback/core';

import {ContestSingleDayMarketInstanceController} from '../controllers';

// Create market and contest instance on every friday at 10:00 pm IST
@cronJob()
export class CreateMarketContestInstance extends CronJob {
  constructor(
    @inject('ContestSingleDayMarketInstanceController')
    protected contestSingleDayMarketInstanceController: ContestSingleDayMarketInstanceController,
  ) {
    super({
      name: 'create-market-contest-instance-run-at-10pm-on-friday',
      onTick: () => {
        console.log(new Date());
        this.contestSingleDayMarketInstanceController
          .create({startDate: ''})
          .catch(err => {
            console.log('Error', err);
          });
      },
      cronTime: '0 0 22 * * 5',
      timeZone: 'Asia/Kolkata',
      start: true,
    });
  }
}
