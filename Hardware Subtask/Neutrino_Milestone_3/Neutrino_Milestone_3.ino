#define latchPin D6
#define clk D7
#define dataPin D5
#define rst D8

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(rst,OUTPUT);
  digitalWrite(rst,1);
}

//Function to update the Shift Register
void updateLED(byte inp){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clk,MSBFIRST,inp);
  digitalWrite(latchPin,HIGH);
}

void loop(){
  //Displays 'H' on the 4x4 matrix
  updateLED(0b00010000);  //Turns LEDs on column 1 ON
  updateLED(0b01101011);  //Turns LEDs on row2 and column3,column3 ON
  updateLED(0b01101101);  //Turns LEDs on row3 and column3,column3 ON
  updateLED(0b10000000);  //Turns LEDs on column 4 ON
}