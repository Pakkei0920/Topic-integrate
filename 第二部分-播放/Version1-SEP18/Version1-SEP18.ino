#include "Arduino.h"
#include "WiFi.h"
#include "Audio.h"
#include <HTTPClient.h>

const int adcPin = 34; // 选择您所连接可变电阻的引脚

Audio audio;

String ssid =    "6412";
String password = "20020920";

String audio_id1 = "";
String audio_id2 = "";


void setup() {
  
  Serial.begin(115200);
  
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  while (WiFi.status() != WL_CONNECTED)
  delay(1500);
  
  audio.setPinout(26, 27, 25);//I2S_BCLK, I2S_LRC, I2S_DOUT
  audio.setVolume(10);
  
}

void loop() {
  int adcValue = analogRead(adcPin); // 读取ADC输入的值
  int volumeValue = map(adcValue, 0, 4095, 0, 21); // 将ADC值映射到0-21的范围内
  audio.setVolume(volumeValue);
  audio.loop();
  audio123();

  }
  
    

  
