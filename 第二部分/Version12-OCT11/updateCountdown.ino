void updateCountdown() {
  // 计算剩余时间
  unsigned long currentTime = millis();
  unsigned long recordingTimeElapsed = currentTime - recordingStartTime;
  unsigned long recordingTimeRemaining = (recordingTimeElapsed >= RECORD_TIME * 1000 ) ? 0 : ((RECORD_TIME * 1000) - recordingTimeElapsed);



// 在OLED上显示倒计时
  if (canrecording == false && endrecording == false) {
    display.clearDisplay();
    display.drawBitmap(4, 0, recmicpng, 64, 64, WHITE);//左右-上下
    display.setCursor(80, 18);//左右-上下
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.println(recordingTimeRemaining / 1000);
    delay(200);
    display.display();
    fill_solid(leds, NUM_LEDS, CRGB(255, 90, 90));//rgb red
  FastLED.show();
    }
    
 if (waiting == true){
  
    display.clearDisplay();
    display.drawBitmap(4, 0, stoprec, 104, 64, WHITE);//左右-上下
    delay(200);
    display.display();

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
