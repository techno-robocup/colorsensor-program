#define _DEBUG
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
void lightup(uint8_t r, uint8_t g, uint8_t b);
template <class T>
void DP(T a);

template <class T>
void DPln(T a);

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
}

void loop() {
  DPln("RED");
  lightup(HIGH, LOW, LOW);
  delay(1000);
  DPln("GREEN");
  lightup(LOW, HIGH, LOW);
  delay(1000);
  DPln("BLUE");
  lightup(LOW, LOW, HIGH);
  delay(1000);
  DP("1: ");
  DPln(analogRead(light1));
  DP("2: ");
  DPln(analogRead(light2));
  DP("3: ");
  DPln(analogRead(light3));
  DP("4: ");
  DPln(analogRead(light4));
  DP("5: ");
  DPln(analogRead(light5));
  delay(500);
}
void lightup(uint8_t r, uint8_t g, uint8_t b){
  digitalWrite(red, r);
  digitalWrite(green, g);
  digitalWrite(blue, b);
}
template <class T>
void DP(T a){
#ifdef _DEBUG
  Serial.print(a);
#endif
}
template <class T>
void DPln(T a){
#ifdef _DEBUG
  Serial.println(a);
#endif
}