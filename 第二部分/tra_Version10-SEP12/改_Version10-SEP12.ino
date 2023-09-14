//V10 加入注解
#include <driver/i2s.h> //i2s麥克風函數庫
#include <SPIFFS.h> //SPIFFS檔案系統函數庫
#include <WiFi.h> //WIFI函數庫
#include <HTTPClient.h> //HTTP函數庫
#include <Adafruit_GFX.h> //OLED顯示器函數庫
#include <Adafruit_SSD1306.h> //OLED顯示器函數庫
#include <U8g2lib.h> //顯示中文函數庫

#define I2S_WS 15 //Pin 15
#define I2S_SD 13 //Pin 13
#define I2S_SCK 2 //Pin 2
#define I2S_PORT I2S_NUM_0 //是 I2S_PORT 的值。
#define I2S_SAMPLE_RATE   (16000) //音訊信號每秒被採集 16000 次。
#define I2S_SAMPLE_BITS   (16) //音訊採樣被設置為16位，意味著每個採樣點用16位二進位數表示
#define I2S_READ_LEN      (16 * 1024) //設置為 16 * 1024 位元組，意味著每次從音訊輸入設備讀取 16 * 1024 位元組的音訊數據。
#define RECORD_TIME       (15) //Seconds //錄音時間被設置為15秒。
#define I2S_CHANNEL_NUM   (1) //音訊通道的數量被設置為 1，表示單聲道音訊。
#define FLASH_RECORD_SIZE (I2S_CHANNEL_NUM * I2S_SAMPLE_RATE * I2S_SAMPLE_BITS / 8 * RECORD_TIME) //用於分配或管理快閃記憶體空間，以確保足夠的儲存容量用於音訊錄製。

#define SCREEN_WIDTH 128 //屏幕的寬度為128個圖元
#define SCREEN_HEIGHT 32 //螢幕的高度為32個圖元
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);//用於控制具有特定解析度的OLED顯示幕，

File file; //打開檔案、讀取檔案內容或寫入數據。
const char filename[] = "/recording.wav"; //用於打開、讀取或寫入檔 「recording.wav」。
const int headerSize = 44; //用來確保在處理 WAV 檔時正確地跳過頭部並讀取音訊數據。
bool isWIFIConnected; //用來表示一個狀態或條件，即是否已經建立了與Wi-Fi網路的連接。

bool canrecording = true; // 新增标志变量
bool endrecording = false; // 新增标志变量
const int buttonPin = 14;
int redbuttonPin = 27; //紅色
int redbuttonState = 0; // 保存按钮状态
unsigned long recordingStartTime; // 记录录音开始时间
bool waiting = false; //等待狀態

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0,U8X8_PIN_NONE); //這個驅動適用於一個 128x64 像素解析度的 SSD1306 型號的 OLED 顯示幕，並且使用硬體 I2C 介面進行通信。
int clock_center_x=64; //時鐘的中心位於水準方向的第64個圖元
int clock_center_y=32; //時鐘的中心位於垂直方向的第32個圖元

//
#include <FastLED.h> //包含了FastLED庫，使您能夠輕鬆控制LED燈帶。
#define LED_PIN    12 //定義了LED燈帶的控制引腳。 在這個例子中，LED燈帶連接到Arduino的引腳12。
#define NUM_LEDS   60 // 定義了LED燈帶上LED的數量。 在這個例子中，有60個LED
#define BRIGHTNESS 64 //定義了LED的亮度級別。 在這個例子中，亮度設置為64，表示LED的亮度。
CRGB leds[NUM_LEDS]; //用於存儲LED的顏色資訊。 這個陣列有60個元素，每個元素表示一個LED的顏色，使用CRGB物件來表示顏色。
//

