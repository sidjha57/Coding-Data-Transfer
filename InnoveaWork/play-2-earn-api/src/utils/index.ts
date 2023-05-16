import moment from 'moment';

export const getDateOfMondayTwoWeeksFromNow = () => {
  // Get the date of next Monday
  const nextMonday = moment().add(1, 'weeks').startOf('isoWeek');

  // Get the date of the Monday two weeks from now
  const dateOfMondayTwoWeeksFromNow = moment(nextMonday).add(1, 'weeks');
  return dateOfMondayTwoWeeksFromNow.format('YYYY-MM-DD');
};
