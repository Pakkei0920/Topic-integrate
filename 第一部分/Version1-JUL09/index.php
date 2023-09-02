$servername = "localhost"; // MySQL服务器名称
$username = "root"; // MySQL用户名
$password = "QKV6yCs2ps.="; // MySQL密码
$dbname = "xkj"; // MySQL数据库名
$conn = mysqli_connect($servername, $username, $password, $dbname);// 创建连接

// 檢查連接是否成功
if ($conn->connect_error) {
    die("連接失敗：" . $conn->connect_error);
}
//
$result = $conn->query("SELECT dht22_temp FROM sensor_data ORDER BY datetime DESC LIMIT 1");
$row = $result->fetch_assoc();
$temp = $row["dht22_temp"];   
//echo "目前溫度：".$temp. "<br>";
//
$result = $conn->query("SELECT dht22_humd FROM sensor_data ORDER BY datetime DESC LIMIT 1");
$row = $result->fetch_assoc(); 
$humd = $row["dht22_humd"];   
//echo "目前濕度：".$humd. "<br>";
//
$result = $conn->query("SELECT datetime FROM sensor_data ORDER BY datetime DESC LIMIT 1");
$row = $result->fetch_assoc(); 
$datetime = $row["datetime"];   
$datetime = date("h:i A", strtotime($datetime));  
//echo "最新數據時間：" . $datetime . "<br>";
//
$result = $conn->query("SELECT dht22_temp, datetime FROM sensor_data WHERE DATE(datetime) = CURDATE() ORDER BY dht22_temp DESC LIMIT 1");
$row = $result->fetch_assoc();
$maxTemp = $row['dht22_temp'];  
//echo "當天最高氣溫：" . $maxTemp . "<br>";
$maxtemp_datetime = $row['datetime']; 
$maxtemp_datetime = date("h:i A", strtotime($maxtemp_datetime));  
//echo "當天最高氣溫時間：" . $maxtemp_datetime . "<br>";
//
$result = $conn->query("SELECT MIN(dht22_temp) AS min_temp, datetime FROM sensor_data WHERE DATE(datetime) = CURDATE()");
$row = $result->fetch_assoc();
$minTemp = $row['min_temp'];  
//echo "當天最低氣溫：" . $minTemp . "<br>";
$mindatetime = $row['datetime'];
$mindatetime = date("h:i A", strtotime($mindatetime));  
//echo "當天最低氣溫時間：" . $mindatetime . "<br>";
// 關閉資料庫連線
$conn->close();
?>

<!DOCTYPE html>
<html>
<head>
  <title>天氣報告</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
    .weather-card {
      background-color: #f2f2f2;
      border-radius: 20px;
      box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
      padding: 20px;
      font-family: Arial, sans-serif;
      text-align: center;
    }

    .weather-card h2 {
      font-size: 24px;
      font-weight: bold;
      margin-bottom: 10px;
      text-align: left;
    }

    .weather-card .temperature {
      font-size: 48px;
      font-weight: bold;
      margin-bottom: 10px;
      text-align: right;
    }

    .weather-card .humidity {
      font-size: 18px;
      margin-bottom: 10px;
      text-align: left;
    }

    .weather-card .high-low {
      font-size: 16px;
      display: flex;
      justify-content: space-between;
      align-items: center;
      margin-top: 20px;
    }

    .weather-card .high {
      color: #ff6347;
      text-align: left;
    }

    .weather-card .low {
      color: #00bfff;
      text-align: right;
    }

    .weather-card .updated {
      font-size: 12px;
      margin-top: 15px;
      text-align: right;
    }
  </style>
</head>
<body>
  <div class="weather-card">
    <div class="updated"><?php echo $datetime."更新"; ?></div>
    <h2>ESP32 | 即時天氣報告</h2>
    <div class="temperature"><?php echo $temp." °C"; ?> </div>
    <div class="humidity"><?php echo $humd." %"; ?></div>
    <div class="high-low">
      <span class="high"><?php echo "▲" . $maxTemp; ?> (<?php echo $maxtemp_datetime; ?>)</span>
      <span class="low"><?php echo "▼" . $minTemp; ?> (<?php echo $mindatetime; ?>)</span>
    </div>
  </div>
	<p>
	<p align="right"><a href="https://wp.paki91.com/new-data/">更多資料點擊這裡</a></p>

</body>
</html>
 