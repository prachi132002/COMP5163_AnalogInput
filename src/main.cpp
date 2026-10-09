/*
 * Statement of Authorship:
 * I, Joshi Prachi , student number 0316555, certify that this
 * material is my original work. No other person's work has been
 * used without due acknowledgement
 */
#include <Arduino.h>

void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);
}

void loop() {
  int iVal;
  float fTemp;
  String sJudgement;

  // read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);
  if (iVal > 1023) iVal = 1023;   // ESP8266 can return 1024

  // scale 0-1023 into 0-50 deg. C
  fTemp = iVal * 50.0 / 1023.0;

  // decide the judgement
  if (fTemp < 10)       sJudgement = "Cold!";
  else if (fTemp < 15)  sJudgement = "Cool";
  else if (fTemp < 25)  sJudgement = "Perfect";
  else if (fTemp < 30)  sJudgement = "Warm";
  else if (fTemp < 35)  sJudgement = "Hot";
  else                  sJudgement = "Too Hot!";

  // print to the USB port
  Serial.println("Digitized output of " + String(iVal) +
                 " is equivalent to a temperature input of " + String(fTemp, 2) +
                 " deg. C, which is " + sJudgement);

  // wait 2 seconds
  delay(2000);
}
