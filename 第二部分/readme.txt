--------------------
LTE - Line To ESP32
--------------------
第二部分包括PHP,C+
Line Webhook URL https://topics.paki91.com/post/
目的：透過Line的Webhook功能，發送到nas，再透過esp32讀取。
實現對話功能及TTS文字轉語音功能。

程序運行包括：
File name 	to 	Make
xkj_v5.ino	C+	esp32收集傳感器數據發送http post到nas
post_index.php	PHP	接受http Post信息+接入氣象局及環保處API到SQL
fetch_data.php	PHP	從SQL中讀取數據,輸出json數據給index_line.php
index_line.php	PHP	fetch_data.php的數據並透過匯入highcharts.js生成折線圖，另外透過匯入jquery.js中的ajax實現不刷新頁面情況下通過讀取fetch_data.php刷新數據
index.php	PHP	從SQL中讀取數據，透過css生成小圓形視窗界面
wordpress		框架界面
nas+sql			系統應用+網站伺服器






