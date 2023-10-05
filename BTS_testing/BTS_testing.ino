//#define R_EN 7
//#define L_EN 6
#define RPWM 9
#define LPWM 10

char x='z';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
//  pinMode(R_EN,OUTPUT);
//  pinMode(L_EN,OUTPUT);
  pinMode(RPWM,OUTPUT);
  pinMode(LPWM,OUTPUT);
//  digitalWrite(R_EN,HIGH);
//  digitalWrite(L_EN,HIGH);
}

void loop() {
  if(Serial.available()){
    x=Serial.read();
    if(x=='d')
    {   analogWrite(LPWM,0);
        analogWrite(RPWM,140);
    }
    if(x=='u')
    {   analogWrite(LPWM,140);
        analogWrite(RPWM,0);
    }
    if(x=='s')
    {   analogWrite(LPWM,0);
        analogWrite(RPWM,0);
//        delay(6000);
    }
    x='z';
  }
}
