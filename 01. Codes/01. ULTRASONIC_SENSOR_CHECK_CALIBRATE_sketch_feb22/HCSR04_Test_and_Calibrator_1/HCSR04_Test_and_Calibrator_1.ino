const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
 
void setup()
{
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); // Starting Serial Terminal
}
 
void loop()
{
  float duration, inches, cm;

  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
 

  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  Serial.print("Total Time : ");
  Serial.print(duration);
  Serial.print(" micro sec  ||  ");

  Serial.print("Bot to Obstracle Distance : ");
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();
 
  delay(100);
}
 
/*
 * 10^-6 microsec-sec
 * 340m/s
 * 
 */
 
float microsecondsToCentimeters(float microseconds)
{
  return microseconds / 29 / 2;
}