void setup() {
  pinMode(redbuttonPin, INPUT); //將redbuttonPin引腳設置為輸入模式，用於讀取一個按鈕或開關的狀態。
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //初始化了一個SSD1306 OLED顯示幕，使用了0x3C作為I2C位址。 它設置了顯示幕的電源電壓模式。
  chinese_text(); //用於配置顯示幕以支援中文字元顯示。
  Serial.begin(115200); //初始化了串口通信，波特率設置為115200。
  SPIFFSInit(); //用於初始化SPI Flash文件系統，以便後續的檔讀寫操作。
  i2sInit(); //用於初始化I2S（Inter-IC Sound）音訊介面，通常用於音訊輸入和輸出。
  delay(500); //延遲500毫秒
  xTaskCreate(wifiConnect, "wifi_Connect", 4096, NULL, 0, NULL); //任務的功能是連接到WiFi網路。 這個任務似乎使用了FreeRTOS多任務庫來實現。
  //
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); //初始化了FastLED庫，用於控制連接到引腳LED_PIN的WS2812型號的RGB LED燈帶。 它還指定了LED的顏色排列順序為GRB。
  FastLED.setBrightness(BRIGHTNESS); //設置LED燈帶的亮度，使用了之前定義的BRIGHTNESS值。
}

void loop() {
  int buttonState = digitalRead(buttonPin); //讀取連接到buttonPin引腳的按鈕的狀態，buttonState將存儲按鈕的狀態，可能是HIGH（按下）或LOW（未按下）。
   
  if (buttonState == HIGH && canrecording) { //如果按鈕被按下且canrecording為true，
    recordingStartTime = millis(); //記錄當前時間，以便計算錄音的持續時間。
    xTaskCreate(i2s_adc, "i2s_adc", 1024 * 2, NULL, 1, NULL); //創建一個名為“i2s_adc”的任務，可能是用於處理音訊錄音。
    Serial.println("目前為start"); //串口輸出上列印消息，指示當前狀態為“start”
    canrecording = false; //不可以錄音
    endrecording = false; //還沒結束
  } 
  else if (buttonState == LOW && endrecording && waiting == false) { //如果按鈕沒有被按下且endrecording為true且waiting為false
    canrecording = true; //設置canrecording為true，表示可以進行下一次錄音。
    delay(500); //延遲500毫秒，可能是為了防止短時間內多次觸髮按鈕。
  }
  
  updateCountdown(); //一個函數調用，可能用於更新倒計時顯示。
  redbutton(); //一個函數調用，可能用於處理按鈕的狀態，但實際操作需要查看redbutton（）函數的內容。
 
}


void SPIFFSInit(){
  if(!SPIFFS.begin(true)){ //檢查SPIFFS初始化是否成功。 如果初始化失敗，條件為真（true）
    Serial.println("SPIFFS initialisation failed!"); //檢查SPIFFS初始化是否成功。 如果初始化失敗，條件為真（true），則執行以下操作。
    while(1) yield(); //檢查SPIFFS初始化是否成功。 如果初始化失敗，條件為真（true）
  }

  SPIFFS.remove(filename); //嘗試刪除名為filename的檔。 
  file = SPIFFS.open(filename, FILE_WRITE); //嘗試以寫入模式打開檔filename。 這個檔是用來存儲音訊數據的檔
  if(!file){ //檢查檔是否成功打開。 如果文件打開失敗，條件！ file為真，
    Serial.println("File is not available!"); //串口输出上打印消息，指示文件不可用。
  }

  byte header[headerSize]; //創建一個名為header的位元組陣列，大小為headerSize。 這個陣列用於存儲WAV檔的文件頭資訊。
  wavHeader(header, FLASH_RECORD_SIZE); //調用wavHeader函數，該函數似乎用於生成WAV檔的檔頭。 header陣列將被填充為WAV文件的標頭數據。

  file.write(header, headerSize); //將WAV檔頭數據寫入打開的檔，確保檔的開始部分包含正確的WAV檔頭。
  listSPIFFS(); //列出SPIFFS文件系統中的檔，以供參考或調試目的。
}

