#include<Servo.h>
Servo Myservo1, Myservo2, Myservo3, Myservo4, Myservo5;
int pos;
void move(Servo myservo, int start_pos, int final_pos, bool flag) {
  if (flag)
    for (pos = start_pos; pos < final_pos; pos++) {
      myservo.write(pos);
      delay(10);
    }
  else
    for (pos = final_pos; pos > start_pos; pos--) {
      myservo.write(pos);
      delay(10);
    }
}
char c;
bool flag1 , flag2, flag3, flag4, flag5;
void setup()
{
  Serial.begin(9600);
  Myservo1.attach(3);
  Myservo2.attach(5);
  Myservo3.attach(6);
  Myservo4.attach(10);
  Myservo5.attach(11);
  Myservo1.write(0);
  Myservo2.write(70);
  Myservo3.write(20);
  Myservo4.write(0);
  Myservo5.write(0);
  flag1 = false;
  flag2 = false;
  flag3 = false;
  flag4 = false;
  flag5 = false;
}

void loop()
{
  if (Serial.available() > 0) {
    c = Serial.read();
    if (c == '1') {
      flag1 = !flag1;
      move(Myservo1, 0, 180, flag1);
      c = 'z';
    }
    if (c == '2') {
      flag2 = !flag2;
      move(Myservo2, 70, 140, flag2);
      c = 'z';
    }
    if (c == '3') {
      flag3 = !flag3;
      move(Myservo3, 20, 180, flag3);
      c = 'z';
    }
    if (c == '4') {
      flag4 = !flag4;
      move(Myservo4, 0, 180, flag4);
      c = 'z';
    }
    if (c == '5') {
      flag5 = !flag5;
      move(Myservo5, 0, 180, flag5);
      c = 'z';
    }
  }

}
