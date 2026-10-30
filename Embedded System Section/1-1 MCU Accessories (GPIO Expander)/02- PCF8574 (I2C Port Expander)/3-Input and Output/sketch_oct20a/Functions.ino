void PCF_init(unsigned char config){
  Wire.begin();
  Wire.beginTransmission(PCF_ADDRESS);
  Wire.write(config);     
  Wire.endTransmission();
}

void sendTransmission(unsigned data){
  Wire.beginTransmission(PCF_ADDRESS);
  Wire.write(data);
  Wire.endTransmission();
}

void updatePin(unsigned char index, boolean value){
  bitWrite(pins, index, value);
}

void updatePin_and_send(unsigned char index, boolean value){
  updatePin(index, value);
  sendTransmission(pins);
}

void returnInput_and_send(unsigned char index){
  updatePin(index, 1);
  sendTransmission(pins);
}

