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
$dht22_temp = $_POST['dht22_temp'];
$dht22_humd = $_POST['dht22_humd'];
$pms_pm1 =$_POST['pms_pm1'];
$pms_pm25 =$_POST['pms_pm25'];
$pms_pm100 =$_POST['pms_pm100'];


// 台灣中央氣象局 API 
$cwb_url = 'https://opendata.cwb.gov.tw/api/v1/rest/datastore/O-A0001-001?Authorization=CWB-9164C5ED-C227-4AD9-947B-3EA579B94742&stationId=C0V810';	
$cwb_response = file_get_contents($cwb_url);	// 發送 GET 請求並取得回應
    // 解析 JSON 回應
      $cwb_data = json_decode($cwb_response, true);   
      $cwb_station = $cwb_data['records']['location'][0];	// 取得觀測站資料
      $cwb_temp = $cwb_station['weatherElement'][3]['elementValue']; // 取得目前的溫度
      $cwb_humd = $cwb_station['weatherElement'][4]['elementValue']; // 取得目前的濕度
      $cwb_humd = $cwb_humd * 100;

// 行政院環境保護署 API
$epa_url = 'https://data.epa.gov.tw/api/v2/aqx_p_241?format=json&api_key=b00c9991-826c-4527-8c11-79720262618d&limit=6';	// 行政院環境保護署EPA API 網址
$epa_response = file_get_contents($epa_url);	// 發送 GET 請求並取得回應
    // 解析 JSON 回應
      $epa_data = json_decode($epa_response, true);   // 解析 JSON 回應
      $epa_pm25 = $epa_data['records'][0]['concentration']; //細懸浮微粒PM2.5
      $epa_pm10 = $epa_data['records'][2]['concentration']; //懸浮微粒PM10

if ($dht22_temp == "0" || $dht22_humd == "0" || $cwb_temp == "0" || $cwb_humd == "0") {
    // Do not perform any action
} else {
    // Insert data into the MySQL database
    $sql = "INSERT INTO sensor_data (dht22_temp, dht22_humd, cwb_temp, cwb_humd, epa_pm25, epa_pm10, esp_pm1, esp_pm25, esp_pm100) 
            VALUES ('$dht22_temp', '$dht22_humd', '$cwb_temp', '$cwb_humd', '$epa_pm25', '$epa_pm10', '$pms_pm1', '$pms_pm25', '$pms_pm100')";}



if (mysqli_query($conn, $sql)) {
  echo "New record created successfully<br>";
} else {
  echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}
mysqli_close($conn);

?>