
// Searching Case...

//initial motor variables... 

  int enL1 = 9;
  int enL2 = 10;
  int enR1 = 5;
  int enR2 = 6;
  int motorR11
  int motorR12
  int motorR21
  int motorR22
  int motorL11
  int motorL12
  int motorL21
  int motorL22

//initial Ultrasonic sensors variables... 
  #define trig1
  #define echo1
  #define trig2
  #define echo2
  int distance1 = 0, t1 =0;
  int distance2 = 0, t2 =0;

  int obstacle_LED1 
  int obstacle_pin1 ; //  output pin of forward IR sensor 
  int obstacle1 = HIGH;
  int obstacle_LED2 
  int obstacle_pin2 ; //  output pin of backword IR sensor 
  int obstacle2 = HIGH;

void setup() {

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
// Ultrasonic sensors...
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
}


// Right Ultrasonic sensor...
int rightUltra(){ 
digitalWrite(trig1, LOW);
  delayMicroseconds(5);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  t1 = pulseIn(echo1, HIGH);
  distance1 = t1/57;
  Serial.println(distance1);
  delay(5);  
  return distance1;  
}

// Left Ultrasonic sensor...
int leftUltra(){
digitalWrite(trig2, LOW);
  delayMicroseconds(5);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  t2 = pulseIn(echo2, HIGH);
  distance2 = t2/57;
  Serial.println(distance2);
  delay(5); 
  return distance2;
}

int forword_ir_sensor(){
 obstacle1 = digitalRead(obstacle_pin1);
    if (obstacle1 == LOW)
    {
        Serial.println(" white ");
        digitalWrite(obstacle_LED1 , HIGH);
    }
    else
    {
        Serial.println(" black ");
        digitalWrite(obstacle_LED1 , LOW);
        
    }
    delay(5);   
}

int backword_ir_sensor(){
 obstacle2 = digitalRead(obstacle_pin2);
    if (obstacle2 == LOW)
    {
        Serial.println(" white ");
        digitalWrite(obstacle_LED2 , HIGH);
    }
    else
    {
        Serial.println(" black ");
        digitalWrite(obstacle_LED2 , LOW);
        
    }
    delay(5);   
}



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

// searching to found an object...
void rotation(){
  digitalWrite(motorR11,HIGH);
  digitalWrite(motorR12,LOW);
  analogWrite(enR1, 250);
  digitalWrite(motorR21,HIGH);
  digitalWrite(motorR22,LOW);
  analogWrite(enR2, 250);
  digitalWrite(motorL11,LOW);
  digitalWrite(motorL12,HIGH);
  analogWrite(enL1, 250);
  digitalWrite(motorL21,LOW);
  digitalWrite(motorL22,HIGH);
  analogWrite(enL1, 250);
  }
  
void backword(){
  digitalWrite(motorR11,LOW);
  digitalWrite(motorR12,HIGH);
  analogWrite(enR1, 250);
  digitalWrite(motorR21,LOW);
  digitalWrite(motorR22,HIGH);
  analogWrite(enR2, 250);
  digitalWrite(motorL11,LOW);
  digitalWrite(motorL12,HIGH);
  analogWrite(enL1, 250);
  digitalWrite(motorL21,LOW);
  digitalWrite(motorL22,HIGH);
  analogWrite(enL1, 250);
} 

void forword(){
  digitalWrite(motorR11,HIGH);
  digitalWrite(motorR12,LOW);
  analogWrite(enR1, 250);
  digitalWrite(motorR21,HIGH);
  digitalWrite(motorR22,LOW);
  analogWrite(enR2, 250);
  digitalWrite(motorL11,HIGH);
  digitalWrite(motorL12,LOW);
  analogWrite(enL1, 250);
  digitalWrite(motorL21,HIGH);
  digitalWrite(motorL22,LOW);
  analogWrite(enL1, 250);
}

void forword_rotation(){
  digitalWrite(motorR11,LOW);
  digitalWrite(motorR12,LOW);
  digitalWrite(motorR21,HIGH);
  digitalWrite(motorR22,LOW);
  analogWrite(enR2, 250);
  digitalWrite(motorL11,HIGH);
  digitalWrite(motorL12,LOW);
  analogWrite(enL1, 250);
  digitalWrite(motorL21,HIGH);
  digitalWrite(motorL22,LOW);
  analogWrite(enL1, 250);
}

void backword_rotation(){
  digitalWrite(motorR11,LOW);
  digitalWrite(motorR12,HIGH);
  analogWrite(enR1, 250);
  digitalWrite(motorR21,LOW);
  digitalWrite(motorR22,HIGH);
  analogWrite(enR2, 250);
  digitalWrite(motorL11,LOW);
  digitalWrite(motorL12,LOW);
  digitalWrite(motorL21,LOW);
  digitalWrite(motorL22,HIGH);
  analogWrite(enL1, 250); 
}


 
void loop() {


}
