void chinese_text(){ //用於處理中文文本或執行與中文相關的操作
  u8g2.begin(); //用於初始化 U8g2 圖形顯示庫的程式碼。
  u8g2.enableUTF8Print(); //用於啟用 UTF-8 字符集的支持。這個函式可能在使用 U8g2 圖形顯示庫時使用，以便在顯示設備上顯示支持 UTF-8 編碼的多語言文本。
  u8g2.setFont(u8g2_font_6x10_tf); //用於設置 U8g2 圖形顯示庫中的字體。這個函式通常用於選擇用於顯示文本的字型或字體。
  u8g2.setFontRefHeightExtendedText(); //用於設置字體的參考高度，特別是針對擴展的文本（通常是包含上部和下部擴展字符的文本）。
  u8g2.setDrawColor(1); //設置繪圖顏色。
  u8g2.setFontPosTop(); //設置字體的位置
  u8g2.setFontDirection(0); // 設置字體的方向

  u8g2.setFont(u8g2_font_unifont_t_chinese1); //設置顯示文本所使用的字體。
  u8g2.firstPage(); //用於設置圖形顯示的頁面。
  do {
    u8g2.setCursor(0, 15);//文字大小
    u8g2.print(String("HKSAC | 开发").c_str()); //以所選的字體和其他設置進行渲染。這通常是在 U8g2 的頁面繪制循環中執行的，以確保文本正確顯示在顯示設備上。
    u8g2.setCursor(0, 35);//文字大小
    u8g2.print(String("BY Paki").c_str());
    u8g2.sendBuffer();//，用於將當前頁面的內容發送到實際的顯示設備上。
  } while (u8g2.nextPage()); //用於確保所有頁面都被順序處理並顯示在顯示設備上。一旦所有頁面都處理完畢，迴圈將退出，顯示設備將顯示所有繪制的內容。
  
}
