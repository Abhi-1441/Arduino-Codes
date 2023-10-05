int IRSensor = 9; // connect ir sensor to arduino pin 2
//int LED = 30; // conect Led to arduino pin 13
void setup() 
{
  Serial.begin(9600);
  pinMode (IRSensor, INPUT); // sensor pin INPUT
//  pinMode (LED, OUTPUT); // Led pin OUTPUT
}
void loop()
{
  int statusSensor = digitalRead (IRSensor);
  if (statusSensor == 1){
//    digitalWrite(LED, LOW); // LED LOW
    Serial.println("Object not Detected");
    delay(500);
  }
  else
  {
//    digitalWrite(LED, HIGH); // LED High
    Serial.println("Object Detected");
    delay(500);
  }
  
}
