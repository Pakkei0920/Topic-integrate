#include "Arduino.h"
#include "WiFi.h"
#include "Audio.h"
#include <HTTPClient.h>
#include <Adafruit_GFX.h> //OLED顯示器函數庫
#include <Adafruit_SSD1306.h> //OLED顯示器函數庫
#include <U8g2lib.h> //顯示中文函數庫

const int adcPin = 34; // 选择您所连接可变电阻的引脚

Audio audio;

String ssid =    "6412";
String password = "20020920";

String audio_id1 = "";
String audio_id2 = "";

const int redLedPin = 18;   // Red LED connected to GPIO 18
const int greenLedPin = 19; // Green LED connected to GPIO 19

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0,U8X8_PIN_NONE);
int clock_center_x=64;
int clock_center_y=32;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  chinese_text();
  Serial.begin(115200);
  
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  while (WiFi.status() != WL_CONNECTED){
  delay(1000);
    Serial.println("連接到WiFi...");
    digitalWrite(redLedPin, HIGH);   // Red LED on
    digitalWrite(greenLedPin, LOW);  // Green LED off
  }
  digitalWrite(redLedPin, LOW);    // Red LED off
  digitalWrite(greenLedPin, HIGH); // Green LED on
  Serial.println("WiFi 連接成功");
  
  audio.setPinout(26, 27, 25);//I2S_BCLK, I2S_LRC, I2S_DOUT
  audio.setVolume(21);
  
}

void loop() {
  int adcValue = analogRead(adcPin); // 读取ADC输入的值
  int volumeValue = map(adcValue, 0, 4095, 0, 21); // 将ADC值映射到0-21的范围内
  audio.setVolume(volumeValue);
  audio.loop();
  audio123();

  }
  
    

  
