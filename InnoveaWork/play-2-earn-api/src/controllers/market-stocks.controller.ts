// Uncomment these imports to begin using these cool features!

// import {inject} from '@loopback/core';


import { get, param, post } from '@loopback/openapi-v3';
import { Exchange, KiteConnect } from 'kiteconnect-ts';
import {IpInstrumentConfigRepository,IpInstrumentPriceRepository,IpPortfolioSelectionRepository,IpInstrumentWeekRepository,IpPortfolioInstanceRepository} from '../repositories';
import { DataObject, repository } from '@loopback/repository';
import { IpInstrumentConfig, IpPortfolioSelection, IpPortfolioSelectionRelations } from '../models';
import { BindingScope,bind } from '@loopback/context';

@bind({scope: BindingScope.SINGLETON})
export class MarketStocksController {
  kc: KiteConnect;
  requestToken: string;
  apiSecret = '88iut8whmy8mp8kktjn8ob5014eh4dr6';
  constructor(
    @repository(IpInstrumentConfigRepository)
    public ipInstrumentConfigRepository: IpInstrumentConfigRepository,
    @repository(IpInstrumentPriceRepository)
    public ipInstrumentPriceRepository: IpInstrumentPriceRepository,
    @repository(IpPortfolioSelectionRepository)
    public ipPortfolioSelectionRepository: IpPortfolioSelectionRepository,
    @repository(IpInstrumentWeekRepository)
    public ipInstrumentWeekRepository: IpInstrumentWeekRepository,
    @repository(IpPortfolioInstanceRepository)
    public ipPortfolioInstanceRepository: IpPortfolioInstanceRepository,
  ) {
    this.kc = new KiteConnect({
      // eslint-disable-next-line @typescript-eslint/naming-convention
      api_key: 'zo4efbkqj0i2ojpy',
    });
    // console.log('Login URL', this.kc.getLoginURL());
  }

