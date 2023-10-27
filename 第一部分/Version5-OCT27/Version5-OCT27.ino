#include <PMS.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP280.h>
#include <SparkFun_SCD4x_Arduino_Library.h>
#include "B1_png.h"

// 初始化 OLED 顯示螢幕
Adafruit_SSD1306 display(128, 64, &Wire, -1);

const char* ssid = "6412";         // WiFi SSID
const char* password = "20020920";    // WiFi 密碼
const char* serverName = "http://topic.paki91.com/xkj/post_index.php";  // 伺服器地址

DHT dht1(0, DHT22);   // 使用引腳 0 連接 DHT22 溫濕度感測器
DHT dht2(2, DHT22);   // 使用引腳 2 連接 DHT22 溫濕度感測器
PMS pms(Serial1);     // 使用 Serial1 連接 PMS 鐳射顆粒感測器

PMS::DATA data;
SCD4x mySensor;
#define BMP280_ADDRESS 0x76
Adafruit_BMP280 bmp; // 通過 I2C 連接的 BMP280 溫壓感測器

const int redLedPin = 18;   // Red LED connected to GPIO 18
const int greenLedPin = 19; // Green LED connected to GPIO 19
//
void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  Serial.begin(115200);
  while (!Serial) delay(100);
  Serial.println(F("初始化..."));

  // 初始化 OLED 顯示幕幕
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2.9);
  display.setTextColor(WHITE);

  // 連接到 WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("連接到WiFi...");
    digitalWrite(redLedPin, HIGH);   // Red LED on
    digitalWrite(greenLedPin, LOW);  // Green LED off
  }
  digitalWrite(redLedPin, LOW);    // Red LED off
  digitalWrite(greenLedPin, HIGH); // Green LED on
  Serial.println("WiFi 連接成功");

  // 初始化 DHT 溫濕度感測器
  dht1.begin();
  dht2.begin();

  mySensor.begin();
  
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
    int esp_pm1 = data.PM_AE_UG_1_0;
    int esp_pm25 = data.PM_AE_UG_2_5;
    int esp_pm100 = data.PM_AE_UG_10_0;

    float dht22_temp1 = dht1.readTemperature();
    float dht22_humd1 = dht1.readHumidity();

    float dht22_temp2 = dht2.readTemperature();
    float dht22_humd2 = dht2.readHumidity();

    float bmp_temp = bmp.readTemperature();
    float bmp_pressure = bmp.readPressure() / 100.0; // 將 Pa 轉換為 hPa
    float bmp_altitude = bmp.readAltitude(1013.25);

    float scd40_co2 = mySensor.getCO2();
    float scd40_temp = mySensor.getTemperature();
    float scd40_humd = mySensor.getHumidity();

    float maxtemp = (dht22_temp1+dht22_temp2+bmp_temp+scd40_temp)/4;
    float maxhumd = (dht22_humd1+dht22_humd2+scd40_humd)/3;
    
    
//顯示器部分//


    display.clearDisplay();
    
    display.setTextSize(4);
    display.drawBitmap(0, 0, pm25, 64, 64, WHITE);//左右-上下
    display.setCursor(70, 15);
    display.print(esp_pm25);
    
    display.setTextSize(1);
    display.setCursor(95, 50);//128 64 
    display.print("ug/m3");
    display.display();
    
    delay (10000);
    
    display.clearDisplay();
    display.setTextSize(2);
    display.drawBitmap(0, 0, wdsd, 32, 64, WHITE);//左右-上下
    display.setCursor(40, 8);
    display.print(maxtemp);display.println("C");
    display.setCursor(40, 40);
    display.print(maxhumd);display.println("%");
    display.display();



    
//串口監視器部分//
    Serial.print("esp_pm1.0: "); Serial.println(esp_pm1);
    Serial.print("PM2.5: "); Serial.println(esp_pm25);
    Serial.print("esp_pm10.0: "); Serial.println(esp_pm100);
    Serial.print("Temp1: "); Serial.print(dht22_temp1);Serial.println("°C");
    Serial.print("Humd1: "); Serial.print(dht22_humd1);Serial.println("%");
    Serial.print("Temp2: "); Serial.print(dht22_temp2);Serial.println("°C");
    Serial.print("Humd2: "); Serial.print(dht22_humd2);Serial.println("%");
    Serial.print("BMP Temp: "); Serial.print(bmp_temp);Serial.println("°C");
    Serial.print("BMP Press: "); Serial.print(bmp_pressure);Serial.println(" hPa");
    Serial.print("BMP Altitude: "); Serial.print(bmp_altitude);Serial.println(" m");
    
    
    Serial.print("scd40_co2: "); Serial.print(scd40_co2);Serial.println("ppm");
    Serial.print("scd40_humd: "); Serial.print(scd40_humd);Serial.println("%");
    Serial.print("scd40_temp: "); Serial.print(scd40_temp);Serial.println("°C");
   
    
//HTTP部分//
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String postData = "dht22_temp1=" + String(dht22_temp1) +
                      "&dht22_humd1=" + String(dht22_humd1) +
                      "&dht22_temp2=" + String(dht22_temp2) +
                      "&dht22_humd2=" + String(dht22_humd2) +
                      "&scd40_temp=" + String(scd40_temp) +
                      "&scd40_humd=" + String(scd40_humd) +
                      "&scd40_co2=" + String(scd40_co2)+
                      "&bmp_temp=" + String(bmp_temp) +
                      "&bmp_pressure=" + String(bmp_pressure) +
                      "&bmp_altitude=" + String(bmp_altitude) +
                      "&esp_pm1=" + String(esp_pm1) +
                      "&esp_pm25=" + String(esp_pm25) +
                      "&esp_pm100=" + String(esp_pm100)
                      
                      ;

    int httpResponseCode = http.POST(postData);
    Serial.println (postData);
    
    if (httpResponseCode > 0) {
      Serial.println("資料發送成功");
    } else {
      Serial.println("發送資料時出錯");
    }
    Serial.println (httpResponseCode);
    http.end();

    delay(24000); // 延遲30秒後再次讀取感測器資料
  }
}
