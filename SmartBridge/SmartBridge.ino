// /Arduino Code//

#include <Servo.h>

#include <Servo.h>

Servo myservo;
int sensor_pin = 4;
int val;

void setup() {
  pinMode(sensor_pin, INPUT);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  
  val = digitalRead(sensor_pin);

  Serial.println(val);

  if (val == 0) {
    myservo.write(0);
  }
  if (val == 1) {
    myservo.write(90);  // rotate the servo to 90 degrees
  }

}
