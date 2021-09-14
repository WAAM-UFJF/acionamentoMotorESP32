#include <Arduino.h>
const int led  = 16;          // Define a porta de saída do sinal PWM.
const int sentidoMotor1 = 2;  // Porta para definir o sentido de rotação 1.
const int sentidoMotor2 = 0;  // Porta para definir o sentido de rotação 2.

const int freq = 5000;        // Define a frequencia a ser utilizada
const int ledChannel = 0;
const int resolution = 8;     // Define a resolução que será utilizada no PWM.


void setup() {
  Serial.begin(115200);

  // Configura o LED PWM
  ledcSetup(ledChannel, freq, resolution);

  // Atribui o canal ao GPIO que será controlado
  ledcAttachPin(led, ledChannel);
}

void loop() {

   // Aumenta a velocidade de rotação do motor
  for(int dutyCycle = 0; dutyCycle <= (2^resolution - 1); dutyCycle++){   
    // Aumenta a velocidade de rotação do motor através do aumento do dutycycle do PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  // Diminui a valocidade de rotação do motor
  for(int dutyCycle = (2^resolution - 1); dutyCycle >= 0; dutyCycle--){
    // Diminui a velocidade de rotação do motor através do decremento do dutycycle do PWM
    ledcWrite(ledChannel, dutyCycle);   
    delay(15);
  }

}