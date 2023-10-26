void chinese_text(){
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);

  u8g2.setFont(u8g2_font_unifont_t_chinese1);
  u8g2.firstPage();
  do {
    u8g2.setCursor(0, 15);//文字大小
    u8g2.print(String("HKSAC | 开发").c_str());
    u8g2.setCursor(0, 35);//文字大小
    u8g2.print(String("BY Paki").c_str());
    u8g2.sendBuffer();
  } while (u8g2.nextPage());
  
}
