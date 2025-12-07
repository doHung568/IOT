//include library
#include <Servo.h>

//init Object
Servo myServo;

//set up
void setup() {
  //connect servo with pin 9 (PWM)
  myServo.attach(9);
}

void loop() {
  //turn the corner 0 degree
  myServo.write(0);
  delay(1000);
  //turn the corner 90 degree
  myServo.write(90);
  delay(1000);
  //turn the corner 180 degree
  myServo.write(180);
  delay(1000);
}
