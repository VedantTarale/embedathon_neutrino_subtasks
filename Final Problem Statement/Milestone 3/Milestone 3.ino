#include <Wire.h>

const int MPU = 0x68;
int16_t AcX, AcY, AcZ;
float xAngError = 0, yAngError = 0, zAngError = 0;
int minVal = 265;
int maxVal = 402;
int c;
double x,y,z;

void setup()
{
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(115200);
  // delay(3000);
  // calculate_IMU_error();
  // delay(100);
}
void loop()
{
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);
  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  int xAng = map(AcX, minVal, maxVal, -90, 90);
  int yAng = map(AcY, minVal, maxVal, -90, 90);
  int zAng = map(AcZ, minVal, maxVal, -90, 90);

  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI) - 3.82;
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI) - 349.39;

  Serial.print("AngleX= ");
  Serial.print(x);

  Serial.print("\tAngleY= ");
  Serial.println(y);
}

// This part of code is inspired by: https://howtomechatronics.com/tutorials/arduino/arduino-and-mpu6050-accelerometer-and-gyroscope-tutorial/
void calculate_IMU_error()
{
  // We can call this funtion in the setup section to calculate the accelerometer and gyro data error. From here we will get the error values used in the above equations printed on the Serial Monitor.
  // Note that we should place the IMU flat in order to get the proper values, so that we then can the correct values
  // Read accelerometer values 100 times

  while (c < 100)
  {
    Wire.beginTransmission(MPU);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 6, true);
    AcX = Wire.read() << 8 | Wire.read();
    AcY = Wire.read() << 8 | Wire.read();
    AcZ = Wire.read() << 8 | Wire.read();
    int xAng = map(AcX, minVal, maxVal, -90, 90);
    int yAng = map(AcY, minVal, maxVal, -90, 90);
    int zAng = map(AcZ, minVal, maxVal, -90, 90);
    x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
    y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
    xAngError = xAngError + x;
    yAngError = yAngError + y;
    c++;
  }
  xAngError = xAngError / 100;
  yAngError = yAngError / 100;
  Serial.print("AccErrorX: ");
  Serial.println(x);
  Serial.print("AccErrorY: ");
  Serial.println(y);
}