import {CronJob, cronJob} from '@loopback/cron';

// Activate contests that start at 9:15 am IST
@cronJob()
export class StartContest915am extends CronJob {
  constructor() {
    super({
      name: 'activate-contest-9-15-am',
      onTick: () => {
        console.log(new Date());
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
  constructor() {
    super({
      name: 'activate-contest-10-am',
      onTick: () => {
        console.log(new Date());
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
  constructor() {
    super({
      name: 'activate-contest-1-pm',
      onTick: () => {
        console.log(new Date());
      },
      cronTime: '0 0 13 * * *',
      timeZone: 'Asia/Kolkata',
      start: true,
    });
  }
}