void i2sInit(){ //。
  i2s_config_t i2s_config = { //定義一個結構體，用於配置I2S介面的參數
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX), //可以發送數據也可以接收數據。
    .sample_rate = I2S_SAMPLE_RATE,//置音訊採樣率，即每秒採集多少個音訊樣本。
    .bits_per_sample = i2s_bits_per_sample_t(I2S_SAMPLE_BITS),//設置為一個特定值（I2S_SAMPLE_BITS），並將其強制轉換為i2s_bits_per_sample_t類型。
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,//使用左聲道。
    .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),//確保音訊數據將以I2S協議進行傳輸，並且每個音訊樣本的位序將是MSB優先。 這是一種常見的音訊數據傳輸格式，適用於許多數位音訊設備。
    .intr_alloc_flags = 0,//分配中斷標誌，這裡設置為0，表示不分配中斷。
    .dma_buf_count = 64, //DMA（Direct Memory Access）緩衝區的數量。
    .dma_buf_len = 1024, //DMA緩衝區的長度。
    .use_apll = 1 //是否使用APLL（Audio PLL）作為音訊時鐘源，這裡設置為1，表示使用APLL。
  };

  i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);//安裝了I2S驅動程式，以便使用指定的I2S埠和配置。 它將I2S配置（i2s_config）應用於指定的I2S埠

  const i2s_pin_config_t pin_config = { //定義了一個I2S引腳配置（i2s_pin_config_t）。 這些配置用於定義I2S介面的引腳連接，以確保數據正確地從外部音訊設備傳輸到ESP32。
    .bck_io_num = I2S_SCK, //指定I2S時鐘（SCK）的引腳編號
    .ws_io_num = I2S_WS, //指定I2S幀同步（WS）的引腳編號
    .data_out_num = -1, //此欄位在這裡設置為-1，表示不使用資料輸出引腳。
    .data_in_num = I2S_SD //指定I2S數據輸入（SD）的引腳編號。 這是從外部音訊設備接收音訊數據的引腳。
  };

  i2s_set_pin(I2S_PORT, &pin_config); //將上面定義的引腳配置應用於指定的I2S埠。
}


void i2s_adc_data_scale(uint8_t * d_buff, uint8_t* s_buff, uint32_t len)
{
    uint32_t j = 0;//初始化一個變數j，用於跟蹤目標緩衝區的索引，初始值為0。
    uint32_t dac_value = 0;//初始化一個變數dac_value，用於存儲處理后的音訊樣本值，初始值為0。
    for (int i = 0; i < len; i += 2) { //用於遍曆輸入音訊數據。 迴圈步長為2，因為每個音訊樣本佔用2個字節。
        dac_value = ((((uint16_t) (s_buff[i + 1] & 0xf) << 8) | ((s_buff[i + 0]))));//用於後續的音訊處理。 這種操作通常在音訊採樣和處理中用於將多個字節的數據合併成一個有意義的整數值。
        d_buff[j++] = 0;//為了填充目標緩衝區中的一些額外位元組，但沒有實際的音訊數據。
        d_buff[j++] = dac_value * 256 / 2048;//用於調整音訊樣本值的幅度，以滿足特定的音訊處理要求。
    }
}


void example_disp_buf(uint8_t* buf, int length)//表示數據的位元組陣列，length 是數據的長度。
{
    printf("======\n");//用於在列印資料前創建一個可讀性良好的分隔線。
    for (int i = 0; i < length; i++) {//用於遍歷數據陣列 buf 中的每個位元組，i 是循環變數，從0開始，逐漸增加到 length - 1。
        printf("%02x ", buf[i]);//用於以兩位十六進位的格式列印每個位元組。 buf[i] 表示當前位元組的值。
        if ((i + 1) % 8 == 0) {//檢查當前迴圈反覆運算是否已經列印了8個字節，如果是，就執行下面的代碼塊。
            printf("\n");//列印一個換行符，以便下一行數據從新的一行開始。
        }
    }
    printf("======\n");//用於列印分隔線的代碼，每列印完8個字節后，都會列印一次，以便區分不同的數據塊。
}

