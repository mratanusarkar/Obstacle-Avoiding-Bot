int pinML1=36;
int pinML2=35;
int pinMR1=12;
int pinMR2=11;


int LEDbackL=9;
int LEDbackR=7;
int LEDfrontL=3;
int LEDfrontR=2;
int LEDsideL=1;
int LEDsideR=13;

void setup() 
{
  // put your setup code here, to run once:

  // For Motors
  pinMode(pinML1,OUTPUT);
  pinMode(pinML2,OUTPUT);
  pinMode(pinMR1,OUTPUT);
  pinMode(pinMR2,OUTPUT);
//For the purpose of output 
  pinMode(LEDbackL,OUTPUT);
  pinMode(LEDbackR,OUTPUT);
  pinMode(LEDfrontL,OUTPUT);
  pinMode(LEDfrontR,OUTPUT);
  pinMode(LEDsideL,OUTPUT);
  pinMode(LEDsideR,OUTPUT);
  
}



void moveForward(int spd,int TotalTime,int BlinkTime)
{
  analogWrite(pinML1,spd);
  analogWrite(pinML2,HIGH);
  analogWrite(pinMR1,spd);
  analogWrite(pinMR2,HIGH);

  int count=0;
  while(true)
  {
    
    digitalWrite(LEDfrontL,HIGH);
    digitalWrite(LEDfrontR,HIGH);
    delay(BlinkTime);
      count=count+BlinkTime;
    digitalWrite(LEDfrontL,LOW);
    digitalWrite(LEDfrontR,LOW);
    delay(BlinkTime);
      count=count+BlinkTime;

    if(count>=TotalTime)
    break;
  }
  
}

void moveBackward(int spd,int TotalTime,int BlinkTime)
{
  analogWrite(pinML1,LOW);
  analogWrite(pinML2,spd);
  analogWrite(pinMR1,LOW);
  analogWrite(pinMR2,spd);

  int count=0;
  while(true)
  {
    
    digitalWrite(LEDbackL,HIGH);
    digitalWrite(LEDbackR,HIGH);
    delay(BlinkTime);
      count=count+BlinkTime;
    digitalWrite(LEDbackL,LOW);
    digitalWrite(LEDbackR,LOW);
    delay(BlinkTime);
      count=count+BlinkTime;

    if(count>=TotalTime)
    break;
  }
  
}

void turnLeft(int spd,int TotalTime,int BlinkTime)
{
  analogWrite(pinML1,LOW);
  analogWrite(pinML2,LOW);
  analogWrite(pinMR1,spd);
  analogWrite(pinMR2,LOW);

  int count=0;
  while(true)
  {
    
    digitalWrite(LEDfrontL,HIGH);
    delay(BlinkTime);
      count=count+BlinkTime;
    digitalWrite(LEDfrontL,LOW);
    delay(BlinkTime);
      count=count+BlinkTime;

    if(count>=TotalTime)
    break;
  }
  
}

void turnRight(int spd,int TotalTime,int BlinkTime)
{
  analogWrite(pinML1,spd);
  analogWrite(pinML2,LOW);
  analogWrite(pinMR1,LOW);
  analogWrite(pinMR2,LOW);

  int count=0;
  while(true)
  {
    
    digitalWrite(LEDfrontR,HIGH);
    delay(BlinkTime);
      count=count+BlinkTime;
    digitalWrite(LEDfrontR,LOW);
    delay(BlinkTime);
      count=count+BlinkTime;

    if(count>=TotalTime)
    break;
  }

}

void STOP()
{
  analogWrite(pinML1,LOW);
  analogWrite(pinML2,LOW);
  analogWrite(pinMR1,LOW);
  analogWrite(pinMR2,LOW);

  
  digitalWrite(LEDbackL,HIGH);
  digitalWrite(LEDbackR,HIGH);
  digitalWrite(LEDfrontR,LOW);
  digitalWrite(LEDfrontL,LOW);
  digitalWrite(LEDsideL,LOW);
  digitalWrite(LEDsideR,LOW);
 
}

void RESET()
{
//Reset LED pin
  analogWrite(pinML1,LOW);
  analogWrite(pinML2,LOW);
  analogWrite(pinMR1,LOW);
  analogWrite(pinMR2,LOW);
  digitalWrite(LEDbackL,LOW);
  digitalWrite(LEDbackR,LOW);
  digitalWrite(LEDfrontL,LOW);
  digitalWrite(LEDfrontR,LOW);
  digitalWrite(LEDsideL,LOW);
  digitalWrite(LEDsideR,LOW);
 
}


void loop() 
{
  // put your main code here, to run repeatedly:


/*
 * RESET() & STOP()    ----> parameterless.
 * all other functions ----> (speed,TotalTime,BlinkTime)
 */
 
  RESET();
  digitalWrite(LEDsideL,LOW);
  digitalWrite(LEDsideR,LOW);
  moveForward(255,3000,300);
  moveBackward(255,3000,300);
  turnLeft(255,3000,300);
  turnRight(255,3000,300);
  STOP();
  delay(5000);
}