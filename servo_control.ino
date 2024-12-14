#include <Servo.h>

Servo servo1, servo2, servo3, servo4, servo5;

const int servoPin1 = 2;
const int servoPin2 = 3;
const int servoPin3 = 4;
const int servoPin4 = 5;	
const int servoPin5 = 6;

void setup() {
  Serial.begin(9600);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');

    int comma1 = data.indexOf(',');
    int comma2 = data.indexOf(',', comma1 + 1);
    int comma3 = data.indexOf(',', comma2 + 1);
    int comma4 = data.indexOf(',', comma3 + 1);

    int value1 = data.substring(0, comma1).toInt();
    int value2 = data.substring(comma1 + 1, comma2).toInt();
    int value3 = data.substring(comma2 + 1, comma3).toInt();
    int value4 = data.substring(comma3 + 1, comma4).toInt();
    int value5 = data.substring(comma4 + 1).toInt();

    servo1.write(value1);
    servo2.write(value2);
    servo3.write(value3);
    servo4.write(value4);
    servo5.write(value5);
  }
}
