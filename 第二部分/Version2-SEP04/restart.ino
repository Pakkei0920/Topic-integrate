void openstart() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  // 在OLED上显示
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Start up..");
  display.display();
  delay(500);
}
