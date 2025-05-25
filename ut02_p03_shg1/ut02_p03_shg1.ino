// ULTRASONIDOS
const int emisorOnda   = 10;
const int receptorOnda = 9;
int cm, duracion;

//LED
const int rojo  = 3; 
const int azul  = 5; 
const int verde = 6;

//Constantes
const int on  = HIGH;
const int off = LOW;

void setup()
{
  // ULTRASONIDOS
  pinMode(emisorOnda,   OUTPUT);
  pinMode(receptorOnda, INPUT);
  digitalWrite(emisorOnda, off);
  
  // LED
  pinMode(rojo,  OUTPUT);
  pinMode(azul,  OUTPUT);
  pinMode(verde, OUTPUT);
  
  //Serial para comprobacion
  Serial.begin(9600);
}

void loop()
{
  //ULTRASONIDOS 
  delayMicroseconds(2);
  digitalWrite(emisorOnda, on);
  delayMicroseconds(10);
  digitalWrite(emisorOnda, off);
  
  duracion = pulseIn(receptorOnda, on);
  
  cm = duracion / 58;
    
  //Condiciones para encendido del LedRGB
  if (cm < 0 && cm > 400) {
    ledOff(); //En caso de ser un valor fuera del rango no se enciende
    
  }else if (cm >= 0 && cm <= 100){
    //Si esta muy cerca se activa con el color rojo y un parpadeo acelerado
    ledColorRojo();
    
    delay(250);
    
    ledOff();
    
    delay(200);
    
    ledColorRojo();
    
  } else if (cm > 100 && cm <= 250){
    //Si es una distancia media se activa con el color ambar y un parpadeo normal 
    ledColorAmbar();
    
    delay(500);
    
    ledOff();
    
    delay(500);
    
    ledColorAmbar();
    
  } else ledColorVerde(); //Si hay una distancia mas que sificiente de activa con un color verde fijo
}

// Metodos para los colores del LedRGB
void ledColorAmbar()
{
  digitalWrite(azul,  off);
  analogWrite (verde, 128);
  analogWrite (rojo,  200);
}

void ledColorRojo()
{
  digitalWrite(azul,  off);
  digitalWrite(verde, off);
  digitalWrite(rojo,  on);
}

void ledColorVerde()
{
  digitalWrite(azul,  off);
  digitalWrite(verde, on);
  digitalWrite(rojo,  off);
}

void ledOff() //Apagado del led
{  
  digitalWrite(rojo, off);
  digitalWrite(azul, off);
  digitalWrite(verde, off);
}