void wavHeader(byte* header, int wavSize){ //作用是生成 WAV 檔的頭部資訊，這個頭部資訊描述了音訊數據的格式和屬性，它必須出現在WAV 檔的開頭才能正確識別和播放音訊數據。
  header[0] = 'R'; //R' 表示 “RIFF”，這是 Resource Interchange File Format 的縮寫，用於標識 RIFF 格式的檔。
  header[1] = 'I'; //'I' 表示 “I”，它是 RIFF 檔案格式的一部分，表示這是一個 RIFF 格式的檔。
  header[2] = 'F'; //F' 表示 “F”，也是 RIFF 檔案格式的一部分，用於進一步標識文件類型。
  header[3] = 'F'; // 'F' 再次表示 “F”，它與前面的 'F' 一起構成 “RIFF”，作為檔類型的確認。
  unsigned int fileSize = wavSize + headerSize - 8; //用於設置 WAV 檔案的檔案大小資訊，以確保其他軟體能夠正確讀取和播放該檔。
  header[4] = (byte)(fileSize & 0xFF); //存儲了檔案大小的最低位元組。
  header[5] = (byte)((fileSize >> 8) & 0xFF); //存儲了檔案大小的次低位元組。
  header[6] = (byte)((fileSize >> 16) & 0xFF); //存儲了檔案大小的次高位元組。
  header[7] = (byte)((fileSize >> 24) & 0xFF); //存儲了檔案大小的最高位元組。
  header[8] = 'W'; // 設置為 『W』，表示檔類型的第一個字節為 『W』。
  header[9] = 'A'; // 設置為 『A』，表示檔類型的第二個字節為 『A』。
  header[10] = 'V'; //設置為 'V'，表示檔類型的第三個字節為 'V'。
  header[11] = 'E'; // 設置為 『E』，表示檔類型的第四個字節為 『E』。
  header[12] = 'f'; //設定為 'f'，表示檔格式的第一個字節為 'f'
  header[13] = 'm'; // 設置為 'm'，表示檔格式的第二個字節為 'm'。
  header[14] = 't'; //設定為 't'，表示檔案格式的第三個字節為 't'
  header[15] = ' '; //設置為 '（空格），表示檔格式的第四個字節為空格。
  header[16] = 0x10; //音訊編碼格式的標識碼，表示音訊數據使用脈衝編碼調製（PCM）進行編碼。
  header[17] = 0x00; //表示額外的編碼參數（如壓縮係數等）為預設值，這通常在 PCM 編碼中是這樣的。
  header[18] = 0x00; //表示額外的編碼參數（如壓縮係數等）為預設值，這通常在 PCM 編碼中是這樣的。
  header[19] = 0x00; //表示額外的編碼參數（如壓縮係數等）為預設值，這通常在 PCM 編碼中是這樣的。
  header[20] = 0x01; //表示 WAV 檔頭中的音訊數據是單聲道（Mono）的。
  header[21] = 0x00; // 表示 WAV 檔頭中的音訊數據的通道數的第二個字節
  header[22] = 0x01; //表示音訊數據的位深度的低位元組是 0x01，即 16 位。
  header[23] = 0x00; //表示音訊數據的位深度的高位元組是 0x00。
  header[24] = 0x80; // 表示音訊數據的採樣率的第一個字節為 0x80。
  header[25] = 0x3E; // 表示音訊數據的平均位元元組率（每秒的位元元組數）的第一個字節為 0x3E。
  header[26] = 0x00; //表示音訊數據的平均位元元組率的第二個字節為 0x00。
  header[27] = 0x00; //表示音訊數據的平均位元元組率的第三個字節為 0x00。
  header[28] = 0x00; //表示音訊數據的平均位元元組率的第四個字節為 0x00。
  header[29] = 0x7D; //表示音訊數據塊對齊的值，即數據塊的大小（每次採樣的位元元組數）的第一個字節為 0x7D。
  header[30] = 0x01; // 表示音訊數據的位深度（每個樣本的位數）的第一個字節為 0x01。
  header[31] = 0x00; //表示音訊數據的位深度的第二個字節為 0x00。
  header[32] = 0x02; //表示聲道數的值的第一個字節為 0x02，這表示雙聲道（立體聲）音訊。
  header[33] = 0x00; //表示聲道數的值的第二個字節為 0x00。
  header[34] = 0x10; //表示每秒採樣的幀數（採樣率）的第一個字節為 0x10，這表示 16 kHz 的採樣率。
  header[35] = 0x00; //表示每秒採樣的幀數的第二個字節為 0x00
  header[36] = 'd'; //設置數據塊標識的第一個字節為字元 'd'，表示這是數據塊的開始。
  header[37] = 'a'; //設置數據塊標識的第二個字節為字元 『a』。
  header[38] = 't'; //設置數據塊標識的第三個字節為字元 『t』。
  header[39] = 'a'; //設置數據塊標識的第四個字節為字元 'a'，表示 “data”，這是 WAV 檔中實際音訊數據存儲的部分。
  header[40] = (byte)(wavSize & 0xFF); //設置WAV數據長度的第一個字節，使用位掩碼 0xFF 提取最低位元組，將其放入header陣列的第40個位置。
  header[41] = (byte)((wavSize >> 8) & 0xFF); //設置WAV數據長度的第二個字節，通過右移 8 位並使用位掩碼來提取次低位元組。
  header[42] = (byte)((wavSize >> 16) & 0xFF); //設置WAV數據長度的第三個字節，通過右移 16 位並使用位掩碼來提取次高位元組。
  header[43] = (byte)((wavSize >> 24) & 0xFF); //設置WAV數據長度的第四個字節，通過右移 24 位來提取最高位元組。
  
}


