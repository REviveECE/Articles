void initProtocol() {
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
