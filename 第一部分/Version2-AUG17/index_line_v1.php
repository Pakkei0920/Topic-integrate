<!DOCTYPE html>
<html>
<head>
    <title>Dynamically Updated Highcharts Example</title>
    <script src="https://code.highcharts.com/highcharts.js"></script>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
</head>
<body>
    <div id="container1" style="width: 100%;"></div>
    <div id="container2" style="width: 100%;"></div>
    <div id="container3" style="width: 100%;"></div>
    <div id="container4" style="width: 100%;"></div>
    <div id="container5" style="width: 100%;"></div>
    <div id="container6" style="width: 100%;"></div>

       <script type="text/javascript">
        function fetchData() {
            $.ajax({
                url: '/topics/fetch_data.php',
                type: 'GET',
                dataType: 'json',
                success: function(data) {
                    // Update the charts with the new data
                    chart1.series[0].setData(data.dht22_temp1Data);
                    chart1.series[1].setData(data.dht22_temp2Data);
                    chart1.series[2].setData(data.bmp_tempData);
                    chart1.series[3].setData(data.cwb_tempData);

                    chart2.series[0].setData(data.dht22_humd1Data);
                    chart2.series[1].setData(data.dht22_humd2Data);
                    chart2.series[2].setData(data.cwb_humd);
					
					chart3.series[0].setData(data.esp_pm1Data);
                    
                    chart4.series[0].setData(data.esp_pm25Data);
                    chart4.series[1].setData(data.epa_pm25Data);

                    chart5.series[0].setData(data.esp_pm100Data);
                    chart5.series[1].setData(data.epa_pm10Data);
                    
                    chart6.series[0].setData(data.bmp_pressureData);
                }
            });
        }

        // Fetch data initially
        fetchData();

        // Fetch data every 5 seconds
        setInterval(fetchData, 5000);

        // Create chart variables
        var chart1, chart2, chart3, chart4, chart5, chart6;

        // Create charts once the document is ready
        $(document).ready(function() {
            chart1 = Highcharts.chart('container1', {
                title: {
                    text: 'Temperature (°C)'
                },
                xAxis: {
                    type: 'datetime',
                    dateTimeLabelFormats: {
                        second: '%m-%d<br/>%H:%M:%S',
                        minute: '%m-%d<br/>%H:%M',
                        hour: '%m-%d<br/>%H:%M',
                        day: '%m-%d',
                        week: '%m-%d',
                        month: '%m',
                    }
                },
                series: [{
                    name: 'DHT22 Temp 1',
                    data: []
                },
                {
                    name: 'DHT22 Temp 2',
                    data: []
                },
                {
                    name: 'BMP Temp',
                    data: []
                },
                {
                    name: 'CWB Temp',
                    data: []
                }]
            });

            chart2 = Highcharts.chart('container2', {
                title: {
                    text: 'Humidity (°F)'
                },
                xAxis: {
                    type: 'datetime',
                    dateTimeLabelFormats: {
                        second: '%m-%d<br/>%H:%M:%S',
                        minute: '%m-%d<br/>%H:%M',
                        hour: '%m-%d<br/>%H:%M',
                        day: '%m-%d',
                        week: '%m-%d',
                        month: '%m',
                    }
                },
                series: [{
                    name: 'DHT22 Humidity 1',
                    data: []
                },
                {
                    name: 'DHT22 Humidity 2',
                    data: []
                },
                {
                    name: 'CWB Humidity',
                    data: []
                }]
            });

            chart3 = Highcharts.chart('container3', {
                title: {
                    text: 'PM1.0'
                },
                xAxis: {
                    type: 'datetime',
                    dateTimeLabelFormats: {
                        second: '%m-%d<br/>%H:%M:%S',
                        minute: '%m-%d<br/>%H:%M',
                        hour: '%m-%d<br/>%H:%M',
                        day: '%m-%d',
                        week: '%m-%d',
                        month: '%m',
                    }
                },
                series: [{
                    name: 'ESP PM1.0',
                    data: []
                }]
            });

            chart4 = Highcharts.chart('container4', {
                title: {
                    text: 'PM2.5'
                },
                xAxis: {
                    type: 'datetime',
                    dateTimeLabelFormats: {
                        second: '%m-%d<br/>%H:%M:%S',
                        minute: '%m-%d<br/>%H:%M',
                        hour: '%m-%d<br/>%H:%M',
                        day: '%m-%d',
                        week: '%m-%d',
                        month: '%m',
                    }
                },
                series: [{
                    name: 'ESP PM2.5',
                    data: []
                },
                {
                    name: 'EPA PM2.5',
                    data: []
                }]
            });

            chart5 = Highcharts.chart('container5', {
                title: {
                    text: 'PM10'
                },
                xAxis: {
                    type: 'datetime',
                    dateTimeLabelFormats: {
                        second: '%m-%d<br/>%H:%M:%S',
                        minute: '%m-%d<br/>%H:%M',
                        hour: '%m-%d<br/>%H:%M',
                        day: '%m-%d',
                        week: '%m-%d',
                        month: '%m',
                    }
                },
                series: [{
                    name: 'ESP PM10',
                    data: []
                },
                {
                    name: 'EPA PM10',
                    data: []
                }]
            });
            
            chart6 = Highcharts.chart('container6', {
            title: {
                text: 'Pressure'
            },
            xAxis: {
                type: 'datetime',
                dateTimeLabelFormats: {
                    second: '%m-%d<br/>%H:%M:%S',
                    minute: '%m-%d<br/>%H:%M',
                    hour: '%m-%d<br/>%H:%M',
                    day: '%m-%d',
                    week: '%m-%d',
                    month: '%m',
                }
            },
            series: [{
                name: 'BMP Pressure',
                data: []
            }]
        });
            
        });
    </script>