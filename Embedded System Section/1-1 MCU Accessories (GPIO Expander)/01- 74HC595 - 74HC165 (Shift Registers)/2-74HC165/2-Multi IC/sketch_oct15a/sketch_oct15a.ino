#define CLOCK_IN  11
#define DATA_IN   12
#define SHIFT_IN  13

unsigned int data1 , data2;

void setup() {
  DDRB = 0B00101000;
  Serial.begin(9600);
}

void loop() {

  // Read Data From 74HC165:
  // -----------------------
  digitalWrite(SHIFT_IN, 0);
  delay(5);
  digitalWrite(SHIFT_IN, 1);    // trig before assign data
  data1 = update165();          // read MSB Data 
  data2 = update165();          // read LSB Data
  // -----------------------

  Serial.print(data1 , BIN);
  Serial.print(" , ");
  Serial.println(data2 , BIN);
  delay(500);
}

unsigned char update165(){
  unsigned char value = 0; 
  for(int i=0; i<8; i++){
      value |= (digitalRead(DATA_IN)<<(7-i));
      digitalWrite(CLOCK_IN, 1);
      digitalWrite(CLOCK_IN, 0);
  }
  return value;
}


