import React from "react"
import {
  LineChart,
  Line,
  XAxis,
  YAxis,
  CartesianGrid,
  Tooltip,
  ResponsiveContainer,
  ReferenceLine,
  Label,
} from "recharts"

interface Props {
  graphData: { time: string; score: number }[]
  tenthPercentile: number
  twentiethPercentile: number
}

const LineChartWithTargets: React.FC<Props> = ({
  graphData,
  tenthPercentile,
  twentiethPercentile,
}) => {
  const [chartWidth, setChartWidth] = React.useState(0)

  React.useEffect(() => {
    const handleResize = () => {
      setChartWidth(
        document.getElementById("chart-container")?.clientWidth || 0
      )
    }

    window.addEventListener("resize", handleResize)
    handleResize()
    return () => window.removeEventListener("resize", handleResize)
  }, [])

  const axisTickStyle = { fontSize: 10, fill: "black" }

  const getFilteredTicks = () => {
    const ticks = graphData.map((entry) => entry.time)
    return [
      ticks[0],
      ticks[Math.floor(ticks.length / 2)],
      ticks[ticks.length - 1],
    ]
  }

  return (
    <div id="chart-container" className="mx-auto" style={{ width: "90%" }}>
      <LineChart
        data={graphData}
        width={chartWidth}
        height={235}
        margin={{ left: -20, right: 30, top: 20 }}
        style={{ background: "white" }}
      >
        <CartesianGrid strokeDasharray="3 3" />
        <Tooltip
          contentStyle={{
            fontSize: "10px",
            padding: "1px 5px",
            background: "rgba(255, 255, 255, 0.8)",
            // border: 'none',
          }}
        />
        <XAxis
          dataKey="time"
          tick={{ style: axisTickStyle, strokeWidth: 1 }}
          ticks={getFilteredTicks()}
        />
        <YAxis tickCount={7} tick={{ style: axisTickStyle, strokeWidth: 1 }} />
        <Line
          type="monotone"
          dataKey="score"
          stroke="#03D09F"
          strokeWidth={2}
          dot={false}
        />
        <ReferenceLine
          y={tenthPercentile}
          stroke="#6ED65E"
          strokeWidth={1}
          label={{
            position: "right",
            value: "10%",
            style: { ...axisTickStyle, stroke: "#6ED65E" },
          }}
        >
          <Label />
        </ReferenceLine>
        <ReferenceLine
          y={twentiethPercentile}
          stroke="#F5B453"
          strokeWidth={1}
          label={{
            position: "right",
            value: "20%",
            style: { ...axisTickStyle, stroke: "#F5B453" },
          }}
        />
      </LineChart>
    </div>
  )
}

export default LineChartWithTargets
