#define boton 12
#define ledRojo 15

bool estadoLED = false;  // Variable para almacenar el estado del LED

void setup() {
  pinMode(boton, INPUT);
  pinMode(ledRojo, OUTPUT);
}

void loop() {
  static bool ultimoEstadoBoton = LOW;  // Guarda el estado anterior del botón
  int estadoBoton = digitalRead(boton);

  // Detecta el cambio de estado (de LOW a HIGH) para actuar solo en pulsaciones
  if (estadoBoton == HIGH && ultimoEstadoBoton == LOW) {
    estadoLED = !estadoLED;  // Cambia el estado del LED
    digitalWrite(ledRojo, estadoLED ? HIGH : LOW);
    delay(200);  // Pequeño retardo para evitar rebotes mecánicos
  }

  ultimoEstadoBoton = estadoBoton;  // Guarda el estado actual del botón
}