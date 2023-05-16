import React, { useEffect, useRef } from 'react';
import Chart from 'chart.js/auto';


const LineChart = () => {
  const chartRef = useRef(null);
  const xData = ["3:24","3:29","3:34","3:39","3:44", "3:49", "3:54", "3:59"];
  const yData = [-190, 20, 23, -110, 35, 60, 70, 90];

  useEffect(() => {
    const chartCanvas = chartRef.current.getContext('2d');
    const gradient = chartCanvas.createLinearGradient(0, 0, 0, 400);
    gradient.addColorStop(0, 'rgba(75, 192, 192, 0.4)');
    gradient.addColorStop(1, 'rgba(75, 192, 192, 0.1)');

    const chart = new Chart(chartCanvas, {
      type: 'line',
      data: {
        labels: xData,
        datasets: [
          {
            label: 'Data',
            data: yData,
            backgroundColor: gradient,
            borderColor: 'green',
            pointBackgroundColor: 'green',
            pointRadius: 5,
            pointHoverRadius: 8,
            borderWidth: 2,
          },
        ],
      },
      options: {
        scales: {
          y: 
            {
              ticks: {
                beginAtZero: false,
                position: 'right',
                // callback: (value) => `${value}`,
              },
              axis: {
                position: 'right'
              }
            },
          
        },
        legend: {
          display: false,
        },
        annotation: {
            annotations: [
              {
                type: 'line',
                mode: 'horizontal',
                scaleID: 'y-axis-0',
                value: 100,
                borderColor: 'red',
                borderWidth: 2,
                label: {
                  content: 'Top 10%',
                  enabled: true,
                  position: 'left',
                },
              },
              {
                type: 'line',
                mode: 'horizontal',
                scaleID: 'y-axis-0',
                value: 50,
                borderColor: 'orange',
                borderWidth: 2,
                label: {
                  content: 'Top 20%',
                  enabled: true,
                  position: 'left',
                },
              },
            ],
          },
        },
      });

    return () => {
      chart.destroy();
    };
  }, [xData, yData]);

  return <canvas ref={chartRef} />;
};

export default LineChart;
