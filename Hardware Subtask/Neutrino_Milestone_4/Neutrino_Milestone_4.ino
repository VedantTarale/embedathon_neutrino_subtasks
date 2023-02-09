//Including the Ticker Liblary
#include <Ticker.h>

#define dataPin D1
#define latchPin D2
#define clk D5
#define rst D6

//Creating TIcker Object
Ticker counter;

int count = 9;

void counter_func(){
  --count;
  if(count == -1) count = 9;
}

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(rst,OUTPUT);
  digitalWrite(rst,1);
  counter.attach(1,counter_func);   //Serves as a 1Hz clock
}

//Function to update the Shift Register
void updateLED(byte inp){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clk,MSBFIRST,inp);
  digitalWrite(latchPin,HIGH);
}

void loop(){
  switch (count){
    case 9: updateLED(0b10000000);  //9
            updateLED(0b11100111);
            updateLED(0b00100001);
            updateLED(0b11101101);
            break;

    case 8: updateLED(0b11110111);  //8
            updateLED(0b01101011);
            updateLED(0b10011101);
            updateLED(0b11111110);
            break;
    
    case 7: updateLED(0b11110111);  //7
            updateLED(0b01001011);
            updateLED(0b00101101);
            updateLED(0b00011110);
            break;
    
    case 6: updateLED(0b00010000);  //6
            updateLED(0b01111011);
            updateLED(0b01011101);
            updateLED(0b01111110);
            break;
    
    case 5: updateLED(0b11110111);  //5
            updateLED(0b00111011);
            updateLED(0b01001101);
            updateLED(0b01111110);
            break;
    
    case 4: updateLED(0b00010011);  //4
            updateLED(0b11111011);
            updateLED(0b10000000);
            break;
    
    case 3: updateLED(0b11110111);  //3
            updateLED(0b01101011);
            updateLED(0b11001101);
            updateLED(0b11101110);
            break;
    
    case 2: updateLED(0b11110111);  //2
            updateLED(0b11111110);
            updateLED(0b01001011);
            updateLED(0b00101101);
            break;
    
    case 1: updateLED(0b01000000);  //1
            updateLED(0b00101010);
            updateLED(0b11111110);
            break;
    
    case 0: updateLED(0b11110111);  //0
            updateLED(0b11111110);
            updateLED(0b00010000);
            updateLED(0b10000000);
            break;
  }
}