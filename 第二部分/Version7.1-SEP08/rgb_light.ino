// 设置所有NeoPixel为指定颜色并立即显示
void setAllPixels(uint32_t color) {
  strip.clear();
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

// NeoPixel呼吸效果函数
void breatheColor(uint32_t color, int duration) {
  strip.clear();
  for (int i = 0; i < 100; i++) {  // 这里的数字控制呼吸的快慢
    float brightness = sin(PI * i / 100.0);  // 使用正弦函数来模拟呼吸效果
    setBrightness(color, brightness);
    delay(20);  // 控制呼吸的速度，可以根据需要调整
  }
}
// 设置NeoPixel的亮度
void setBrightness(uint32_t color, float brightness) {
  strip.clear();
  uint8_t r = (uint8_t)((color >> 16) * brightness);
  uint8_t g = (uint8_t)(((color >> 8) & 0xFF) * brightness);
  uint8_t b = (uint8_t)((color & 0xFF) * brightness);
  strip.fill(strip.Color(r, g, b));
  strip.show();
}
