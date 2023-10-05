#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int led1 = 4;                // the pin that the LED is atteched to
int led2 =5;
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

int redLed = 12;
int buzzer = 10;
int smokeA0 = A3;
// threshold value
int sensorThres = 80;

byte warning[8] ={
  0b01110,
  0b10001,
  0b10101,
  0b10101,
  0b10001,
  0b10101,
  0b10001,
  0b01110
};
byte blank[8] ={
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
byte pattern[8] ={
  0b00100,
  0b01010,
  0b10101,
  0b01110,
  0b10101,
  0b01010,
  0b00100,
  0b00000
};

void setup()
{
  Serial.begin(9600);        // initialize serial
  pinMode(led1, OUTPUT);      // initalize LED as an output
  pinMode(led2, OUTPUT); 
  
  pinMode(sensor, INPUT);    // initialize sensor as an input
  
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  
  //analogWrite(6, Contrast);
  lcd.begin(16, 2);
  // create a new character
  lcd.createChar(0, blank);
   // create a new character
  lcd.createChar(1, warning);
  // create a new character
  lcd.createChar(2, pattern);
  lcd.backlight();
  lcd.clear();
}
void loop()
{
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led1, HIGH);   // turn LED ON
    digitalWrite(led2, HIGH);
    //delay(1000);                 
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led1, LOW); 
      digitalWrite(led2, LOW);
      delay(500);              
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }

  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1000);
  }
  else
  {
    digitalWrite(redLed, LOW);
    noTone(buzzer);
    delay(500);
  }
  delay(100);
  
  if(analogSensor>sensorThres){
    lcd.setCursor(0,0);
    lcd.print("                ");
//    for(int i=0;i<16;i++){
//        lcd.setCursor(i, 0);
//        lcd.write((byte)0);
//      }
    delay(500);  
    lcd.setCursor(1, 0);
    lcd.write((byte)1);
    lcd.print(" FIRE ALERT ");
    lcd.write((byte)1);
    lcd.setCursor(2, 1);
    lcd.print("DO NOT ENTER"); 
    delay(500);    
  }
  else{
   if(val==HIGH){
      lcd.setCursor(0, 0);
      // Print a message to the lcd.
      lcd.print("  Please knock  ");
      lcd.setCursor(0, 1);
      lcd.print("  before enter  "); 
   }
   else{
      lcd.setCursor(1,0);
      lcd.write((byte)0);
      lcd.setCursor(2, 0);
      lcd.write((byte)2);
      lcd.setCursor(14, 0);
      lcd.write((byte)2);
      delay(500);
      lcd.setCursor(2, 0);
      lcd.write((byte)0);
      lcd.setCursor(14, 0);
      lcd.write((byte)0);
      lcd.setCursor(3, 0);
      lcd.print("  IOT LAB  ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
   }
}                                                                                                                                                                                                                                                                                                                                                                                       
}
