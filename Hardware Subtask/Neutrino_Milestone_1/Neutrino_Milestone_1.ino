#define dataPin D1
#define latchPin D2
#define clk D5
#define rst D6

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(rst,OUTPUT);
  digitalWrite(rst,1);
}

//Funtion to update the Shift Register
void updateLED(byte inp){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clk,MSBFIRST,inp);
  digitalWrite(latchPin,HIGH);
  delay(1000);
}

/*
  0b01010101
    bit-7 => col - 4
    bit-6 => col - 3
    bit-5 => col - 2
    bit-4 => col - 1
    bit-3 => row - 1
    bit-2 => row - 2
    bit-1 => row - 3
    bit-0 => row - 4
  The first four bits control the cols - Active High 
  The last four bits control the rows - Active Low
*/
void loop() {
  // ==========================================================continuity_checker==================================================
  updateLED(0b10000111);  //col4 row1 
  updateLED(0b01000111);  //col3 row1 
  updateLED(0b00100111);  //col2 row1   
  updateLED(0b00010111);  //col1 row1 
  
  updateLED(0b10001011);  //col4 row2
  updateLED(0b01001011);  //col3 row2
  updateLED(0b00101011);  //col2 row2
  updateLED(0b00011011);  //col1 row2
  
  updateLED(0b10001101);  //col4 row3
  updateLED(0b01001101);  //col3 row3
  updateLED(0b00101101);  //col2 row3
  updateLED(0b00011101);  //col1 row3
  
  updateLED(0b10001110);  //col4 row4
  updateLED(0b01001110);  //col3 row4
  updateLED(0b00101110);  //col2 row4
  updateLED(0b00011110);  //col1 row4
  //===============================================================================================================================
}
