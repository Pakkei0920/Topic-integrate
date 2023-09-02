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

       <script type="text/javascript">
        function fetchData() {
            $.ajax({
                url: '/topics/fetch_data.php',
                type: 'GET',
                dataType: 'json',
                success: function(data) {
                    // Update the charts with the new data
                    chart1.series[0].setData(data.dht22_tempData);
                    chart1.series[1].setData(data.lm75_tempData);
                    chart1.series[2].setData(data.cwb_tempData);

                    chart2.series[0].setData(data.dht22_humdData);
                    chart2.series[1].setData(data.cwb_humd);

                    chart3.series[0].setData(data.esp_pm1Data);
                    
                    chart4.series[0].setData(data.esp_pm25Data);
                    chart4.series[1].setData(data.epa_pm25Data);

                    chart5.series[0].setData(data.esp_pm100Data);
                    chart5.series[1].setData(data.epa_pm10Data);
                }
            });
        }

        // Fetch data initially
        fetchData();

        // Fetch data every 5 seconds
        setInterval(fetchData, 1000);

        // Create chart variables
        var chart1, chart2, chart3, chart4, chart5;

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
                    name: 'DHT22',
                    data: []
                },
                {
                    name: 'LM75',
                    data: []
                },
                {
                    name: 'CWB',
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
                    name: 'DHT22',
                    data: []
                },
                {
                    name: 'CWB',
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
                },
                ]
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
        });
    </script>


<i id="__PIKPAK_EXTENSION__" style="display: none;"></i></body></html>        });
    </script><?php echo json_encode($dht22_tempData); ?>;
</body>
</html>