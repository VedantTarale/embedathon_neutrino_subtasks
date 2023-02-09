//Including the Ticker Liblary
#include <Ticker.h>

#define dataPin D1
#define latchPin D2
#define clk D5
#define rst D6

//Creating Ticker Object
Ticker counter;

int count = 0;

void counter_func(){
  ++count;
  if(count == 5) count = 0;
}

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(rst,OUTPUT);
  digitalWrite(rst,1);
  counter.attach(3,counter_func);   //Serves as a 1/3 Hz clock
}

//Function to update the Shift Register
void updateLED(byte inp){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clk,MSBFIRST,inp);
  digitalWrite(latchPin,HIGH);
}

void loop(){
  switch (count){
    case 0: updateLED(0b11110111);  //I
            updateLED(0b01101001);
            updateLED(0b11111110);
            break;
    case 1: updateLED(0b00010000);  //N
            updateLED(0b00101011);
            updateLED(0b01001101);
            updateLED(0b10000000);
            break;
    case 2: updateLED(0b00010000);  //D
            updateLED(0b00100110);
            updateLED(0b01000110);
            updateLED(0b10001001);
            break;
    case 3: updateLED(0b11110111);  //I
            updateLED(0b01101001);
            updateLED(0b11111110);
            break;
    case 4: updateLED(0b00010000);  //A
            updateLED(0b11110111);
            updateLED(0b11111101);
            updateLED(0b10000000);
            break;
  }
}