void listSPIFFS(void) {
 
  static const char line[] PROGMEM =  "=================================================";//用於在檔案清單之間創建分隔線。

  Serial.println(FPSTR(line));//通過串行通信向終端輸出分隔線，FPSTR 用於從 PROGMEM 中讀取字串。
  Serial.println(F("  File name                              Size")); //輸出檔案清單的標題，顯示檔名和檔案大小。
  Serial.println(FPSTR(line)); //再次輸出分隔線，分隔標題和檔案清單。

  fs::File root = SPIFFS.open("/"); //打開 SPIFFS 檔案系統的根目錄，root 將指向該目錄。
  if (!root) { //檢查是否成功打開了根目錄，如果未成功，輸出錯誤消息。
    Serial.println(F("Failed to open directory")); //通過串行通信向終端輸出一條錯誤消息，提示用戶無法成功打開 SPIFFS 檔案系統的根目錄。
    return; //無法打開目錄時，立即退出當前函數
  }
  if (!root.isDirectory()) { //檢查根目錄是否為目錄而不是檔，如果不是目錄，也輸出錯誤消息。
    Serial.println(F("Not a directory")); //通過串行通信輸出一條錯誤消息，提示使用者根目錄不是一個目錄。
    return; //是在不是目錄的情況下，立即退出當前函數
  }

  fs::File file = root.openNextFile(); //用於打開 SPIFFS 根目錄中的第一個文件或目錄，並將其賦值給 file 變數。
  while (file) { 

    if (file.isDirectory()) { //檢查目前打開的專案是否是一個目錄。
      Serial.print("DIR : "); //列印文本 「DIR ： 」 以指示接下來的內容是一個目錄（資料夾）。
      String fileName = file.name(); //獲取目錄的名稱並列印它。
      Serial.print(fileName); //將目錄的名稱列印到串行通信中
    } else { //如果目前專案不是目錄（即是一個檔)
      String fileName = file.name(); //獲取當前打開檔的名稱，並將其存儲在名為 fileName 的字串變數中。
      Serial.print("  " + fileName); //在串行通信中列印兩個空格，然後是文件的名稱（fileName 變數）。
      // File path can be 31 characters maximum in SPIFFS //
      int spaces = 33 - fileName.length(); // Tabulate nicely //計算需要多少空格來對齊檔名。
      if (spaces < 1) spaces = 1; //計算出的空格數量小於1，它會將空格數量設置為1，以確保至少有一個空格。
      while (spaces--) Serial.print(" "); //在檔名后列印計算出的空格數量，以便對齊下一列的檔大小資訊。
      String fileSize = (String) file.size(); //獲取當前檔的大小並將其存儲在名為 fileSize 的字串變數中。
      spaces = 10 - fileSize.length(); // Tabulate nicely //計算需要多少空格來對齊檔大小資訊，假設最多有 10 個字元寬度。
      if (spaces < 1) spaces = 1; //計算出的空格數量小於1，它會將空格數量設置為1，以確保至少有一個空格。
      while (spaces--) Serial.print(" "); //在檔案大小資訊后列印計算出的空格數量，以確保格式對齊。
      Serial.println(fileSize + " bytes"); //列印檔大小資訊，後跟 “ bytes” 以表示檔的大小單位。
    }

    file = root.openNextFile(); //用於獲取下一個文件或目錄，並將其賦值給 file 變數，以便下一次反覆運算處理。
  }

  Serial.println(FPSTR(line)); //用於將這個常量字串從程式存儲空間複製到程式的記憶體空間，以便進行串行列印。
  Serial.println(); //列印一個空行，用於在不同的輸出段之間創建垂直間隔，使輸出更易讀。
  delay(1000); //1000 毫秒（1 秒）的延遲
}

