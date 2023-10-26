void updateCountdown() {
  // 计算剩余时间
  unsigned long currentTime = millis();
  unsigned long recordingTimeElapsed = currentTime - recordingStartTime;
  unsigned long recordingTimeRemaining = (recordingTimeElapsed >= RECORD_TIME * 1000 ) ? 0 : ((RECORD_TIME * 1000) - recordingTimeElapsed);



// 在OLED上显示倒计时
  if (canrecording == false && endrecording == false) {
    u8g2.setFont(u8g2_font_unifont_t_chinese2);  // use chinese2 for all the glyphs of "你好世界"
    u8g2.setFontDirection(0);
    u8g2.clearBuffer();
    u8g2.setCursor(0, 15);
    u8g2.print("正在录音中...");
    u8g2.setCursor(0, 40);
    u8g2.print("录音时间还有："); 
    u8g2.setCursor(98, 40);
    u8g2.print(recordingTimeRemaining / 1000); 
    u8g2.sendBuffer();
    delay(200);
    fill_solid(leds, NUM_LEDS, CRGB(255, 90, 90));//rgb red
  FastLED.show();
    }
    
 if (waiting == true){
    u8g2.setFont(u8g2_font_unifont_t_chinese2);  // use chinese2 for all the glyphs of "你好世界"
    u8g2.clearBuffer();
    u8g2.setCursor(0, 12);
    u8g2.print("正在发送和打扫...");    // Chinese "Hello World" 
    u8g2.setCursor(0, 40);
    u8g2.print("请等等 Ples wait..."); 
    u8g2.sendBuffer();
    delay(500);
    fill_solid(leds, NUM_LEDS, CRGB(255, 204, 3));//yellow
  FastLED.show();
    }
    
  if (canrecording == true){
    display.clearDisplay();
    display.drawBitmap(4, 0, waitrec, 112, 64, WHITE);//左右-上下
    delay(200);
    display.display();
   
    
    fill_solid(leds, NUM_LEDS, CRGB(0, 218, 255));//blue
  FastLED.show();
     }
}    
