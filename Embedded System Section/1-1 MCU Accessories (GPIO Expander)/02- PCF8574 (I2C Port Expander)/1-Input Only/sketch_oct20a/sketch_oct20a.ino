#include <Wire.h>

#define PCF_ADDRESS 0x20

unsigned char pins;

void setup() {
  PCF_init(255);      // all Input 
  Serial.begin(9600);
}

void loop() {

  Wire.requestFrom(PCF_ADDRESS, 1);

  if (Wire.available()) {

    pins = Wire.read();
    Serial.println(pins, BIN);

  }

  delay(500);
}
