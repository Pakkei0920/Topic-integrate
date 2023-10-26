#include "Arduino.h"
#include "WiFi.h"
#include "Audio.h"
#include <HTTPClient.h>
#include <Adafruit_GFX.h> //OLED顯示器函數庫
#include <Adafruit_SSD1306.h> //OLED顯示器函數庫
#include "paki_text.h"

const int adcPin = 34; // 选择您所连接可变电阻的引脚

Audio audio;

String ssid =    "6412";
String password = "20020920";

String audio_id1 = "";
String audio_id2 = "";

const int redLedPin = 18;   // Red LED connected to GPIO 18
const int greenLedPin = 19; // Green LED connected to GPIO 19

Adafruit_SSD1306 display(128, 64, &Wire, 4);
int clock_center_x=64;
int clock_center_y=32;

//
int upbtpin=34;
int downbtpin=35;
int volumeValue = 10;

//

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  open_text();
  
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
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
  display.clearDisplay();
  display.drawBitmap(15, 25, wlljcg, 96, 16, WHITE);delay(200);
  display.display();
  
  digitalWrite(redLedPin, LOW);    // Red LED off
  digitalWrite(greenLedPin, HIGH); // Green LED on
  Serial.println("WiFi 連接成功");

  delay(2000);  
  display.clearDisplay();
  display.drawBitmap(30, 25, pmdj, 64, 16, WHITE);//左右-上下
  display.display();
  delay(2500);
  display.clearDisplay();
  display.display();
  
  audio.setPinout(26, 27, 25);//I2S_BCLK, I2S_LRC, I2S_DOUT
  pinMode(upbtpin,INPUT);
  pinMode(downbtpin,INPUT);
  
}

void loop() {
  audio.setVolume(volumeValue);
  audio.loop();
  audio123();
  sound_bt();

  }
  
    

  
