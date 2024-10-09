#include <EEPROM.h>
#include <Wire.h>
#define _DEBUG
#ifdef _DEBUG
#define DP(x)   \
Serial.print(x);
#define DPln(x) \
Serial.println(x)
#endif // _DEBUG
/*
ESP
i2c pins
SDA 21
SCL 22

EV3
white->none
black->none
red->GND
green->vcc
yellow->SCL
blue->SDA
*/
constexpr uint8_t red = 32;
constexpr uint8_t green = 26;
constexpr uint8_t blue = 25;
constexpr uint8_t light1 = 15;
constexpr uint8_t light2 = 4;
constexpr uint8_t light3 = 34;
constexpr uint8_t light4 = 35;
constexpr uint8_t light5 = 12;
constexpr uint8_t light6 = 27;
constexpr uint8_t light7 = 14;
constexpr uint8_t waittime=600;
inline void lightup(uint8_t r, uint8_t g, uint8_t b);
inline void i2cSendEvent();
uint8_t colordata[7][3];
#define getdata(x)                  \
colordata[0][x]=analogRead(light1); \
colordata[1][x]=analogRead(light2); \
colordata[2][x]=analogRead(light3); \
colordata[3][x]=analogRead(light4); \
colordata[4][x]=analogRead(light5); \
colordata[5][x]=analogRead(light6); \
colordata[6][x]=analogRead(light7);

void setup() {
#ifdef _DEBUG
  Serial.begin(115200);
  Serial.println("serial start");
#endif
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(light1, INPUT);
  pinMode(light2, INPUT);
  pinMode(light3, INPUT);
  pinMode(light4, INPUT);
  pinMode(light5, INPUT);
  pinMode(light6, INPUT);
  pinMode(light7, INPUT);
	Wire.onRequest(i2cSendEvent);
}


void loop() {
  DPln("RED");
  lightup(HIGH, LOW, LOW);
  getdata(0);
  delay(waittime);
  DPln("GREEN");
  lightup(LOW, HIGH, LOW);
  getdata(1)
  delay(waittime);
  DPln("BLUE");
  lightup(LOW, LOW, HIGH);
  getdata(2);
  delay(waittime);
}
inline void lightup(uint8_t r, uint8_t g, uint8_t b){
  digitalWrite(red, r);
  digitalWrite(green, g);
  digitalWrite(blue, b);
}
inline void i2cSendEvent(){
	Wire.write(colordata, sizeof(colordata));
}
