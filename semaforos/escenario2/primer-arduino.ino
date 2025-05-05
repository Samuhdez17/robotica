//============================
//||    CUADRADO CENTRAL    ||
//============================

// Leds en "eje" vertical
#define rojosVC 	 11
#define amarillosVC  12
#define verdesVC 	 13

// Leds en "eje" horizontal
#define rojosHC	       8
#define amarillosHC    9
#define verdesHC	  10

// Variables para pines de envio de señal
#define A0 horCoche 
#define A1 horPeatones
#define A2 verCoches
#define A3 verPeatones

// Variables para marcar encendido y apagado digital
#define on  HIGH
#define off LOW

void setup()
{ 
  // Todos los leds se marcan como salida de señal
  pinMode(rojosVC,		OUTPUT);
  pinMode(amarillosVC,	OUTPUT);
  pinMode(verdesVC,		OUTPUT);

  pinMode(rojosHC,		OUTPUT);
  pinMode(amarillosHC,	OUTPUT);
  pinMode(verdesHC,		OUTPUT);
  
  pinMode(horCoche ,	OUTPUT);
  pinMode(horPeatones,	OUTPUT);
  pinMode(verCoches,	OUTPUT);
  pinMode(verPeatones,	OUTPUT);
  
  // Se inician los semaforos en rojo
  iniciarSemaforos();
  
  delay(3000);
}

void loop()
{  
  for (int segundo = 0 ; segundo < 30 ; segundo ++) {
    // 10 seg,horizontales en verde ; verticales en rojo
    if (segundo <= 9) {
      semaforosHC('v');
      semaforosVC('r');
      analogWrite(verPeatones, x); // Se manda una señal de cierta potencia para saber si se tiene que poner en rojo o en verde 
//             ^-- Así con todos los pines extras      
    } else if (segundo <= 14) {
      if (segundo < 13) {
        semaforosHC('a');
        
      } else {
        semaforosHC('r');
        semaforosVC('a');
      }
      
    } else if (segundo <= 24) {
      semaforosVC('v');
      
    } else {
      if (segundo < 28) {
        semaforosVC('a');
        
      } else {
        semaforosHC('a');
        semaforosVC('r');
      }
    }
    
    delay(1000);
    
    
  }
}



void semaforosVC(char estado) {
  if (estado == 'v') {
    digitalWrite(rojosVC, 	  off);
    digitalWrite(amarillosVC, off);
    digitalWrite(verdesVC, 	  on);
    
  } else if (estado == 'a') {
    	digitalWrite(rojosVC, 	  off);
    	digitalWrite(amarillosVC, on);
    	digitalWrite(verdesVC, 	  off);
    
  } else {
    digitalWrite(rojosVC, 	  on);
    digitalWrite(amarillosVC, off);
    digitalWrite(verdesVC, 	  off);
  }  
}

void semaforosHC(char estado) {
  if (estado == 'v') {
    digitalWrite(rojosHC,		off);
    digitalWrite(amarillosHC,	off);
    digitalWrite(verdesHC,		 on);
    
  } else if (estado == 'a') {
    	digitalWrite(rojosHC,		off);
    	digitalWrite(amarillosHC,	 on);
    	digitalWrite(verdesHC,		off);
    
  } else {
    digitalWrite(rojosHC,		 on);
    digitalWrite(amarillosHC,	off);
    digitalWrite(verdesHC,		off);
  }
}

void apagarSemaforos() {
  digitalWrite(rojosVC, 	off);
  digitalWrite(amarillosVC, off);
  digitalWrite(verdesVC, 	off);
  
  digitalWrite(rojosHC,		off);
  digitalWrite(amarillosHC,	off);
  digitalWrite(verdesHC,	off);
}

void encenderSemaforos() {
  digitalWrite(rojosVC, 	on);
  digitalWrite(amarillosVC, on);
  digitalWrite(verdesVC, 	on);

  digitalWrite(rojosHC,		on);
  digitalWrite(amarillosHC,	on);
  digitalWrite(verdesHC,	on);
}

void iniciarSemaforos() {
 semaforosVC('r');
 semaforosHC('r');
}