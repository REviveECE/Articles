unsigned char update165(){
  unsigned char value = 0; 
  for(int i=0; i<8; i++){
      value |= (digitalRead(DATA_IN)<<(7-i));
      digitalWrite(CLOCK_IN, 1);
      digitalWrite(CLOCK_IN, 0);
  }
  return value;
}

void update595(unsigned data){
  for(int i=0; i<8; i++){
      digitalWrite(DATA_OUT,bitRead(data , 7-i));
      digitalWrite(CLOCK_OUT, 1);
      digitalWrite(CLOCK_OUT, 0);
  }
}
