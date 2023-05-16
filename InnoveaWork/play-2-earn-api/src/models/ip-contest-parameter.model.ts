import {Entity, model, property} from '@loopback/repository';

@model({
  settings: {
    idInjection: false,
    mysql: {schema: 'innov-play', table: 'ip_contest_parameter'}
  }
})
export class IpContestParameter extends Entity {
  @property({
    type: 'number',
    precision: 22,
    generated: 0,
    jsonSchema: {
      minimum : 1,
      errorMessage : {
        minimum : "Booster1 cannot be less than 0"
      }
    },
    mysql: {columnName: 'booster1', dataType: 'double', dataLength: null, dataPrecision: 22, dataScale: null, nullable: 'Y', generated: 0},
  })
  booster1?: number;

  @property({
    type: 'number',
    precision: 22,
    generated: 0,
    jsonSchema: {
      minimum : 1,
      errorMessage : {
        minimum : "Booster2 cannot be less than 0"
      }
    },
    mysql: {columnName: 'booster2', dataType: 'double', dataLength: null, dataPrecision: 22, dataScale: null, nullable: 'Y', generated: 0},
  })
  booster2?: number;

  @property({
    type: 'number',
    precision: 22,
    generated: 0,
    jsonSchema: {
      minimum : 1,
      errorMessage : {
        minimum : "Booster3 cannot be less than 0"
      }
    },
    mysql: {columnName: 'booster3', dataType: 'double', dataLength: null, dataPrecision: 22, dataScale: null, nullable: 'Y', generated: 0},
  })
  booster3?: number;

  @property({
    type: 'number',
    required: true,
    precision: 10,
    scale: 0,
    generated: 0,
    default: 100000,
    jsonSchema: {
      minimum : 0,
      maximum : 100000,
      errorMessage : {
        minimum : "Number of Maximum Contest Portfolios cannot be less than 0"
      }
    },
    mysql: {columnName: 'contest_maximum_portfolios', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 0},
  })
  contestMaximumPortfolios: number;

  @property({
    type: 'number',
    required: true,
    precision: 10,
    scale: 0,
    generated: 0,
    default: 100,
    jsonSchema: {
      minimum : 100,
      errorMessage : {
        minimum : "Number of Minimum Contest Portfolios cannot be less than 100"
      }
    },
    mysql: {columnName: 'contest_minimum_portfolios', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 0},
  })
  contestMinimumPortfolios: number;

  @property({
    type: 'string',
    required: true,
    length: 10,
    generated: 0,
    default: "INR",
    mysql: {columnName: 'currency', dataType: 'varchar', dataLength: 10, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  currency: string;

  @property({
    type: 'number',
    required: true,
    precision: 10,
    scale: 0,
    generated: 0,
    jsonSchema: {
      minimum : 0,
      errorMessage : {
        minimum : "Entry amount cannot be less than 0"
      }
    },
    mysql: {columnName: 'entry_amount', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 0},
  })
  entryAmount: number;

  @property({
    type: 'number',
    required: true,
    precision: 10,
    scale: 0,
    generated: 0,
    default: 4,
    jsonSchema: {
      minimum : 0,
      errorMessage : {
        minimum : "Number of Instruments required cannot be less than 0"
      }
    },
    mysql: {columnName: 'instruments_required', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 0},
  })
  instrumentsRequired: number;

  @property({
    type: 'number',
    precision: 10,
    scale: 0,
    generated: 1,
    id: 1,
    mysql: { columnName: 'ipid', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 1 },
  })
  ipid?: number;

  @property({
    type: 'number',
    required: true,
    precision: 22,
    generated: 0,
    jsonSchema: {
      minimum : 0,
      errorMessage : {
        minimum : "Platform Commission amount cannot be less than 0"
      }
    },
    mysql: {columnName: 'platform_commission', dataType: 'double', dataLength: null, dataPrecision: 22, dataScale: null, nullable: 'N', generated: 0},
  })
  platformCommission: number;

  @property({
    type: 'number',
    required: true,
    precision: 10,
    scale: 0,
    generated: 0,
    default: 4,
    jsonSchema: {
      minimum : 0,
      errorMessage : {
        minimum : "Number of Maximum User Portfolios cannot be less than 0"
      }
    },
    mysql: {columnName: 'user_maximum_portfolios', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 0},
  })
  userMaximumPortfolios: number;

  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpContestParameter>) {
    super(data);
  }
}

export interface IpContestParameterRelations {
  // describe navigational properties here
}

export type IpContestParameterWithRelations = IpContestParameter & IpContestParameterRelations;
