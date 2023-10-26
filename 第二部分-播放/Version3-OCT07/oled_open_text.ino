void open_text(){
display.clearDisplay();
display.drawBitmap(2, 10, bq, 16, 16, WHITE);
display.setCursor(18, 10);display.setTextSize(2);display.setTextColor(WHITE);display.println("HKSAC");
display.drawBitmap(58, 35, ying, 16, 16, WHITE);
display.drawBitmap(74, 35, yong, 16, 16, WHITE);
display.drawBitmap(90, 35, kai, 16, 16, WHITE);
display.drawBitmap(106, 35, fa, 16, 16, WHITE);delay(200);
display.display();

delay(1000);

display.clearDisplay();
display.drawBitmap(15, 25, shu, 16, 16, WHITE);
display.drawBitmap(31, 25, de, 16, 16, WHITE);
display.drawBitmap(47, 25, ke, 16, 16, WHITE);
display.drawBitmap(63, 25, ji, 16, 16, WHITE);
display.drawBitmap(79, 25, da, 16, 16, WHITE);
display.drawBitmap(95, 25, xue, 16, 16, WHITE);delay(200);
display.display();
delay(1000);

display.clearDisplay();
display.drawBitmap(8, 10, dsbk, 64, 16, WHITE);
display.drawBitmap(18, 35, wlljz, 80, 16, WHITE);
display.setCursor(98, 35);display.setTextSize(2);display.setTextColor(WHITE);display.println("..");
delay(200);display.display();
  
}
