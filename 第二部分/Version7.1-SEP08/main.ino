void i2s_adc(void *arg)
{
    int i2s_read_len = I2S_READ_LEN;
    int flash_wr_size = 0;
    size_t bytes_read;

    char* i2s_read_buff = (char*) calloc(i2s_read_len, sizeof(char));
    uint8_t* flash_write_buff = (uint8_t*) calloc(i2s_read_len, sizeof(char));

    i2s_read(I2S_PORT, (void*) i2s_read_buff, i2s_read_len, &bytes_read, portMAX_DELAY);
    i2s_read(I2S_PORT, (void*) i2s_read_buff, i2s_read_len, &bytes_read, portMAX_DELAY);
    
    Serial.print("Recing..");
    
    while (flash_wr_size < FLASH_RECORD_SIZE) {
        i2s_read(I2S_PORT, (void*) i2s_read_buff, i2s_read_len, &bytes_read, portMAX_DELAY);
        i2s_adc_data_scale(flash_write_buff, (uint8_t*)i2s_read_buff, i2s_read_len);
        file.write((const byte*) flash_write_buff, i2s_read_len);
        flash_wr_size += i2s_read_len;
        ets_printf("Sound recording %u%%\n", flash_wr_size * 100 / FLASH_RECORD_SIZE);
    }
    file.close();

    free(i2s_read_buff);
    i2s_read_buff = NULL;
    free(flash_write_buff);
    flash_write_buff = NULL;
    
    endrecording = true; //結束錄音
    waiting = true;
    
    
    if(isWIFIConnected){
      uploadFile();
      Serial.println(" *** I2S END *** ");}
      

  SPIFFS.format();  // SPIFFS格式化代码

  SPIFFSInit();
  i2sInit();
  
  delay(500);
  
  waiting = false;
  
  vTaskDelete(NULL);//結束任務

  
}