void wifiConnect(void *pvParameters){ //
  isWIFIConnected = false; //將名為 isWIFIConnected 的全域變數設置為 false，表示 Wi-Fi 連接尚未建立。
  char* ssid = "6412"; //定義了Wi-Fi網路的名稱（SSID）和密碼。 
  char* password = "20020920"; //定義了Wi-Fi網路的名稱（SSID）和密碼。 

  WiFi.begin(ssid, password); //開始Wi-Fi連接，使用上面定義的SSID和密碼。 它啟動了連接過程。
  while(WiFi.status() != WL_CONNECTED){ //用於檢查連接狀態，WL_CONNECTED 表示已連接。 因此，這個迴圈會一直運行，直到成功連接到Wi-Fi網路。
    vTaskDelay(500); //讓當前任務延遲 500 毫秒，這個延遲是為了減輕 CPU 的負擔，同時等待 Wi-Fi 連接完成。
    Serial.print("."); //等待連接時，它會每隔 500 毫秒列印一個點，以指示連接尚未建立。
  }
  isWIFIConnected = true; //一旦成功連接到Wi-Fi，它將isWIFIConnected設置為 true，表示連接已建立。
  while(true){ //一旦連接建立，就會一直運行。
    vTaskDelay(1000); //使任務每隔 1000 毫秒（1 秒）休眠一次，這是為了避免 CPU 過度使用，同時保持任務處於活動狀態
  }
}

void uploadFile(){
  file = SPIFFS.open(filename, FILE_READ); //用於從 SPIFFS（SPI Flash File System）檔案系統中打開檔的函數。 如果檔成功打開，file 物件將引用該檔，
  if(!file){ //用於檢查檔是否成功打開。 如果檔未成功打開，即 file 物件為空（null）
    Serial.println("FILE IS NOT AVAILABLE!"); //如果檔未成功打開，將在串行監視器上列印一條消息，指示檔不可用。
    return; //終止了函數的執行並立即返回。
  }

  Serial.println("現在發送中..."); //在串行監視器上列印消息，指示檔正在發送中。

  HTTPClient client; //創建一個名為 client 的 HTTPClient 物件，用於與伺服器建立連接併發送 HTTP 請求。
  client.begin("http://topic.paki91.com/upload_audio.php"); //設置 HTTP 請求的目標 URL，這是上傳檔的目標伺服器的位址。
  client.addHeader("Content-Type", "audio/wav"); //設置 HTTP 請求的頭部資訊，指定內容類型為 “audio/wav”，表示將要上傳的檔是 WAV 音訊檔。
  int httpResponseCode = client.sendRequest("POST", &file, file.size()); //發送 HTTP POST 請求，其中包括要上傳的檔案內容。 file 物件包含要上傳的檔，file.size（） 傳回檔的大小。 HTTPResponseCode 變數將包含伺服器的響應代碼，通常 200 表示成功。
  Serial.print("httpResponseCode : "); //在串行監視器上列印 HTTP 回應代碼，以便進行調試。
  Serial.println(httpResponseCode); //將實際的 HTTP 回應代碼列印到串行監視器。

  if(httpResponseCode == 200){ //用於檢查 HTTP 回應代碼是否為 200，表示請求成功。
    String response = client.getString(); //如果回應成功，這行代碼將從伺服器獲取回應的內容並存儲在名為 response 的字串中。
    Serial.print("response"); //在串行監視器上列印字串 「response」
    Serial.println(response); //將從伺服器接收到的響應內容列印到串行監視器，以便查看上傳操作的結果。
  }else{ //處理 HTTP 回應代碼不為 200 的情況，即請求出現錯誤。
    String errorDescription = client.errorToString(httpResponseCode); //將根據 HTTP 回應代碼獲取相應的錯誤描述，並將其存儲在 errorDescription 變數中。
    Serial.print("HTTP Error: "); //列印一個錯誤消息的前綴。
    Serial.println(errorDescription); //將具體的錯誤描述列印到串行監視器，以便查看錯誤的詳細資訊。
  }
  file.close(); //關閉之前打開的檔，即 file 物件。
  client.end(); //關閉 HTTP 用戶端，即 client 物件。
}
