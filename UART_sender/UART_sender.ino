// Connect GND pin of both ARDUINOs 
// For int passing
int num =260;
void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
}
void loop(){
  Serial.println(num);
  Serial1.write(num>>8);
  //delay(2);
  Serial1.write(num);
  delay(1000);
}
