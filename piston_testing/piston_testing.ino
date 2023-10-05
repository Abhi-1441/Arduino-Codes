#define piston1 27
char x = 'z';
void setup() {
  Serial.begin(9600);
  pinMode(piston1, OUTPUT);
  digitalWrite(piston1, LOW);
}

void loop() {
  if (Serial.available()) {
    x = Serial.read();
    if (x == '1') {
      digitalWrite(piston1, HIGH);
      Serial.println("Actuated");
    }
    if (x == '2') {
      digitalWrite(piston1, LOW);
      Serial.println("Deactuated");
    }

  }
}
