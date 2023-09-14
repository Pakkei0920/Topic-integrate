void i2s_adc(void *arg) //通常用於處理音訊數據的讀取和處理
{
    int i2s_read_len = I2S_READ_LEN; //將 i2s_read_len 設定為 I2S_READ_LEN 的值，即將 I2S_READ_LEN 的值賦給 i2s_read_len 變數。
    int flash_wr_size = 0; //被用來追蹤一個值，該值代表某種寫入（write）操作的大小或計數。
    size_t bytes_read; //記錄已讀取的位元組數目。例如，當讀取檔案、接收網路數據或執行類似的操作時，可以使用 bytes_read 來跟蹤已經成功讀取的位元組數目。

    char* i2s_read_buff = (char*) calloc(i2s_read_len, sizeof(char)); //創建一個具有指定大小的字符數據緩衝區，用於存儲從某個資料源（可能是音訊數據）讀取的數據。
    C
    i2s_read(I2S_PORT, (void*) i2s_read_buff, i2s_read_len, &bytes_read, portMAX_DELAY); //是從指定的 I2S 介面讀取音訊數據，並將它存儲到 i2s_read_buff 中，同時追蹤實際讀取的位元組數目，直到成功讀取為止，或者在無限等待期間出現錯誤。
    i2s_read(I2S_PORT, (void*) i2s_read_buff, i2s_read_len, &bytes_read, portMAX_DELAY);//是從指定的 I2S 介面讀取音訊數據，並將它存儲到 i2s_read_buff 中，同時追蹤實際讀取的位元組數目，直到成功讀取為止，或者在無限等待期間出現錯誤。
    Serial.print("Recing.."); //是在控制台上輸出一個表示音訊錄製（Recording）正在進行的訊息，以提示用戶或開發人員該操作正在執行中。
    
    while (flash_wr_size < FLASH_RECORD_SIZE) { //是當 flash_wr_size 變數的值小於 FLASH_RECORD_SIZE 變數的值時，執行迴圈內的程式碼。
        i2s_read(I2S_PORT, (void*) i2s_read_buff, i2s_read_len, &bytes_read, portMAX_DELAY); //從指定的 I2S 介面讀取音訊數據，並將它存儲到 i2s_read_buff 中，同時記錄實際讀取的位元組數目，直到成功讀取指定的位元組數量，
        i2s_adc_data_scale(flash_write_buff, (uint8_t*)i2s_read_buff, i2s_read_len); //調用自定義函式 i2s_adc_data_scale，將來自 i2s_read_buff 的原始音訊數據進行處理，並將處理後的結果存儲在 flash_write_buff 中。
        file.write((const byte*) flash_write_buff, i2s_read_len); //將位於 flash_write_buff 緩衝區中的數據寫入到代表文件的 file 中，並且寫入的數據長度為 i2s_read_len。
        flash_wr_size += i2s_read_len; //將 i2s_read_len 中讀取的位元組數添加到 flash_wr_size 中，以便追蹤已經寫入的數據的總大小。
        ets_printf("Sound recording %u%%\n", flash_wr_size * 100 / FLASH_RECORD_SIZE); //目的是輸出一個表示音訊錄製進度的訊息，顯示已經寫入的數據占預期總數據的百分比。
    }
    file.close(); //是將一個已經打開的文件關閉，以確保文件操作被正確結束。

    free(i2s_read_buff); //使用 free 函式來釋放 i2s_read_buff 指向的動態分配的記憶體。
    i2s_read_buff = NULL; //將 i2s_read_buff 設置為 NULL，確保不再通過這個指標訪問釋放的內存。
    free(flash_write_buff); //使用 free 函式來釋放 flash_write_buff 指向的動態分配的記憶體。同樣地，釋放後，flash_write_buff 變數不再指向任何內存。
    flash_write_buff = NULL; //將 flash_write_buff 設置為 NULL，確保不再通過這個指標訪問釋放的內存。
    
    endrecording = true; //結束錄音
    waiting = true; //表示程式或某個部分正在等待某個條件的滿足或某個事件的發生。程式可能會進入一個等待狀態，直到條件滿足，然後再繼續執行後續的操作。
    
    
    if(isWIFIConnected){
      uploadFile(); //用於上傳文件或數據到某個遠端伺服器或設備
      Serial.println(" *** I2S END *** ");} //用來表示某個操作或事件已經完成。
      

  SPIFFS.format();  // SPIFFS格式化代码

  SPIFFSInit(); //用來初始化 SPI Flash File System（SPIFFS）
  i2sInit(); //用來初始化 I2S（Inter-IC Sound）接口的
  
  delay(500);
  
  waiting = false; //表示程式或某個部分不再等待某個條件的滿足或某個事件的發生，它現在可以繼續執行後續的操作。
  
  vTaskDelete(NULL);//結束任務

  
}
