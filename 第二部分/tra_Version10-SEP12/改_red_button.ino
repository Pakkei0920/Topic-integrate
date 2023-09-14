void redbutton(){
  redbuttonState = digitalRead(redbuttonPin); //是讀取特定數位引腳 redbuttonPin 上的電位狀態，並將這個狀態儲存在 redbuttonState 變數中。redbuttonState 將包含一個值，通常是 HIGH（表示高電位，通常是1）或 LOW（表示低電位，通常是0），以反映數位引腳的電壓狀態。

  if (redbuttonState == HIGH) { //用來檢查 redbuttonState 變數的值是否等於 HIGH。
    HTTPClient http; //通常用於建立和執行 HTTP 請求，以與網絡服務進行通信。

    // 设置服务器URL
    http.begin("http://topic.paki91.com/button.php"); //表示要訪問的遠程伺服器的位置和資源。
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); //表示請求主體中的數據將以 URL 編碼的形式提交，用於將表單數據發送到伺服器。
    String postData = "data=1"; // 1表示按钮按下
    int httpResponseCode = http.POST(postData); //將執行一個 HTTP POST 請求，將 postData 中的數據發送到目標 URL。
    if (httpResponseCode > 0) { //檢查 httpResponseCode 是否大於零，
      Serial.print("HTTP Response code: "); //如果請求成功（狀態碼大於零），則這兩行代碼會顯示 HTTP 回應的狀態碼。這些訊息可以用於調試和記錄。
      Serial.println(httpResponseCode); //如果請求成功（狀態碼大於零），則這兩行代碼會顯示 HTTP 回應的狀態碼。這些訊息可以用於調試和記錄。
    } else { //如果 if 條件不成立，則執行 else 塊中的代碼
      Serial.print("HTTP POST failed, error: "); //如果請求不成功（狀態碼小於或等於零），則這兩行代碼會顯示一條錯誤訊息，其中包含 HTTP POST 失敗的提示，以及錯誤的狀態碼。
      Serial.println(httpResponseCode); //如果請求不成功（狀態碼小於或等於零），則這兩行代碼會顯示一條錯誤訊息，其中包含 HTTP POST 失敗的提示，以及錯誤的狀態碼。
    }
    http.end(); //用於結束 HTTPClient 對象的方法。
  }
}
