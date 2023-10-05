int led = 13;  
void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
}
//Values are in hexadecimal

void loop() {
  if(Serial.find("YY"))
  {
    int l=Serial.read(),h=Serial.read();
    int ans=l>>8 |h;
    //Serial.print("Distance: ");
    //Serial.println(ans);
    if(ans>50){
      digitalWrite(led, HIGH);
      delay(500);
    digitalWrite(led, LOW);
    } 
  }
//  else{
//    Serial.println("NO Data");
//  }
  delay(500);
}
