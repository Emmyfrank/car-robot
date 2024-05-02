#include <Ultrasonic.h>

const int motor1Pin1 = 2;  
const int motor1Pin2 = 3;   
const int motor2Pin1 = 4;   
const int motor2Pin2 = 5;   
const int enablePin1 = 6;  
const int enablePin2 = 9;   

const int trigPin1 = 7;      
const int echoPin1 = 8;      
const int trigPin2 = 10;     
const int echoPin2 = 11;    

const int maxDistance1 = 70; // Maximum distance for sensor 1
const int maxDistance2 = 70; // Maximum distance for sensor 2

Ultrasonic ultrasonic1(trigPin1, echoPin1);
Ultrasonic ultrasonic2(trigPin2, echoPin2);

void setup() {
  // Initialize motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);

  // Initialize ultrasonic sensor pins
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  // Measure the distance to the obstacle for sensor 1
  int distance1 = ultrasonic1.distanceRead();
  
  // Measure the distance to the obstacle for sensor 2
  int distance2 = ultrasonic2.distanceRead();

  // If obstacle is detected by sensor 1 within the specified range
  if (distance1 < maxDistance1 && distance1 > 0) {
    // Move backward for sensor 1
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
  } 
  // If obstacle is detected by sensor 2 within the specified range
  else if (distance2 < maxDistance2 && distance2 > 0) {
    // Move forward for sensor 2
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
  }
  // If no obstacle is detected
  else {
    // Move forward
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);

    // Set motor speeds (PWM)
    analogWrite(enablePin1, 150);  // Adjust the speed by changing the PWM value (0-255)
    analogWrite(enablePin2, 150);  // Adjust the speed by changing the PWM value (0-255)
  }
}
