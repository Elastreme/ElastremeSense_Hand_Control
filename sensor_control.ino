const int sensorPin1 = A0;
const int sensorPin2 = A1;
const int sensorPin3 = A2;
const int sensorPin4 = A3;
const int sensorPin5 = A4;

int sensorMin1 = 1023, sensorMax1 = 0;
int sensorMin2 = 1023, sensorMax2 = 0;
int sensorMin3 = 1023, sensorMax3 = 0;
int sensorMin4 = 1023, sensorMax4 = 0;
int sensorMin5 = 1023, sensorMax5 = 0;

bool calibrated = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Calibrating sensors...");
}

void loop() {
  if (!calibrated) {
    unsigned long startTime = millis();
    while (millis() - startTime < 5000) { // 定标5秒钟
      int sensorValue1 = analogRead(sensorPin1);
      int sensorValue2 = analogRead(sensorPin2);
      int sensorValue3 = analogRead(sensorPin3);
      int sensorValue4 = analogRead(sensorPin4);
      int sensorValue5 = analogRead(sensorPin5);

      if (sensorValue1 < sensorMin1) sensorMin1 = sensorValue1;
      if (sensorValue1 > sensorMax1) sensorMax1 = sensorValue1;

      if (sensorValue2 < sensorMin2) sensorMin2 = sensorValue2;
      if (sensorValue2 > sensorMax2) sensorMax2 = sensorValue2;

      if (sensorValue3 < sensorMin3) sensorMin3 = sensorValue3;
      if (sensorValue3 > sensorMax3) sensorMax3 = sensorValue3;

      if (sensorValue4 < sensorMin4) sensorMin4 = sensorValue4;
      if (sensorValue4 > sensorMax4) sensorMax4 = sensorValue4;

      if (sensorValue5 < sensorMin5) sensorMin5 = sensorValue5;
      if (sensorValue5 > sensorMax5) sensorMax5 = sensorValue5;
    }
    calibrated = true;
    Serial.println("Calibration complete.");
  } else {
    int sensorValue1 = analogRead(sensorPin1);
    int sensorValue2 = analogRead(sensorPin2);
    int sensorValue3 = analogRead(sensorPin3);
    int sensorValue4 = analogRead(sensorPin4);
    int sensorValue5 = analogRead(sensorPin5);

    int mappedValue1 = map(sensorValue1, sensorMin1, sensorMax1, 0, 180);  //大拇指
    int mappedValue2 = map(sensorValue2, sensorMin2, sensorMax2, 180, 0);
    int mappedValue3 = map(sensorValue3, sensorMin3, sensorMax3, 180, 0);
    int mappedValue4 = map(sensorValue4, sensorMin4, sensorMax4, 180, 0);
    int mappedValue5 = map(sensorValue5, sensorMin5, sensorMax5, 180, 0);

    mappedValue1 = constrain(mappedValue1, 0, 180);   //大拇指
    mappedValue2 = constrain(mappedValue2, 0, 180);
    mappedValue3 = constrain(mappedValue3, 0, 180);
    mappedValue4 = constrain(mappedValue4, 0, 180);
    mappedValue5 = constrain(mappedValue5, 0, 180);

    Serial.print(mappedValue1); Serial.print(",");
    Serial.print(mappedValue2); Serial.print(",");
    Serial.print(mappedValue3); Serial.print(",");
    Serial.print(mappedValue4); Serial.print(",");
    Serial.println(mappedValue5);

    delay(100);
  }
}
