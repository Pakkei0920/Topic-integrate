<?php
$connection = mysqli_connect('localhost', 'root', 'QKV6yCs2ps.=', 'xkj');
if (!$connection) {die("Connection failed: " . mysqli_connect_error());}

$query = "SELECT datetime, dht22_temp, dht22_humd, lm75_temp, cwb_temp, cwb_humd, esp_pm1, esp_pm25, esp_pm100, epa_pm25, epa_pm10
          FROM sensor_data
          ORDER BY datetime DESC
          LIMIT 20";

$result = mysqli_query($connection, $query);

while ($row = mysqli_fetch_assoc($result)) {
    $dht22_tempData[] = array(
        strtotime($row['datetime']) * 1000 + 28800000,
        floatval($row['dht22_temp'])
    );
    $dht22_humdData[] = array(
        strtotime($row['datetime']) * 1000 + 28800000,
        floatval($row['dht22_humd'])
    );
    $lm75_tempData[] = array(
        strtotime($row['datetime']) * 1000 + 28800000,
        floatval($row['lm75_temp'])
    );
    $cwb_tempData[] = array(
        strtotime($row['datetime']) * 1000 + 28800000,
        floatval($row['cwb_temp'])
    );
    $cwb_humd[] = array(
        strtotime($row['datetime']) * 1000 + 28800000,
        floatval($row['cwb_humd'])
    );
    $esp_pm1Data[] = array(
        strtotime($row['datetime']) * 1000 + 28800000,
        floatval($row['esp_pm1'])
    );
    $esp_pm25Data[] = array(
        strtotime($row['datetime']) * 1000 + 28800000,
        floatval($row['esp_pm25'])
    );
    $esp_pm100Data[] = array(
        strtotime($row['datetime']) * 1000 + 28800000,
        floatval($row['esp_pm100'])
    );
    $epa_pm25Data[] = array(
        strtotime($row['datetime']) * 1000 + 28800000,
        floatval($row['epa_pm25'])
    );
    $epa_pm10Data[] = array(
        strtotime($row['datetime']) * 1000 + 28800000,
        floatval($row['epa_pm10'])
    );
}

// Convert the data to JSON format and send the response
$data = array(
    "dht22_tempData" => $dht22_tempData,
    "dht22_humdData" => $dht22_humdData,
    "lm75_tempData" => $lm75_tempData,
    "cwb_tempData" => $cwb_tempData,
    "cwb_humd" => $cwb_humd,
    "esp_pm1Data" => $esp_pm1Data,
    "esp_pm25Data" => $esp_pm25Data,
    "esp_pm100Data" => $esp_pm100Data,
    "epa_pm25Data" => $epa_pm25Data,
    "epa_pm10Data" => $epa_pm10Data
);
header('Content-Type: application/json');
echo $response = json_encode($data);

mysqli_free_result($result); //釋放與結果關聯的內存
mysqli_close($connection);
?>
