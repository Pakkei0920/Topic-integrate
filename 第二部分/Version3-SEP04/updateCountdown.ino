void updateCountdown() {
  // 计算剩余时间
  unsigned long currentTime = millis();
  unsigned long recordingTimeElapsed = currentTime - recordingStartTime;
  unsigned long recordingTimeRemaining = (recordingTimeElapsed >= RECORD_TIME * 1000 - 2000) ? 0 : ((RECORD_TIME * 1000 - 2000) - recordingTimeElapsed);


if (canrecording == false && endrecording == false) {

  Serial.print("主板时间:");
  Serial.print(currentTime);
  Serial.print("  录音时间:");
  Serial.println(recordingTimeRemaining);
  
  // 在OLED上显示倒计时
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Recording...");
  display.setCursor(0, 16);
  display.print("Time Remaining: ");
  display.print(recordingTimeRemaining / 1000); // 显示剩余秒数
  display.display();
  delay(500);
  }
else {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("No Record");
  display.display();
  delay(1000);
}}
