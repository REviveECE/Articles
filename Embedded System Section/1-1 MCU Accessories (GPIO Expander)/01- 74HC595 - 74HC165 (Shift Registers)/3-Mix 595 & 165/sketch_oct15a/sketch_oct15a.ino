#define CLOCK_OUT 8
#define DATA_OUT  9
#define SHIFT_OUT 10
#define CLOCK_IN  11
#define DATA_IN   12
#define SHIFT_IN  13

unsigned int data1 , data2;

void setup() {
  DDRB = 0x2F;
}

void loop() {

  // Read Data From 74HC165:
  // -----------------------
  digitalWrite(SHIFT_IN, 0);
  delay(5);
  digitalWrite(SHIFT_IN, 1);    // trig before assign data
  data1 = update165();
  data2 = update165();
  // -----------------------

  // write Data to 74HC595 :
  // -----------------------
  digitalWrite(SHIFT_OUT, 0);
  update595(data2);
  update595(data1);
  digitalWrite(SHIFT_OUT, 1);   // trig after assign data
  // -----------------------

  delay(200);
}

