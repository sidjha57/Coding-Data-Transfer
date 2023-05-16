import moment from 'moment';
export const tradingHolidays = [
  {
    tradingDate: '26-Jan-2023',
    weekDay: 'Thursday',
    description: 'Republic Day',
  },
  {
    tradingDate: '18-Feb-2023',
    weekDay: 'Saturday',
    description: 'Mahashivratri',
  },
  {
    tradingDate: '19-Feb-2023',
    weekDay: 'Sunday',
    description: 'Chatrapati Shivaji Maharaj Jayanti',
  },
  {
    tradingDate: '07-Mar-2023',
    weekDay: 'Tuesday',
    description: 'Holi',
  },
  {
    tradingDate: '22-Mar-2023',
    weekDay: 'Wednesday',
    description: 'Gudi Padwa',
  },
  {
    tradingDate: '30-Mar-2023',
    weekDay: 'Thursday',
    description: 'Ram Navami',
  },
  {
    tradingDate: '01-Apr-2023',
    weekDay: 'Saturday',
    description: 'Annual Bank Closing',
  },
  {
    tradingDate: '04-Apr-2023',
    weekDay: 'Tuesday',
    description: 'Mahavir Jayanti',
  },
  {
    tradingDate: '07-Apr-2023',
    weekDay: 'Friday',
    description: 'Good Friday',
  },
  {
    tradingDate: '14-Apr-2023',
    weekDay: 'Friday',
    description: 'Dr. Baba Saheb Ambedkar Jayanti',
  },
  {
    tradingDate: '22-Apr-2023',
    weekDay: 'Saturday',
    description: 'Id-Ul-Fitr (Ramzan ID)',
  },
  {
    tradingDate: '01-May-2023',
    weekDay: 'Monday',
    description: 'Maharashtra Day',
  },
  {
    tradingDate: '05-May-2023',
    weekDay: 'Friday',
    description: 'Buddha Pournima',
  },
  {
    tradingDate: '28-Jun-2023',
    weekDay: 'Wednesday',
    description: 'Bakri ID',
  },
  {
    tradingDate: '29-Jul-2023',
    weekDay: 'Saturday',
    description: 'Muharram',
  },
  {
    tradingDate: '15-Aug-2023',
    weekDay: 'Tuesday',
    description: 'Independence Day',
  },
  {
    tradingDate: '16-Aug-2023',
    weekDay: 'Wednesday',
    description: 'Parsi New Year',
  },
  {
    tradingDate: '19-Sep-2023',
    weekDay: 'Tuesday',
    description: 'Ganesh Chaturthi',
  },
  {
    tradingDate: '28-Sep-2023',
    weekDay: 'Thursday',
    description: 'Id-E-Milad',
  },
  {
    tradingDate: '02-Oct-2023',
    weekDay: 'Monday',
    description: 'Mahatma Gandhi Jayanti',
  },
  {
    tradingDate: '24-Oct-2023',
    weekDay: 'Tuesday',
    description: 'Dussehra',
  },
  {
    tradingDate: '12-Nov-2023',
    weekDay: 'Sunday',
    description: 'Diwali-Laxmi Pujan',
  },
  {
    tradingDate: '14-Nov-2023',
    weekDay: 'Tuesday',
    description: 'Diwali-Balipratipada',
  },
  {
    tradingDate: '27-Nov-2023',
    weekDay: 'Monday',
    description: 'Gurunanak Jayanti',
  },
  {
    tradingDate: '25-Dec-2023',
    weekDay: 'Monday',
    description: 'Christmas',
  },
];

export const checkMarketClose = (date: string) => {
  const marketDate = moment(date, 'YYYY-MM-DD');
  return tradingHolidays.some(({tradingDate}) => {
    const holidayDate = moment(tradingDate, 'DD-MMM-YYYY');
    return marketDate.isSame(holidayDate);
  });
};
