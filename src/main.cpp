#include <Arduino.h>
const int led  = 16;          // Define a porta de saída do sinal PWM.
const int sentidoMotor1 = 2;  // Porta para definir o sentido de rotação 1.
const int sentidoMotor2 = 0;  // Porta para definir o sentido de rotação 2.

const int freq = 5000;        // Define a frequencia a ser utilizada
const int ledChannel = 0;
int resolution = 8;           // Define a resolução que será utilizada no PWM.


void setup() {
  Serial.begin(115200);
  pinMode(sentidoMotor1, OUTPUT);
  pinMode(sentidoMotor2, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(sentidoMotor1, LOW);
  digitalWrite(sentidoMotor2, HIGH);

  // Atribui o canal ao GPIO que será controlado
  ledcAttachPin(led, ledChannel);

  // Configura o LED PWM
  ledcSetup(ledChannel, freq, resolution);

  

  // Define como output os pinos que definem o sentido de rotação do motor
  
}

void loop() {

   // Aumenta a velocidade de rotação do motor
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // Aumenta a velocidade de rotação do motor através do aumento do dutycycle do PWM
    ledcWrite(ledChannel, dutyCycle);
    Serial.print("DutyCycle: ");
    Serial.println(dutyCycle);
    delay(100);
  }

  // Diminui a valocidade de rotação do motor
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // Diminui a velocidade de rotação do motor através do decremento do dutycycle do PWM
    ledcWrite(ledChannel, dutyCycle);
    Serial.print("DutyCycle: ");
    Serial.println(dutyCycle);
    delay(100);
  }

}