  @get('/setSessiontoken/')
  async setAccessToken(
    @param.query.string('request_token') token: string,
    ) {
    // console.log('Getting new token', token);
    // console.log(this.kc.getLoginURL());
    this.requestToken = token;
    try {
      const accessToken = await this.kc.generateSession(token,this.apiSecret );
      // console.log('Received token', accessToken);
      return {
        success: 'Token set successfully',
      };
    } catch (error) {
      // console.log('Session error', error);
      return {
        error: 'Error seting token',
        msg: error,
      };
    }
  }
  @post('/update-stock-prices')
  async updateStockPrices() {
    try {
      // console.log(this.requestToken,this.apiSecret)
      // await this.kc.generateSession(this.requestToken,this.apiSecret)
      const stocks = await this.ipInstrumentConfigRepository.find();
      // console.log(stocks.length)
      const reqStock = stocks.map(s => 'NSE:' + s.instrumentSymbol);
      const n = reqStock.length;
      // console.log(n)

      const len = 400;
      const pArr = [];
      // console.log(this.kc)
      // console.log(reqStock[10])

      pArr.push(this.kc.getQuote(reqStock.slice(0, len)));

      // for (let i = 1; i < n / len - 1; i++) {
        // console.log(i * len + 1, (i + 1) * len);
      //   pArr.push(this.kc.getOHLC(reqStock.slice(i * len + 1, (i + 1) * len)));
      // }

      const quotes = await Promise.all(pArr);
      // console.log(quotes[0],quotes[0].ohlc);
    } catch (error) {
      // console.log(error);
    }
  }
  @post('/update-marketstocks')
  async updateKiteStocks() {
    try {
      const ex:Exchange[]= [this.kc['EXCHANGE_NSE']];
      const stocks = await this.kc.getInstruments(ex);
      // console.log(stocks[0])
      // await this.ipInstrumentPriceRepository.deleteAll();
      // await this.ipInstrumentConfigRepository.deleteAll();
      const newStocks:DataObject<IpInstrumentConfig>[]|void[] = stocks
      .filter((st) => st.name && st.last_price === 0 )
      .map( s=>
        {
          const stk: DataObject<IpInstrumentConfig>={
            catalogId:1,
            instrumentName:s.name,
            instrumentSymbol:s.tradingsymbol,
            instrumentToken:s.instrument_token
          };
         return stk;
      }
      )
      await this.ipInstrumentConfigRepository.createAll(newStocks);

      return {
        successs: `${newStocks.length} stocks created`,
      };
    } catch (error) {
      // console.log(error);
    }
  }
  @get('/get-portfolio-rank/{contestId}/{weekId}')
  async getPortfolioRank(
    @param.path.number('contestId') contestId: number,
    // @param.path.number('portfolioId') portfolioId: number,
    @param.path.number('weekId') weekId: number,
    ) {
    // console.log('Get portfoilio rank: ', contestId);


    const portfoilioIds = await this.ipPortfolioInstanceRepository.find(
      {
        where :{
          contestSingleDayId :353
        }
      }
    )

    const idSet = new Set(); 
    portfoilioIds.forEach(p=> idSet.add(p.ipid))
    // console.log("port",idSet);



    const portfolio = await this.ipPortfolioSelectionRepository.find({
        where:{
        portfolioId:{ inq: [...idSet] } 
      }
    })
    
    // console.log("portf",portfolio)

      
    const instruments = await this.ipInstrumentWeekRepository.find({
      where:{
      weekNumber:weekId
    },
    include:["instrument"]
  })
    
  // console.log("ins",instruments);
  const tokens = instruments.map((i)=>  'NSE:' + i.instrument.instrumentSymbol)
  // console.log("ins",tokens);

  const tokenIdMap=  new Map();
  instruments.forEach((i)=> {
    tokenIdMap.set(i.instrument.instrumentToken  ,{id:i.instrumentId,name:i.instrument.instrumentSymbol})
  })
  // console.log("Map",tokenIdMap);

  const perChangeMap = new Map();
  try {
    
    const quotes = await this.kc.getQuote(tokens);
    // console.log("Qte",quotes);

    // quotes.forEach(qt => {
    for (const key in quotes) {
      if (Object.prototype.hasOwnProperty.call(quotes, key)) {
        const qt = quotes[key];
        //  Calculate the percentage change
        const lastPrice = qt.last_price;
        const prevClose = qt.ohlc.open;
        const percentageChange = ((lastPrice - prevClose) / prevClose) * 100;
        // console.log(qt.instrument_token.toString(),percentageChange);
        
        perChangeMap.set(tokenIdMap.get(qt.instrument_token.toString()).id,{
          name:(tokenIdMap.get(qt.instrument_token.toString())).name,
          change:percentageChange})
      }
    }
       
    // console.log("PerChange",perChangeMap);
  } catch (error) {
    // console.log("Errr",error)
  }
    return this.getPortfolioPoints(perChangeMap,portfolio);
    
  }

  getPortfolioPoints(percentChangeMap:any, portfoilioSelection:(IpPortfolioSelection & IpPortfolioSelectionRelations)[]) {
    const score =new Map();
    // console.log("port",portfoilioSelection,percentChangeMap);
    for (const ps of portfoilioSelection) {
      // console.log(ps.instrumentSelection , ps.boosterSelection , percentChangeMap.get(ps.instrumentId));
      const instrumentVal =ps.instrumentSelection * 100 * ps.boosterSelection * percentChangeMap.get(ps.instrumentId).change;
      if(score.get(ps.portfolioId)){
        score.get(ps.portfolioId)[ps.instrumentId] = {name:percentChangeMap.get(ps.instrumentId).name, score:instrumentVal};
        score.get(ps.portfolioId)['total']+= instrumentVal;
      }else{
        score.set(ps.portfolioId,{
          [ps.instrumentId]:{name:percentChangeMap.get(ps.instrumentId).name, score:instrumentVal},
          total : instrumentVal
        })
      }
      
    }
  
    // console.log("score",score)
    return this.getRanks(Object.fromEntries(score));
  }

  getRanks(scoreMap:any){
   
    // Convert the object into an array of objects
    const arr = Object.keys(scoreMap).map(key => ({ id: key, ...scoreMap[key] }));

    // Sort the array based on the `total` property in descending order
    arr.sort((a, b) => b.total - a.total);

    // Assign rank to each object
    arr.forEach((item, index) => {
      item.rank = index + 1;
    });

    // Convert the array back into an object with `id` as the key
    const rankedObj:any = {};
    arr.forEach(item => {
      const { id, ...rest } = item;
      rankedObj[id] = rest;
    });

    // console.log(rankedObj);
    return rankedObj;

  }
}
