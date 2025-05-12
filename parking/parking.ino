// ULTRASONIDOS
#define emisorOnda   27
#define receptorOnda 14

//LED
#define rojo 25
#define ambar 33
#define verde 32

//Constantes
#define on HIGH
#define off LOW

int cm, duracion;

void setup() {
  // ULTRASONIDOS
  pinMode(emisorOnda, OUTPUT);
  pinMode(receptorOnda, INPUT);
  digitalWrite(emisorOnda, off);

  // LED
  pinMode(rojo, OUTPUT);
  pinMode(ambar, OUTPUT);
  pinMode(verde, OUTPUT);

  //Serial para comprobacion
  Serial.begin(9600);

  digitalWrite(rojo, on);
  digitalWrite(verde, on);
  digitalWrite(ambar, on);
  
}

void loop() {
  //ULTRASONIDOS
  delayMicroseconds(2);
  digitalWrite(emisorOnda, on);
  delayMicroseconds(10);
  digitalWrite(emisorOnda, off);

  duracion = pulseIn(receptorOnda, on);

  cm = duracion / 59;

  Serial.print("durecion: ");
  Serial.println(cm);
  
  //Condiciones para encendido del LedRGB
  if (cm < 0 && cm > 325) {
    ledOff();  //En caso de ser un valor fuera del rango no se enciende
  }

  if (cm >= 0 && cm <= 5) {
    //Si esta muy cerca se activa con el color rojo y un parpadeo acelerado
    ledColorRojo();

    delay(250);

    ledOff();

    delay(200);

    ledColorRojo();
  }

  if (cm > 5 && cm <= 15) {
    //Si es una distancia media se activa con el color ambar y un parpadeo normal
    ledColorAmbar();

    delay(500);

    ledOff();

    delay(500);

    ledColorAmbar();

  }

  else ledColorVerde();  //Si hay una distancia mas que suficiente de activa con un color verde fijo
}

// Metodos para los colores del LedRGB
void ledColorAmbar() {
  digitalWrite(ambar, on);
}

void ledColorRojo() {
  digitalWrite(rojo, on);
}

void ledColorVerde() {
  digitalWrite(verde, on);
}

void ledOff()  //Apagado del led
{
  digitalWrite(rojo, off);
  digitalWrite(ambar, off);
  digitalWrite(verde, off);
}
