//包括pms5003+dht22post功能+oled
#include <PMS.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

const char* ssid = "6412";
const char* password = "20020920";
const char* serverName = "http://topic.paki91.com/xkj/post_index.php";

DHT dht(15, DHT22);//pin15
PMS pms(Serial1);
PMS::DATA data;

void setup()
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1.8);
  display.setTextColor(WHITE);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000); Serial.println("Connecting to WiFi...");
  }
    Serial.println("WiFi OK");
    dht.begin();
    Wire.begin(); //i2c通訊
    Serial1.begin(9600, SERIAL_8N1, 16, 17); //pms5003
}

void loop()
{
if (pms.read(data))
  {
    int pm1 = data.PM_AE_UG_1_0;
    int pm25 = data.PM_AE_UG_2_5;
    int pm100 = data.PM_AE_UG_10_0;
    
    Serial.print("PM 1.0(ug/m3): ");Serial.println(pm1);
    Serial.print("PM 2.5(ug/m3): ");Serial.println(pm25);
    Serial.print("PM 10.0(ug/m3): ");Serial.println(pm100);

    float dht22_temp = dht.readTemperature(); Serial.println(dht22_temp);
    float dht22_humd = dht.readHumidity(); Serial.println(dht22_humd);
  
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("PM1.0: ");display.println(pm1);
    display.print("PM2.5: ");display.println(pm25);
    display.print("PM10.0: ");display.println(pm100);
    display.print("Temp: ");display.println(dht22_temp);
    display.print("Humd: ");display.println(dht22_humd);
    display.display();

   HTTPClient http;
   http.begin(serverName);
   http.addHeader("Content-Type", "application/x-www-form-urlencoded");
   
   String postData =    "dht22_temp=" + String(dht22_temp) + 
                        "&dht22_humd=" + String(dht22_humd)+
                        "&pms_pm1=" + String(pm1)+
                        "&pms_pm25=" + String(pm25)+
                        "&pms_pm100=" + String(pm100);
                        
   int httpResponseCode = http.POST(postData);
    
    if (httpResponseCode > 0) {
      Serial.println("Data sent successfully");
    } else {
      Serial.println("Error sending data");
    }
    http.end();

delay(30000);
}
  }
