#define PWM 5
#define DIR 44
void setup()
{
 pinMode(PWM,OUTPUT);
 pinMode(DIR,OUTPUT);
}
void loop()
{
  digitalWrite(DIR,HIGH);
  analogWrite(PWM,130);
  delay(1000);
  analogWrite(PWM,0);
  delay(1000);
  
// int i=0;
// digitalWrite(DIR,HIGH);
// for(i=0;i<150; i++)
// {
// analogWrite(PWM,i);
// delay(2);
// }
// delay(2000);
// digitalWrite(DIR,LOW);
// for(int j=0;j<150;j++)
// {
// analogWrite(PWM,j);
// delay(2);
// }
// delay(2000);
}
