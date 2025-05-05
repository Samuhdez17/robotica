// C++ code
//

// Variables estaticas para hacer el codigo mas entendible
// Leds en "eje" vertical 
static int rojosV 		= 11;
static int amarillosV 	= 12;
static int verdesV 		= 13;

// Leds en "eje" horizontal
static int rojosH 		= 8;
static int amarillosH 	= 9;
static int verdesH 		= 10;

// Variables para marcar encendido y apagado digital
static int on 	= HIGH;
static int off 	= LOW;

void setup()
{
  // Todos los leds se marcan como salida de señal
  pinMode(rojosV, 		OUTPUT);
  pinMode(amarillosV, 	OUTPUT);
  pinMode(verdesV, 		OUTPUT);

  pinMode(rojosH, 		OUTPUT);
  pinMode(amarillosH, 	OUTPUT);
  pinMode(verdesH, 		OUTPUT);
  
  // Se inician los semaforos en rojo
  iniciarSemaforos();
  
  delay(3000);
}

void loop()
{  
  for (int segundo = 0 ; segundo < 30 ; segundo ++) {
    if (segundo <= 9) {
      semaforosH('v');
      semaforosV('r');
      
    } else if (segundo <= 14) {
      if (segundo < 13) {
        semaforosH('a');
        
      } else {
        semaforosH('r');
        semaforosV('a');
      }
      
    } else if (segundo <= 24) {
      semaforosV('v');
      
    } else {
      if (segundo < 28) {
        semaforosV('a');
        
      } else {
        semaforosH('a');
        semaforosV('r');
      }
    }
    
    delay(1000);
  }
}



void semaforosV(char estado) {
  if (estado == 'v') {
    digitalWrite(rojosV,     off);
    digitalWrite(amarillosV, off);
    digitalWrite(verdesV,     on);
    
  } else if (estado == 'a') {
    	digitalWrite(rojosV,     off);
    	digitalWrite(amarillosV,  on);
    	digitalWrite(verdesV,    off);
    
  } else {
    digitalWrite(rojosV,      on);
    digitalWrite(amarillosV, off);
    digitalWrite(verdesV,    off);
  }  
}

void semaforosH(char estado) {
  if (estado == 'v') {
    digitalWrite(rojosH,     off);
    digitalWrite(amarillosH, off);
    digitalWrite(verdesH,     on);
    
  } else if (estado == 'a') {
    	digitalWrite(rojosH,     off);
    	digitalWrite(amarillosH,  on);
    	digitalWrite(verdesH,    off);
    
  } else {
    digitalWrite(rojosH,      on);
    digitalWrite(amarillosH, off);
    digitalWrite(verdesH,    off);
  }
}

void apagarSemaforos() {
  digitalWrite(rojosV, 		off);
  digitalWrite(amarillosV, 	off);
  digitalWrite(verdesV, 	off);

  digitalWrite(rojosH, 		off);
  digitalWrite(amarillosH, 	off);
  digitalWrite(verdesH, 	off);
}

void encenderSemaforos() {
  digitalWrite(rojosV, 		on);
  digitalWrite(amarillosV, 	on);
  digitalWrite(verdesV, 	on);

  digitalWrite(rojosH, 		on);
  digitalWrite(amarillosH, 	on);
  digitalWrite(verdesH, 	on);
}

void iniciarSemaforos() {
 semaforosV('r');
 semaforosH('r');
}