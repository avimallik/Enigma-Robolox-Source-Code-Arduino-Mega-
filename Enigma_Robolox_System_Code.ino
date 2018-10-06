/*******
 
 Auther : Arunav Mallik Avi (Arm Avi),
 Department of Computer Science & Engineering,
 National Uniersity, Bangladesh

*******/
#include <SoftwareSerial.h>

int smokeA0 = A1;
int flamepin = A2;

//threshold value for Smoke Detector
int sensorThres = 300;

//Ultrasonic Sensor Code
#define trigPin 6
#define echoPin 5

SoftwareSerial SIM900(7, 8); 
int sms_count;

void setup() {
  
  pinMode(smokeA0, INPUT);
  pinMode(flamepin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  SIM900.begin(19200);   
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
  int analogSensorFire = analogRead(flamepin);

  Serial.print("Pin A1: ");
  Serial.println(analogSensorFire);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);

  SIM900.println("AT + CMGS = \"+8801827933335\""); 
  delay(100);
  
  SIM900.println("smoke detected"); 
  delay(100);

  SIM900.println((char)26); 
  delay(100);
  SIM900.println();
  delay(3000); 
  
  }
 
  if(analogSensorFire <= 200){

  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  
  SIM900.println("AT + CMGS = \"+8801827933335\""); 
  delay(100);
  
  SIM900.println("fire detected"); 
  delay(100);

  SIM900.println((char)26); 
  delay(100);
  SIM900.println();
  delay(3000); 
  
  }

  ultrasonicFunc();
  
  delay(100);
  
}

//Ultrasonic Sensor Object Detection Function
void ultrasonicFunc(){
  //For Ultrasonic Sensor
  
long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  
  //delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance < 10) { 

  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  
  SIM900.println("AT + CMGS = \"+8801827933335\""); 
  delay(100);
  
  SIM900.println("intruder detected"); 
  delay(100);

  SIM900.println((char)26); 
  delay(100);
  SIM900.println();
  delay(3000); 
  
  }
}
