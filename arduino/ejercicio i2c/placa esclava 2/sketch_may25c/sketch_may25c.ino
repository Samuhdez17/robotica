#include <Wire.h>

#define esp_esc_2 0x09 // Numero de la placa esclava en el bus

void setup() {
  Wire.begin(esp_esc_2);
  Wire.onRequest(requestEvent);

  randomSeed(analogRead(0)); // Inicializacion para generar el random
}

void requestEvent() {
  // Generamos un numero random y lo mandamos
  int numero = random(0, 256);
  Wire.write(numero);
}
