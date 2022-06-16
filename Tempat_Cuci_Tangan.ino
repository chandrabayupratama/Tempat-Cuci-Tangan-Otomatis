#include <Servo.h>
const int triggerPin_1 = 8;
const int echoPin_1 = 9;
unsigned int duration_1;
unsigned int jarak1;
const int triggerPin_2 = 3;
const int echoPin_2 = 4;
unsigned int duration_2;
unsigned int jarak2;

Servo myservo1;
Servo myservo2;

void setup() {
  pinMode(triggerPin_1, OUTPUT);
  pinMode(echoPin_1, INPUT);
  pinMode(triggerPin_2, OUTPUT);
  pinMode(echoPin_2, INPUT);
  
  myservo1.attach(10);
  myservo2.attach(5);
  myservo1.write(0);
  myservo2.write(0);
    
  Serial.begin(9600);
}
void readSensor_1() {
  digitalWrite(triggerPin_1, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin_1, LOW);
  duration_1 = pulseIn(echoPin_1, HIGH);
  jarak1 = (duration_1 / 2) / 28.5;
  Serial.print("Sensor 1 = ");
  Serial.print(jarak1);
  Serial.println(" cm");
}
void readSensor_2() {
  digitalWrite(triggerPin_2, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin_2, LOW);
  duration_2 = pulseIn(echoPin_2, HIGH);
  jarak2 = (duration_2 / 2) / 28.5;
  Serial.print("Sensor 2 = ");
  Serial.print(jarak2);
  Serial.println(" cm");
}

void CuciTangan(){
 if(jarak1 <= 10 && jarak1 > 1){
    myservo1.write(180);
    delay(500);
  }
  else{
    myservo1.write(0);
  }
}

void SemprotSabun(){
 if(jarak2 <= 10 && jarak2 > 1){
   myservo2.write(180);
   delay(1000);
   myservo2.write(0);
   delay(1000);
  }
  else{
    myservo2.write(0);
    
  }
}

void loop() {
  readSensor_1();
  readSensor_2();
  CuciTangan();
  SemprotSabun();
}
