#define CLOCK_OUT 8
#define DATA_OUT  9
#define SHIFT_OUT 10

unsigned char data1 = 0, data2 = 0B00110011;
void setup() {
  DDRB = 7;
}

void loop() {

  // write Data to 74HC595 :
  // -----------------------
  digitalWrite(SHIFT_OUT, 0);
  update595(data1);             // write your (data / variable) MSB here  
  update595(data2);             // write your (data / variable) LSB here  
  digitalWrite(SHIFT_OUT, 1);   // trig after assign data
  // -----------------------

  data1 += 1;
  delay(200);
}

void update595(unsigned data){
  for(int i=0; i<8; i++){
      digitalWrite(DATA_OUT,bitRead(data , 7-i));
      digitalWrite(CLOCK_OUT, 1);
      digitalWrite(CLOCK_OUT, 0);
  }
}


