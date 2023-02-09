//Including Ticker Liblary
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
  if(count == 8) count = 0;
}

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(rst,OUTPUT);
  digitalWrite(rst,1);
  counter.attach(3,counter_func);  // Servers as a 1/3 Hz clock 
}

//Function to update the Shift Register
void updateLED(byte inp){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clk,MSBFIRST,inp);
  digitalWrite(latchPin,HIGH);
}

void loop(){
  switch (count){
    case 0: updateLED(0b00010000);  //N
            updateLED(0b00101011);
            updateLED(0b01001101);
            updateLED(0b10000000);
            break;
    case 1: updateLED(0b00010001);  //e
            updateLED(0b00100100);
            updateLED(0b01000010);
            break;
    case 2: updateLED(0b00010001);  //u
            updateLED(0b01101110);
            updateLED(0b10000001);
            break;
    case 3: updateLED(0b00010011);  //T
            updateLED(0b00100000);
            updateLED(0b01000000);
            updateLED(0b10000011);
            break;
    case 4: updateLED(0b00010111);  //r
            updateLED(0b00101000);
            updateLED(0b01000111);
            updateLED(0b10001011);
            break;
    case 5: updateLED(0b11110111);  //I
            updateLED(0b01101001);
            updateLED(0b11111110);
            break;
    case 6: updateLED(0b00010000);  //N
            updateLED(0b00101011);
            updateLED(0b01001101);
            updateLED(0b10000000);
            break;
    case 7: updateLED(0b01100111);  //O
            updateLED(0b10011011);
            updateLED(0b10011101);
            updateLED(0b01101110);
            break;
  }
}