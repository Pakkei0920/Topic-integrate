void sound_bt(){
  int upbt = digitalRead(upbtpin);
  int downbt = digitalRead(downbtpin);
 
    if(upbt == HIGH && volumeValue < 21){
      volumeValue = volumeValue + 1;
      delay (500);
      display.clearDisplay();
      display.drawBitmap(0, 0, png1, 64, 60, WHITE);
      display.setCursor(80, 18);display.setTextSize(4);display.setTextColor(WHITE);
      display.println(volumeValue);//左右-上下
      display.display();
    }
    
    if(downbt == HIGH && volumeValue > 0){
      volumeValue = volumeValue - 1;
      delay (500);
      display.clearDisplay();
      display.drawBitmap(0, 0, png2, 64, 60, WHITE);
      display.setCursor(80, 18);display.setTextSize(4);display.setTextColor(WHITE);
      display.println(volumeValue);//左右-上下
      display.display();
    }
  }
