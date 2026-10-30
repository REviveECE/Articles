// Direction Registers (0: input , 1: Output)
#define IODIR_A 0x00
#define IODIR_B 0x01

// Input Polarity Inversion (1 = Inverted, 0 = Normal)
#define IPOL_A 0x02
#define IPOL_B 0x03

// Interrupt-on-Change Enable (1 = Enabled, 0 = Disabled)
#define GPINTEN_A 0x04
#define GPINTEN_B 0x05

// Default Compare Register for Interrupt-on-Change
#define DEFVAL_A 0x06
#define DEFVAL_B 0x07

// Interrupt Control Register
#define INTCON_A 0x08
#define INTCON_B 0x09

// I/O Expander Configuration Register
#define IOCON_A 0x0A
#define IOCON_B 0x0B

// Pull-Up Resistor Configuration (1 = Enabled, 0 = Disabled)
#define GPPU_A  0x0C  
#define GPPU_B  0x0D  

// Interrupt Flag Register (which pin caused interrupt)
#define INTF_A  0x0E  
#define INTF_B  0x0F  

// Interrupt Capture Register (port value at time of interrupt)
#define INTCAP_A  0x10  
#define INTCAP_B  0x11  

// Port Value Register (reads pins / writes output latch)
#define GPIO_A  0x12 
#define GPIO_B  0x13 

// Output Latch Register
#define OLAT_A  0x14 
#define OLAT_B  0x15 