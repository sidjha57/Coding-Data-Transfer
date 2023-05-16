import React, { useEffect, useRef } from 'react';
import * as d3 from 'd3';

const LineD3 = () => {
  const chartRef = useRef(null);
  const xData = ['3:24', '3:29', '3:34', '3:39', '3:44'];
  const yData = [-190, 20, 23, -110, 35];

  useEffect(() => {
    const margin = { top: 20, right: 20, bottom: 30, left: 50 };
    const width = 600 - margin.left - margin.right;
    const height = 400 - margin.top - margin.bottom;

    const chartSvg = d3.select(chartRef.current)
      .attr('width', width + margin.left + margin.right)
      .attr('height', height + margin.top + margin.bottom);

    const chartGroup = chartSvg.append('g')
      .attr('transform', `translate(${margin.left}, ${margin.top})`);

    const xScale = d3.scalePoint()
      .domain(xData)
      .range([0, width]);

    const yScale = d3.scaleLinear()
      .domain([d3.min(yData) - 10, d3.max(yData) + 10])
      .range([height, 0]);

    const line = d3.line()
      .x((d, i) => xScale(xData[i]))
      .y(d => yScale(d))
      .curve(d3.curveCatmullRom.alpha(0.5));

    const gradient = chartGroup.append('linearGradient')
      .attr('id', 'gradient')
      .attr('gradientUnits', 'userSpaceOnUse')
      .attr('x1', 0)
      .attr('y1', yScale(0))
      .attr('x2', 0)
      .attr('y2', yScale(d3.max(yData)))
      .selectAll('stop')
      .data([
        { offset: '0%', color: 'rgba(75, 192, 192, 0.4)' },
        { offset: '100%', color: 'rgba(75, 192, 192, 0.1)' },
      ])
      .enter()
      .append('stop')
      .attr('offset', d => d.offset)
      .attr('stop-color', d => d.color);

    chartGroup.append('path')
      .datum(yData)
      .attr('class', 'line')
      .attr('d', line)
      .attr('stroke', 'green')
      .attr('stroke-width', 2)
      .attr('fill', 'url(#gradient)');

    const yAxis = d3.axisRight(yScale)
      .tickSize(width)
      .tickFormat(d => d);

    chartGroup.append('g')
      .attr('class', 'y axis')
      .call(yAxis);

    chartGroup.selectAll('.y.axis .tick line')
      .attr('stroke', '#ccc')
      .attr('stroke-dasharray', '2,2');

    chartGroup.selectAll('.y.axis .tick text')
      .attr('x', 4)
      .attr('dy', -4);

    const yCoord = 20;
    chartGroup.append('line')
      .attr('class', 'y-coordinate')
      .attr('x1', 0)
      .attr('y1', yScale(yCoord))
      .attr('x2', width)
      .attr('y2', yScale(yCoord))
      .attr('stroke', 'red')
      .attr('stroke-width', 1)
      .attr('stroke-dasharray', '4');
    
    chartGroup.append('text')
      .attr('class', 'y-coordinate-label')
      .attr('x', width + 10)
      .attr('y', yScale(yCoord) - 10)
      .attr('text-anchor', 'start')
      .attr('font-size', '12px')
      .attr('fill', 'red')
      .text(`Y-Coordinate: ${yCoord}`);
    
    const top10Percent = yScale(d3.quantile(yData, 0.9));
    chartGroup.append('line')
      .attr('class', 'top-10-percent')
      .attr('x1', 0)
      .attr('y1', top10Percent)
      .attr('x2', width)
      .attr('y2', top10Percent)
      .attr('stroke', 'red')
      .attr('stroke-width', 1)
      .attr('stroke-dasharray', '4');
    
    chartGroup.append('text')
      .attr('class', 'top-10-percent-label')
      .attr('x', width + 10)
      .attr('y', top10Percent - 10)
      .attr('text-anchor', 'start')
      .attr('font-size', '12px')
      .attr('fill', 'red')
      .text('Top 10%');
    
    const top20Percent = yScale(d3.quantile(yData, 0.8));
    chartGroup.append('line')
      .attr('class', 'top-20-percent')
      .attr('x1', 0)
      .attr('y1', top20Percent)
      .attr('x2', width)
      .attr('y2', top20Percent)
      .attr('stroke', 'orange')
      .attr('stroke-width', 1)
      .attr('stroke-dasharray', '4');
    
    chartGroup.append('text')
      .attr('class', 'top-20-percent-label')
      .attr('x', width + 10)
      .attr('y', top20Percent - 10)
      .attr('text-anchor', 'start')
      .attr('font-size', '12px')
      .attr('fill', 'orange')
      .text('Top 20%');
    
    }, []);

    return (
    <svg ref={chartRef}></svg>
    );
    };
    
    export default LineD3;