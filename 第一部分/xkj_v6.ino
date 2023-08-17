#include <PMS.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP280.h>

// 初始化 OLED 顯示螢幕
Adafruit_SSD1306 display(128, 64, &Wire, -1);

const char* ssid = "6412";         // WiFi SSID
const char* password = "20020920";    // WiFi 密碼
const char* serverName = "http://topic.paki91.com/xkj/post_index.php";  // 伺服器地址

DHT dht1(0, DHT22);   // 使用引腳 0 連接 DHT22 溫濕度感測器
DHT dht2(2, DHT22);   // 使用引腳 2 連接 DHT22 溫濕度感測器
PMS pms(Serial1);     // 使用 Serial1 連接 PMS 鐳射顆粒感測器
PMS::DATA data;

#define BMP280_ADDRESS 0x76
Adafruit_BMP280 bmp; // 通過 I2C 連接的 BMP280 溫壓感測器

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(100);
  Serial.println(F("初始化..."));

  // 初始化 OLED 顯示幕幕
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1.8);
  display.setTextColor(WHITE);

  // 連接到 WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("連接到WiFi...");
  }
  Serial.println("WiFi 連接成功");

  // 初始化 DHT 溫濕度感測器
  dht1.begin();
  dht2.begin();

  // 初始化 PMS 顆粒感測器
  Wire.begin();
  Serial1.begin(9600, SERIAL_8N1, 16, 17);

  // 初始化 BMP280 溫壓感測器
  if (!bmp.begin(BMP280_ADDRESS)) {
    Serial.println(F("無法找到有效的BMP280感測器。請檢查接線或地址。"));
    while (1);
  }
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X2,
                  Adafruit_BMP280::SAMPLING_X16,
                  Adafruit_BMP280::FILTER_X16,
                  Adafruit_BMP280::STANDBY_MS_500);
}

void loop() {
  if (pms.read(data)) {
    int pm1 = data.PM_AE_UG_1_0;
    int pm25 = data.PM_AE_UG_2_5;
    int pm100 = data.PM_AE_UG_10_0;

    float dht1_temp = dht1.readTemperature();
    float dht1_humd = dht1.readHumidity();

    float dht2_temp = dht2.readTemperature();
    float dht2_humd = dht2.readHumidity();

    float bmp_temp = bmp.readTemperature();
    float bmp_pressure = bmp.readPressure() / 100.0; // 將 Pa 轉換為 hPa
    float bmp_altitude = bmp.readAltitude(1013.25);

//顯示器部分//
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("PM1.0: "); display.println(pm1);
    display.print("PM2.5: "); display.println(pm25);
    display.print("PM10.0: "); display.println(pm100);
    display.print("Temp1: "); display.print(dht1_temp);display.println("C");
    display.print("Humd1: "); display.print(dht1_humd);display.println("%");
    display.print("Temp2: "); display.print(dht2_temp);display.println("C");
    display.print("Humd2: "); display.print(dht2_humd);display.println("%");
    display.print("BMP Temp: "); display.print(bmp_temp);display.println("C");
    display.display();
    
//串口監視器部分//
    Serial.print("PM1.0: "); Serial.println(pm1);
    Serial.print("PM2.5: "); Serial.println(pm25);
    Serial.print("PM10.0: "); Serial.println(pm100);
    Serial.print("Temp1: "); Serial.print(dht1_temp);Serial.println("°C");
    Serial.print("Humd1: "); Serial.print(dht1_humd);Serial.println("%");
    Serial.print("Temp2: "); Serial.print(dht2_temp);Serial.println("°C");
    Serial.print("Humd2: "); Serial.print(dht2_humd);Serial.println("%");
    Serial.print("BMP Temp: "); Serial.print(bmp_temp);Serial.println("°C");
    Serial.print("BMP Press: "); Serial.print(bmp_pressure);Serial.println(" hPa");
    Serial.print("BMP Altitude: "); Serial.print(bmp_altitude);Serial.println(" m");
    
//HTTP部分//
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String postData = "dht1_temp=" + String(dht1_temp) +
                      "&dht1_humd=" + String(dht1_humd) +
                      "&dht2_temp=" + String(dht2_temp) +
                      "&dht2_humd=" + String(dht2_humd) +
                      "&bmp_temp=" + String(bmp_temp) +
                      "&bmp_pressure=" + String(bmp_pressure) +
                      "&pms_pm1=" + String(pm1) +
                      "&pms_pm25=" + String(pm25) +
                      "&pms_pm100=" + String(pm100);

    int httpResponseCode = http.POST(postData);

    if (httpResponseCode > 0) {
      Serial.println("資料發送成功");
    } else {
      Serial.println("發送資料時出錯");
    }
    http.end();

    delay(30000); // 延遲30秒後再次讀取感測器資料
  }
}
