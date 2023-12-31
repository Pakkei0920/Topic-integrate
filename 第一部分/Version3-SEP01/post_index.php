<?php
$servername = "localhost"; // MySQL服务器名称
$username = "root"; // MySQL用户名
$password = "QKV6yCs2ps.="; // MySQL密码
$dbname = "xkj"; // MySQL数据库名
$conn = mysqli_connect($servername, $username, $password, $dbname);// 创建连接

// 检测连接
if (!$conn) {
  die("Connection failed: " . mysqli_connect_error());
}

// 接受 ESP32 POST 的数据
    $dht22_temp1 = $_POST['dht22_temp1'];
    $dht22_humd1 = $_POST['dht22_humd1'];
    $dht22_temp2 = $_POST['dht22_temp2'];
    $dht22_humd2 = $_POST['dht22_humd2'];
    $scd40_temp = $_POST['scd40_temp'];
    $scd40_humd = $_POST['scd40_humd'];
    $scd40_co2 = $_POST['scd40_co2'];
    $bmp_temp = $_POST['bmp_temp'];
    $bmp_pressure = $_POST['bmp_pressure'];
    $bmp_altitude = $_POST['bmp_altitude'];
    $esp_pm1 = $_POST['esp_pm1'];
    $esp_pm25 = $_POST['esp_pm25'];
    $esp_pm100 = $_POST['esp_pm100'];


// 台灣中央氣象局 API 
$cwb_url = 'https://opendata.cwb.gov.tw/api/v1/rest/datastore/O-A0001-001?Authorization=CWB-9164C5ED-C227-4AD9-947B-3EA579B94742&stationId=C0V810';	
$cwb_response = file_get_contents($cwb_url);	// 發送 GET 請求並取得回應
    // 解析 JSON 回應
      $cwb_data = json_decode($cwb_response, true);   
      $cwb_station = $cwb_data['records']['location'][0];	// 取得觀測站資料
      $cwb_temp = $cwb_station['weatherElement'][3]['elementValue']; // 取得目前的溫度
      $cwb_humd = $cwb_station['weatherElement'][4]['elementValue']; // 取得目前的濕度
      $cwb_humd = $cwb_humd * 100;




// Insert data into the MySQL database
$sql = "INSERT INTO sensor_data (dht22_temp1, dht22_humd1, dht22_temp2, dht22_humd2, scd40_temp, scd40_humd, scd40_co2,
    bmp_temp, bmp_pressure, bmp_altitude, esp_pm1, esp_pm25, esp_pm100,cwb_temp, cwb_humd, epa_pm25, epa_pm10) VALUES ('$dht22_temp1', '$dht22_humd1', '$dht22_temp2', '$dht22_humd2', '$scd40_temp', '$scd40_humd', '$scd40_co2','$bmp_temp', '$bmp_pressure', '$bmp_altitude', '$esp_pm1', '$esp_pm25', '$esp_pm100','$cwb_temp', '$cwb_humd', '$epa_pm25', '$epa_pm10')";



echo $sql;
if (mysqli_query($conn, $sql)) {
  echo "New record created successfully<br>";
} else {
  echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}
mysqli_close($conn);

?>