const uint8_t pin = A0;
const float vRef = 3.3;
const float R1 = 10000.0;
const float R2 = 18000.0;

void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);
  analogReadResolution(16);
}

void loop() {
  uint16_t valeur_analogique = analogRead(pin);
  float Vs = valeur_analogique * vRef / 65536;
  float Ve = Vs / (R2 / (R1 + R2)); 
  float A = (Ve - 2.5) / 0.0625;
  Serial.print("Tension capteur : ");
  Serial.print(Ve);
  Serial.println(" V");
  Serial.print("Courant : ");
  Serial.print(A);
  Serial.println(" A");
  Serial.println();
  delay(200);
}
