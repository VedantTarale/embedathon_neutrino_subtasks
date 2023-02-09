#define dataPin D1
#define latchPin D2
#define clk D5
#define rst D6
void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(rst,OUTPUT);
  digitalWrite(rst,0);  //Resetting the Register
  delay(100);
  digitalWrite(rst,1);
}

//Function to update the Shift Register
void updateLED(byte inp){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clk,MSBFIRST,inp);
  digitalWrite(latchPin,HIGH);
  delay(1000);
}

void loop() {
  //============================================================Rowwise============================================================
  updateLED(0b11111110); 
  updateLED(0b11111101);
  updateLED(0b11111011);
  updateLED(0b11110111);
  //===============================================================================================================================
}
