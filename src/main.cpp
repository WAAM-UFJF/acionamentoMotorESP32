#include <Arduino.h>
int led  = 2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  Serial.println("Led Ligado");
  delay(1000);
  digitalWrite(led, LOW);
  Serial.println("Led desligado.");
  delay(1000);

}