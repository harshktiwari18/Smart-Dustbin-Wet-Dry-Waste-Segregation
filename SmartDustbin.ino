#include <Servo.h>
Servo myServo;
const int trigPin = 3;
const int echoPin = 4;
const int rainSensor = 2;
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(rainSensor, INPUT);
myServo.attach(9);
myServo.write(90);
Serial.begin(9600);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
7
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;
Serial.print("Distance: ");
Serial.println(distance);
if(distance >= 2 && distance <= 10) {
delay(200);
int sensorValue = digitalRead(rainSensor);
Serial.print("Rain Sensor: ");
Serial.println(sensorValue);
if(sensorValue == HIGH) {
Serial.println("Dry Waste");
myServo.write(30);
delay(2000);
}
else {
Serial.println("Wet Waste");
myServo.write(150);
delay(2000);
}
myServo.write(90);
delay(1000);
}
else {
myServo.write(90);
}
delay(300);
}
