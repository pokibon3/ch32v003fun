#include <Arduino.h>
uint32_t count;

void setup() {
  pinMode(D6, OUTPUT);
}

void loop() {
  digitalWrite(D6, LOW);
  delay(250);
  digitalWrite(D6, HIGH);
  delay(250);

  count++;
}