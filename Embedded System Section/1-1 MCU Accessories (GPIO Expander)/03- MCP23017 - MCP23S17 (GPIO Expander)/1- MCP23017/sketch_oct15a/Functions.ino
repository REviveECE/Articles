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
