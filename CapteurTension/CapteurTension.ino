#include <Arduino.h>

const float R1 = 190000.0;
const float R2 = 10000.0;
const float VREF = 3.3;

void setup() {
  Serial.begin(115200);
  analogReadResolution(16);   // pas de pinMode pour A9
}

void loop() {
  uint16_t raw = analogRead(A0);
  float vadc = raw * VREF / 65536;
  float vreelle = vadc * (R1 + R2) / R2;

  Serial.print("ADC : ");
  Serial.print(raw);
  Serial.print("Tension : ");
  Serial.print(vreelle);
  Serial.println(" V");

  delay(500);
}