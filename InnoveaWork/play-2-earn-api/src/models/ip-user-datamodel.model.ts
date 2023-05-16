import {Entity, model, property} from '@loopback/repository';

@model({
  settings: {idInjection: false, mysql: {schema: 'innov-play', table: 'ip_user_datamodel'}}
})
export class IpUserDatamodel extends Entity {
  @property({
    type: 'date',
    required: true,
    generated: 0,
    mysql: {columnName: 'account_create_timestamp', dataType: 'datetime', dataLength: null, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  accountCreateTimestamp: string;

  @property({
    type: 'date',
    generated: 0,
    mysql: {columnName: 'date_of_birth', dataType: 'datetime', dataLength: null, dataPrecision: null, dataScale: null, nullable: 'Y', generated: 0},
  })
  dateOfBirth?: string;

  @property({
    type: 'string',
    required: true,
    length: 45,
    generated: 0,
    jsonSchema: {
      format: 'email'
    },
    mysql: {columnName: 'email_id', dataType: 'varchar', dataLength: 45, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  emailId: string;

  @property({
    type: 'string',
    required: true,
    length: 30,
    generated: 0,
    mysql: {columnName: 'first_name', dataType: 'varchar', dataLength: 30, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  firstName: string;

  @property({
    type: 'number',
    precision: 10,
    scale: 0,
    generated: 1,
    id: 1,
    mysql: {columnName: 'ipid', dataType: 'int', dataLength: null, dataPrecision: 10, dataScale: 0, nullable: 'N', generated: 1},
  })
  ipid?: number;

  @property({
    type: 'string',
    required: true,
    length: 30,
    generated: 0,
    mysql: {columnName: 'last_name', dataType: 'varchar', dataLength: 30, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  lastName: string;

  @property({
    type: 'string',
    length: 30,
    generated: 0,
    mysql: {columnName: 'middle_name', dataType: 'varchar', dataLength: 30, dataPrecision: null, dataScale: null, nullable: 'Y', generated: 0},
  })
  middleName?: string;

  @property({
    type: 'string',
    required: true,
    length: 10,
    generated: 0,
    jsonSchema: {
      minLength: 10,
      maxLength: 10,
      pattern: '^[0-9]*$',
      errorMessage: {
        maxLength: 'Phone Number must be of 10 length',
        minLength: 'Phone Number must be of 10 length',
        pattern: 'Phone Number must contain only digits',
      },
    },
    mysql: {columnName: 'phone_number', dataType: 'varchar', dataLength: 10, dataPrecision: null, dataScale: null, nullable: 'N', generated: 0},
  })
  phoneNumber: string;

  @property({
    type: 'string',
    length: 10,
    generated: 0,
    mysql: {columnName: 'resident_location', dataType: 'varchar', dataLength: 10, dataPrecision: null, dataScale: null, nullable: 'Y', generated: 0},
  })
  residentLocation?: string;

  // Define well-known properties here

  // Indexer property to allow additional data
  // eslint-disable-next-line @typescript-eslint/no-explicit-any
  [prop: string]: any;

  constructor(data?: Partial<IpUserDatamodel>) {
    super(data);
  }
}

export interface IpUserDatamodelRelations {
  // describe navigational properties here
}

export type IpUserDatamodelWithRelations = IpUserDatamodel & IpUserDatamodelRelations;
