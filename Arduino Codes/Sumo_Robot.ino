  int ir_forward = A5 ;
  int ir_backward = A4 ;
  int enL1 = 9;
  int enL2 = 10;
  int enR1 = 5;
  int enR2 = 6;
  int motorR11 = 3;
  int motorR12 = 4;
  int motorR21 = 7;
  int motorR22 = 8;
  int motorL11 = 11;
  int motorL12 = 12;
  int motorL21 = 13;
  int motorL22 = 2;

  #define trigR A0
  #define echoR A1
  #define trigL A2
  #define echoL A3
  int distanceR = 0, tR =0;
  int distanceL = 0, tL =0;
//-----------------------------------------------------------------------
int forward_line(){
  int i;
  if(digitalRead(ir_forward)==LOW)
  { 
    i = 0;
    Serial.print("white");    
  }
  else
  {
    i = 1;
    Serial.print("black");
  }
  return i;
}
//--------------------------------------------------------------------------
int backward_line(){
   int i;
  if(digitalRead(ir_backward)==LOW)
  { 
    i = 0;
    Serial.print("white");
    delay(50);    
  }
  else
  {
    i = 1;
    delay(50);
    Serial.print("black");
  }
  return i;
}
//------------------------------------------------------------------------
  int Ultra_sensor(){
  digitalWrite(trigR, LOW);
  delayMicroseconds(5);
  digitalWrite(trigR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigR, LOW);
  tR = pulseIn(echoR, HIGH);

  digitalWrite(trigL, LOW);
  delayMicroseconds(5);
  digitalWrite(trigL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigL, LOW);
  tL = pulseIn(echoL, HIGH);
 
  distanceR = tR/57;
  distanceL = tL/57;

  if (distanceR < distanceL)
    {
      return distanceR;
    }
  else
    {
      return distanceL;
    } 
  }
//------------------------------------------------------------------------------- 
void stopMotors(){
  digitalWrite(motorR11,LOW);
  digitalWrite(motorR12,LOW);
  digitalWrite(motorR21,LOW);
  digitalWrite(motorR22,LOW);
  digitalWrite(motorL11,LOW);
  digitalWrite(motorL12,LOW);
  digitalWrite(motorL21,LOW);
  digitalWrite(motorL22,LOW);
 }
//--------------------------------------------------------------------------------
  void forward(){
     analogWrite(enR1, 250);
     analogWrite(enR2, 250);
     analogWrite(enL1, 250);
     analogWrite(enL2, 250);
   
  digitalWrite(motorR11,HIGH);
  digitalWrite(motorR12,LOW);
  
  digitalWrite(motorR21,LOW);
  digitalWrite(motorR22,HIGH);
  
  digitalWrite(motorL11,HIGH);
  digitalWrite(motorL12,LOW);
  
  digitalWrite(motorL21,HIGH);
  digitalWrite(motorL22,LOW);  
  }
//---------------------------------------------------------------------------
  void backward(){
  analogWrite(enR1, 250);
  analogWrite(enR2, 250);
  analogWrite(enL1, 250);
  analogWrite(enL2, 250);

  digitalWrite(motorR11,LOW);
  digitalWrite(motorR12,HIGH);
  
  digitalWrite(motorR21,HIGH);
  digitalWrite(motorR22,LOW);
  
  digitalWrite(motorL11,LOW);
  digitalWrite(motorL12,HIGH);
  
  digitalWrite(motorL21,LOW);
  digitalWrite(motorL22,HIGH);     
  }
//---------------------------------------------------------------------------
  void rotation(){
  analogWrite(enR1, 225);
  analogWrite(enR2, 225);
  analogWrite(enL1, 225);
  analogWrite(enL2, 225);
  digitalWrite(motorR11,HIGH);
  digitalWrite(motorR12,LOW);
  
  digitalWrite(motorR21,LOW);
  digitalWrite(motorR22,HIGH);
  
  digitalWrite(motorL11,LOW);
  digitalWrite(motorL12,1);
  
  digitalWrite(motorL21,LOW);
  digitalWrite(motorL22,1); 
  }
//---------------------------------------------------------------------------
  void setup(){
    Serial.begin(9600);
    // right motors & anables...
  pinMode(enR1,OUTPUT);
  pinMode(enR2,OUTPUT);
  pinMode(motorR11,OUTPUT);
  pinMode(motorR12,OUTPUT);
  pinMode(motorR21,OUTPUT);
  pinMode(motorR22,OUTPUT);
// left motors & anables...
  pinMode(enL1,OUTPUT);
  pinMode(enL2,OUTPUT);
  pinMode(motorL11,OUTPUT);
  pinMode(motorL12,OUTPUT);
  pinMode(motorL21,OUTPUT);
  pinMode(motorL22,OUTPUT);

  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);
  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);
  }
//----------------------------------------------------------------------------------
  void loop(){
    
  long d=0;
  d = Ultra_sensor();
  int a=0;
  a=forward_line();
  int b=0;
  b=backward_line();
  if (a==1 && b == 1 && d <40)  
  {
   forward();
  }
  else
  { 
     rotation();
  }
  if (b == 0)
  {
   forward();
  }
}
