#include "Addresses.h"

#include <SPI.h>
#define MCP23S17_CMD_WRITE 0x40 // B0100(base) 0000(address+0)
#define MCP23S17_CMD_READ  0x41 // B0100(base) 0001(address+1)
#define CS_PIN 10 // PB2


void setup() {
  
  Serial.begin(9600);

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  SPI.begin();

  // for Enable Multi SPI Slave : 0x08
  writeRegister(IOCON_A, 0x08);

  // input / output Direction
  writeRegister(IODIR_A, 0B01101111); // 1 = Input
  writeRegister(IODIR_B, 0B11110111); // 0 = Output

  // invert PORT
  writeRegister(IPOL_A, 0x05);        // 1 = Inverted
  writeRegister(IPOL_B, 0x00);        // 0 = Normal

  // Pull-up
  writeRegister(GPPU_A, 0x05);        // 1 = Pull-up Enabled
  writeRegister(GPPU_B, 0x00);        // 0 = Disabled
}

void loop() {

  // portA code: (copy button to Led)
  // --------------------------------
    uint8_t portA = readRegister(GPIO_A); // read PORTA
    
    bitWrite(portA, 4, bitRead(portA,0)); // copy bit 0 to bit 4
    bitWrite(portA, 7, bitRead(portA,2)); // copy bit 2 to bit 7

    writeRegister(GPIO_A, portA);         // write to PORTA
  // --------------------------------

  // portB code: (toggle pin 3)
  // --------------------------------
    uint8_t portB = readRegister(GPIO_B); // read PORTB

    bitToggle(portB, 3);

    writeRegister(GPIO_B, portB);         // write to PORTB
  // --------------------------------
  
  delay(200);
}



