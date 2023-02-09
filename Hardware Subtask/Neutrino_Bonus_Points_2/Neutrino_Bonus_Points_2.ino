//Including Ticker Liblary
#include <Ticker.h>

#define dataPin D1
#define latchPin D2
#define clk D5
#define rst D6

//Creating Tecker Object
Ticker counter;
int count = 0;

byte LEDS[40] = {0b00001111,0b00001111,0b00001111,0b00001111,  //buffer bytes
                 0b00000000,0b00001011,0b00001101,0b00000000,  //N
                 0b00000001,0b00000100,0b00000010,0b00001111,  //e
                 0b00000001,0b00001110,0b00001110,0b00000001,  //U
                 0b00000011,0b00000000,0b00000000,0b00000011,  //T
                 0b00000111,0b00001000,0b00000111,0b00001011,  //r
                 0b00000110,0b00000000,0b00000000,0b00000110,  //I
                 0b00000000,0b00001011,0b00001101,0b00000000,  //N
                 0b00001001,0b00000110,0b00000110,0b00001001,  //O
                 0b00001111,0b00001111,0b00001111,0b00001111}; //buffer bytes.

void counter_func(){
  ++count;
  if(count == 36) count = 0;
}
void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(rst,OUTPUT);
  digitalWrite(rst,1);
  counter.attach(0.5,counter_func);   //Serves as 2Hz clock
}

//Function to update the Shift Register
void updateLED(byte inp){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clk,MSBFIRST,inp);
  digitalWrite(latchPin,HIGH);
}
void loop(){
    updateLED(LEDS[0+count]|0b00010000);
    updateLED(LEDS[1+count]|0b00100000);
    updateLED(LEDS[2+count]|0b01000000);
    updateLED(LEDS[3+count]|0b10000000);
}