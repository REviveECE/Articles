#include <Wire.h>

#define PCF_ADDRESS 0x20

char pins;

void setup() {
  PCF_init(0B11111111);      // all Output (OFF) 
  Serial.begin(9600);
}

void loop() {

  sendTransmission(0B01111110);
  delay(500);
  sendTransmission(0B00000000);
  delay(500);

}
