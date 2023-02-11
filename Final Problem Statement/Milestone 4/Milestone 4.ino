#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>

const int MPU = 0x68;
const int button_pin = D0;
int16_t AcX, AcY, AcZ;
double x,y;
int minVal = 265;
int maxVal = 402;

ESP8266WebServer server;
char* ssid = "Home WIFI";
char* password = "infinity@1";

void MPU_func(){
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

  String str = String(x);
  str += ",";
  str += String(y);
  str += ",";
  str += String(digitalRead(button_pin));
  str += "\n";
  Serial.print(str);
  server.send(200,"text/plain",str);
}

void setup()
{
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  pinMode(button_pin,INPUT_PULLUP);

  WiFi.begin(ssid,password);
  Serial.begin(115200);
  
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/",MPU_func);
  server.begin();
}
void loop(){
  server.handleClient();
}