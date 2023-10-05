
int potPin = A0; // Potentiometer output connected to analog pin 3
int potVal = 0; // Variable to store the input from the potentiometer



void setup()
{Serial.begin(9600);
}

// Main program
void loop()
{
  potVal = analogRead(potPin);   // read the potentiometer value at the input pin
  Serial.println(String("POT : ") + potVal);
}
