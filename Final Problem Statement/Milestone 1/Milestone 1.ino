#include<Wire.h>
 
const int MPU = 0x68;
int16_t AcX,AcY,AcZ;
 
double x;
double y;
double z;
 
void setup(){
Wire.begin();
Wire.beginTransmission(MPU);
Wire.write(0x6B);
Wire.write(0);
Wire.endTransmission(true);
Serial.begin(9600);
}
void loop(){
Wire.beginTransmission(MPU);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(MPU,6,true);
AcX=Wire.read()<<8|Wire.read();
AcY=Wire.read()<<8|Wire.read();
AcZ=Wire.read()<<8|Wire.read();
Wire.endTransmission(true); 
Serial.print("AccX= ");
Serial.print(AcX);
 
Serial.print("\tAccY= ");
Serial.print(AcY);
 
Serial.print("\tAccZ= ");
Serial.println(AcZ);
delay(50);
}