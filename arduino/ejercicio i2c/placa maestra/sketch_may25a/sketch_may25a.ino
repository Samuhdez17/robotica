#include <Wire.h>

#define esp_esc_1 0x08  // Supuesto número en bus de conexion (se comprueba previamente)
#define esp_esc_2 0x09  // Supuesto número en bus de conexion (se comprueba previamente)

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  int numPlaca1 = pedirNumeroI2C(1);
  int numPlaca2 = pedirNumeroI2C(2);

  // Calculamos con los numeros recividos
  String multiplicacion = "Multiplicado: " + String(numPlaca1) + " * " + String(numPlaca2);
  String resultado = "Resultado: " + String(numPlaca1 * numPlaca2);

  Serial.println(multiplicacion);
  Serial.println(resultado);

  delay(2000);
}

int pedirNumeroI2C(int numPlaca) {
  int numero = 0;

  switch (numPlaca) {
    case 1: {
      Wire.requestFrom(esp_esc_1, 1);  // pedimos 1 byte a la primera placa esclava
      if (Wire.available()) {
        numero = Wire.read();
      }

      break;
    }

    case 2: {
      Wire.requestFrom(esp_esc_2, 1);  // pedimos 1 byte a la segunda placa esclava
      if (Wire.available()) {
        numero = Wire.read();
      }

      break;
    }

    default: numero = 0;
  }
  
  return numero;
}
