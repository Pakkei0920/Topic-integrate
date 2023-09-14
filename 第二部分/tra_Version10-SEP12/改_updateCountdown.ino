void updateCountdown() {
  // 計算剩餘時間
  unsigned long currentTime = millis(); //獲取當前的系統時間（以毫秒為單位）並將其存儲在 currentTime 變數中。millis() 函式通常用於獲取自系統開始運行以來的時間，它是一種計時器。
  unsigned long recordingTimeElapsed = currentTime - recordingStartTime; //計算自錄音開始以來經過的時間，並將其存儲在 recordingTimeElapsed 變數中。
  unsigned long recordingTimeRemaining = (recordingTimeElapsed >= RECORD_TIME * 1000 ) ? 0 : // 檢查是否已達到或超過了錄音的最大允許時間（RECORD_TIME 的值乘以 1000，以將其轉換為毫秒）。
((RECORD_TIME * 1000) - recordingTimeElapsed); //用於計算錄音開始以來的剩餘時間，以毫秒為單位。這可用於在錄音過程中顯示剩餘時間或執行與剩餘時間相關的任何其他操作。



// 在OLED上顯示倒計時
  if (canrecording == false && endrecording == false) {
    u8g2.setFont(u8g2_font_unifont_t_chinese2);  // use chinese2 for all the glyphs of "你好世界"
    u8g2.setFontDirection(0); //用於設置字體的方向。0：表示正常方向。文字將按照正常的左到右、上到下的方式排列。這是通常的文本排列方向。
    u8g2.clearBuffer(); //用於清除 U8g2 圖形緩衝區（buffer）的函式呼叫。
    u8g2.setCursor(0, 15); //將從左上角位於 (0, 15) 的位置開始繪製。
    u8g2.print("正在錄音中..."); //在 U8g2 圖形庫中輸出文字 "正在录音中..."
    u8g2.setCursor(0, 40); //調用將文本的左上角放在 x=0、y=40 的位置。
    u8g2.print("錄音時間還有：");  //在 U8g2 图形库中输出文本 "录音时间还有："
    u8g2.setCursor(98, 40); //调用将文本的左上角放在 x=98、y=40 的位置。
    u8g2.print(recordingTimeRemaining / 1000);  //在U8g2圖形庫中輸出一個整數值，該整數值表示錄音時間剩餘的秒數。    
    u8g2.sendBuffer(); //用於將繪製在圖形緩衝區中的內容實際渲染到顯示設備上，以顯示圖形或文本等元素。
    delay(200);
    fill_solid(leds, NUM_LEDS, CRGB(255, 90, 90));//rgb red
  FastLED.show();//用於將LED顏色效果實際呈現到硬體上的關鍵函數
    }
    
 if (waiting == true){ //用於檢查一個名為 waiting 的布爾變數是否等於 true。
    u8g2.setFont(u8g2_font_unifont_t_chinese2);  // use chinese2 for all the glyphs of "你好世界"
    u8g2.clearBuffer(); //用於清空 U8g2 圖形庫的緩衝區。
    u8g2.setCursor(0, 12); //用於在使用U8g2圖形庫時設置文字的顯示位置。
    u8g2.print("正在發送和打掃...");    // Chinese "Hello World" 
    u8g2.setCursor(0, 40); //用於在使用U8g2圖形庫時設置文字的顯示位置。
    u8g2.print("請等等 Ples wait..."); //在顯示設備上繪製文本消息 “請等等 Ples wait...”
    u8g2.sendBuffer(); //用於將緩衝區中的內容發送到顯示幕上以進行實際顯示的命令
    delay(500);
    fill_solid(leds, NUM_LEDS, CRGB(255, 204, 3));//yellow
  FastLED.show();//用於控制LED燈帶（或LED燈珠）的命令
    }
    
  if (canrecording == true){ //用於在程序中根據條件執行不同的操作。
    u8g2.setFont(u8g2_font_unifont_t_chinese2);  // use chinese2 for all the glyphs of "你好世界"
    u8g2.clearBuffer(); //用於清空圖形緩衝區的命令
    u8g2.setCursor(0, 12); // 用於在使用U8g2圖形庫時設置文字的顯示位置。
    u8g2.print（“按下按鈕錄音~”）; //在屏幕上顯示文本消息 “按下按鈕錄音~”。
    u8g2.sendBuffer(); //用於清空圖形緩衝區的命令
    delay(500);
    fill_solid(leds, NUM_LEDS, CRGB(0, 218, 255));//blue
    FastLED.show(); //用於將LED燈光效果從軟體層面同步到LED硬體上，以實際顯示效果。
     }
}    
