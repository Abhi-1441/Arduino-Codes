// Connect GND pin of both ARDUINOs 
// For int passing
int num;
void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
}
void loop(){
  if(Serial.available()>0){
     num=Serial1.read();
     delay(2);
     num= num<<8 | Serial1.read();
     Serial.println(num);
     delay(1000);
  }
}
