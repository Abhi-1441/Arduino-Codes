#define LSwitch 42
#define a 11
void setup() {
  Serial.begin(115200);
  pinMode(LSwitch,INPUT);
  pinMode(a,INPUT);
}

void loop() {
  int x=digitalRead(LSwitch);
  Serial.println(x);
//  Serial.print(" ");
//  Serial.println(digitalRead(a));
}
