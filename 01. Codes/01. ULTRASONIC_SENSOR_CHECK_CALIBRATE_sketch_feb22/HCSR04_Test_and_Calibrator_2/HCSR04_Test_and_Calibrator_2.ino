
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int trigpin=9;
const int echopin=10;
int distance,duration;
void setup() 
{
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);// gives time to go and return
  //Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin,LOW);
  delayMicroseconds(3);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(30);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  //distance=duration*(0.034/2);
  lcd.setCursor(0,0);
  //lcd.print(distance);
  lcd.print(duration);
  //lcd.print("cm");
  //Serial.print(distance);
  //Serial.print("cm");
}
