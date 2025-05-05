//============================================
//||   REGULACION DE PASO DE CEBRA A COCHE  ||
//============================================

// Semáforos horizontales para regular a los coches ante el paso de cebra
#define rojoHF  13
#define ambarHF 12
#define verdeHF 11

// Semáforos de pasos de peatones horizontales
#define rojoPH  10
#define verdePH  9

// Semáforo vertical para regular a los coches ante el paso de cebra
#define rojoVF  8
#define ambarVF 7
#define verdeVF 6

// Semáforo de paso de peatones vertical
#define rojoPV  5
#define verdePV 4

// Variables para marcar encendido y apagado digital
#define on  HIGH
#define off LOW

// Variables para recibir la señal de la otra placa
#define A0 horCoche
#define A1 horPeatones
#define A2 verCoches
#define A3 verPeatones

void setup()
{
  pinMode(rojoHF , OUTPUT);
  pinMode(ambarHF, OUTPUT);
  pinMode(verdeHF, OUTPUT);

  pinMode(rojoPH , OUTPUT);
  pinMode(verdePH, OUTPUT);

  pinMode(rojoVF , OUTPUT);
  pinMode(ambarVF, OUTPUT);
  pinMode(verdeVF, OUTPUT);

  pinMode(rojoPV , OUTPUT);
  pinMode(verdePV, OUTPUT);
  
  pinMode(horCoche   , INPUT);
  pinMode(horPeatones, INPUT);
  pinMode(verCoches  , INPUT);
  pinMode(verPeatones, INPUT);
}

void loop()
{
  if (analogRead(horCoches) > 0) {
    // encendido de semaforos horizontales de coches
    
  } else if (analogRead(horPeatones) > 0) {
    // encendido de semaforos horizontales de peaotnes
    
  } else if (analogRead(verCoches) > 0) {
    // encendido de semaforo vertical de coches
    
  } else if (analogRead(verPeatones) > 0) {
    // encendido de semaforo vertical de peaotnes
  }
}