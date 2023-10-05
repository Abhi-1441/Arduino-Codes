#include <Wire.h>
void setup() {
  Wire.begin(); 
}
int x=250;
void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("x is ");        // sends five bytes
  Wire.write(x>>8);              // sends one byte
  Wire.write(x);
  Wire.endTransmission();    // stop transmitting

  x++;
  delay(500);
}
