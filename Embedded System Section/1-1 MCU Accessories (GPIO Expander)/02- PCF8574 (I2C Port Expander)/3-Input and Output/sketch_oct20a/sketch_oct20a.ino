#include <Wire.h>

#define PCF_ADDRESS 0x20

unsigned char ledIdx[4]    = { 0, 1, 2, 3 };
unsigned char buttonIdx[3] = { 4, 5, 6    };

char pins;

void setup() {
  // Input (UP) & Output (OFF) 
  PCF_init(0B11111111); 
}

void loop() {

  Wire.requestFrom(PCF_ADDRESS, 1);

  if (Wire.available()) {

    pins = Wire.read();
    
    for (int i = 0; i < 3; i++) {

      if (bitRead(pins, buttonIdx[i]) == 0)
        updatePin(ledIdx[i], 0); // turn on
      else
        updatePin(ledIdx[i], 1); // turn off

      // we must return Button to 1' first then resend all pins
      returnInput_and_send(buttonIdx[i]); 
    }
  }

  // toggle fourth led every 200ms
  updatePin_and_send(ledIdx[3] , 1-bitRead(pins, ledIdx[3]));
  delay(200);
}
