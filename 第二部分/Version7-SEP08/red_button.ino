void redbutton(){
  redbuttonState = digitalRead(redbuttonPin);

  if (redbuttonState == HIGH) {
    HTTPClient http;

    // 设置服务器URL
    http.begin("http://topic.paki91.com/button.php");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String postData = "data=1"; // 1表示按钮按下
    int httpResponseCode = http.POST(postData);
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("HTTP POST failed, error: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
}
