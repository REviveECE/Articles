void PCF_init(unsigned char config){
  Wire.begin();
  Wire.beginTransmission(PCF_ADDRESS);
  Wire.write(config);     
  Wire.endTransmission();
}
