#if (MODE == I2CMODE)

  void initProtocol(){
    Wire.begin();
  }

  void writeRegister(uint8_t reg, uint8_t value) {
    Wire.beginTransmission(MCP_ADDRESS);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
  }

  uint8_t readRegister(uint8_t reg) {
    Wire.beginTransmission(MCP_ADDRESS);
    Wire.write(reg);
    Wire.endTransmission();
    
    Wire.requestFrom((uint8_t)MCP_ADDRESS, (uint8_t)1);
    if (Wire.available()) {
      return Wire.read();
    }
    return 0;
  }

#elif (MODE == SPIMODE)

  void initProtocol(){
    pinMode(CS_PIN, OUTPUT);
    digitalWrite(CS_PIN, HIGH);

    SPI.begin();

    // for Enable Multi SPI Slave : 0x08
    writeRegister(IOCON_A, 0x08); 
  }

  void writeRegister(uint8_t reg, uint8_t value) {
    digitalWrite(CS_PIN, LOW);       
    SPI.transfer(MCP23S17_CMD_WRITE); 
    SPI.transfer(reg);              
    SPI.transfer(value);            
    digitalWrite(CS_PIN, HIGH);   
  }

  uint8_t readRegister(uint8_t reg) {
    uint8_t value = 0;
    digitalWrite(CS_PIN, LOW);      
    SPI.transfer(MCP23S17_CMD_READ); 
    SPI.transfer(reg);               
    value = SPI.transfer(0x00);    
    digitalWrite(CS_PIN, HIGH);   
    return value;
  }

#endif
