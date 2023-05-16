export interface ContestType {
    contestSessionStartTime : string,
    contestSessionEndTime : string,
    contestTypeConfigId : number,
    ipid : number,
    marketInstanceId : number,
    status : {
        contestStatus : string
    }
}