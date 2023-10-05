/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(22, 3);
//   avoid using pins with LEDs attached
#define PWM 2
#define DIR 23
char x;
void setup() {
  Serial.begin(9600);
  pinMode(PWM, OUTPUT);
  pinMode(DIR,OUTPUT);
  Serial.println("Basic Encoder Test:");
}

long oldPosition  = -999;

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }
  if (Serial.available()){
     x = Serial.read();
    if (x == 'u' || x == '1') {
      digitalWrite(DIR, HIGH);
      analogWrite(PWM, 20);
    }
    if (x == 'd' || x == '2') {
      digitalWrite(DIR, LOW);
      analogWrite(PWM, 20);
    }
    if(x=='s'){
      analogWrite(PWM, 0);
    }
  }
 
}
