import React from "react"
import { ContestType } from "../interface/Contest"
import moment from "moment"

interface ContestStatusProps {
  contest: ContestType
  headerActive: boolean
}

type timeLeft = {
  days: number
  hours: number
  minutes: number
}

const ContestStatus = ({ contest, headerActive }: ContestStatusProps) => {
  const [startTime, setStartTime] = React.useState<timeLeft>()
  const [endTime, setEndTime] = React.useState<timeLeft>()

  function getTimeDifference(toDateTime: any) {
    const currentDateTime = moment().format().split('+')[0] + 'Z';

    const fromDateTime = moment(currentDateTime);
    const toDateTimeMoment = moment(toDateTime);  

    const duration = moment.duration(toDateTimeMoment.diff(fromDateTime));

    const days = duration.days();
    const hours = duration.hours();
    const minutes = duration.minutes();
  
    return {
      days: days,
      hours: hours,
      minutes: minutes,
    }
  }

  React.useEffect(() => {
    setStartTime(getTimeDifference(contest?.contestSessionStartTime))
    setEndTime(getTimeDifference(contest?.contestSessionEndTime))
  }, [contest.contestSessionStartTime, contest.contestSessionEndTime])

  return (
    <div className="mx-4">
      {headerActive && (
        <div className="grid grid-flow-col place-content-between my-[2px]">
          <div className="font-bold text-base">
            Daily Contest,{" "}
            {moment(contest.contestSessionStartTime).format("D MMM")}
          </div>
          <p className="p-2 grid place-content-center capitalize box-border text-center text-xs text-gray-700 rounded-2xl h-5 w-fit border border-gray-400">
            {contest.status.contestStatus}
          </p>
        </div>
      )}
      <div className=" grid grid-flow-col place-content-between">
        <div className="text-xs font-medium">
          {moment.utc(contest.contestSessionStartTime).format("h:mm A") +
            " - " +
            moment.utc(contest.contestSessionEndTime).format("h:mm A")}
        </div>
        <div className="text-xs font-medium">
          {contest.status.contestStatus === "LIVE" && (
            <span className="font-medium">
              Ends in
              <span className="text-[#93000A] font-bold ml-1">
                {endTime?.days ? endTime?.days + "d:" : ""}
                {endTime?.hours}h:{endTime?.minutes}m
              </span>
            </span>
          )}
          {contest.status.contestStatus === "UPCOMING" && (
            <span className="font-medium">
              Starts in
              <span className="text-[#93000A] font-bold ml-1">
                {startTime?.days ? startTime?.days + "d:" : ""}
                {startTime?.hours}h:{startTime?.minutes}m
              </span>
            </span>
          )}
        </div>
      </div>
    </div>
  )
}

export default ContestStatus
