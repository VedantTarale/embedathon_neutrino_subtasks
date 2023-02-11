#include <Wire.h>
#include <Ticker.h>

Ticker updater;
#define dataPin D3
#define latchPin D4
#define clk D5
#define rst D6

const int MPU = 0x68;
int16_t AcX, AcY, AcZ;
float xAngError = 0, yAngError = 0;
int minVal = 265;
int maxVal = 402;
double x, y;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(rst, OUTPUT);
  digitalWrite(rst, 1);

  Serial.begin(115200);
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void updateLED(byte inp) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clk, MSBFIRST, inp);
  digitalWrite(latchPin, HIGH);
}

void MPU_func() {
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
}

void loop() {
  MPU_func();
  Serial.print(x);
  Serial.print("\t");
  Serial.println(y);
  while (x > 45 && x < 70) {
    updateLED(0b00011011);
    updateLED(0b00100000);
    updateLED(0b01000000);
    updateLED(0b10001011);
  }
  while (x > 250 && x < 300) {
    updateLED(0b00011101);
    updateLED(0b00100000);
    updateLED(0b01000000);
    updateLED(0b10001101);
  }
  while (y < -45 && y > -70) {
    updateLED(0b00011001);
    updateLED(0b00100000);
    updateLED(0b01001001);
    updateLED(0b10001001);
  }
  while (y < -250 && y > -300) {
    updateLED(0b00011001);
    updateLED(0b00101001);
    updateLED(0b01000000);
    updateLED(0b10001001);
  }
  while (!(((x > 45 && x < 70)||(x > 250 && x < 300)||(y < -45 && y > -70)||(y < -250 && y > -300)))) {
    updateLED(0b00011001);
    updateLED(0b00100110);
    updateLED(0b01000110);
    updateLED(0b10001001);
  }
}
