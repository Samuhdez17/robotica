               // Variables constantes
#define on HIGH
#define off LOW

// Semaforo 1
#define sem1V 1
#define sem1A 1
#define sem1R 1

// Semaforo 2
#define sem2V 1
#define sem2A 1
#define sem2R 1

// Semaforo 3
#define sem3V 1
#define sem3A 1
#define sem3R 1

// Semaforo 4
#define sem4V 1
#define sem4A 1
#define sem4R 1

// Peaton 1
#define peaton1 1

// Peaton 2
#define peaton2 1

// Peaton 3
#define peaton3 1
 
// Pulsadores
#define pulsador1 1 
#define pulsador2 1
#define pulsador3 1

// ESTRUCTURA DEL PROTOTHREAD
#include <pt.h>

static struct pt semaforos;
long t = millis();

static int ptSemaforoCarretera(struct pt *pt) {
  PT_BEGIN(pt);
  while (1) {
    semaforo1('v');
    semaforo4('v');

    semaforo2('r');
    semaforo3('r');
    PT_WAIT_WHILE(semaforos, (t + 1500) < millis());

    semaforo1('a');
    PT_WAIT_WHILE(semaforos, (t + 1500) < millis());

    semaforo1('r');
    PT_WAIT_WHILE(semaforos, (t + 1500) < millis());
  }
  PT_END(pt);
}

void setup() {
  // Semaforos
  pinMode(sem1V, OUTPUT);
  pinMode(sem1A, OUTPUT);
  pinMode(sem1R, OUTPUT);

  pinMode(sem2V, OUTPUT);
  pinMode(sem2A, OUTPUT);
  pinMode(sem2R, OUTPUT);

  pinMode(sem3V, OUTPUT);
  pinMode(sem3A, OUTPUT);
  pinMode(sem3R, OUTPUT);

  pinMode(sem4V, OUTPUT);
  pinMode(sem4A, OUTPUT);
  pinMode(sem4R, OUTPUT);

  // Peatones
  pinMode(peaton1, OUTPUT);
  pinMode(peaton2, OUTPUT);
  pinMode(peaton3, OUTPUT);

  // Pulsadores
  pinMode(pulsador1, INPUT);
  pinMode(pulsador2, INPUT);
  pinMode(pulsador3, INPUT);

  PT_INIT(&semaforos);
}

void loop() {
  ptSemaforoCarretera(semaforos);
}

void semaforo1(char estado) {
  if (estado == 'v') {
    digitalWrite(sem1V,  on);
    digitalWrite(sem1A, off);
    digitalWrite(sem1R, off);
  }

  if (estado == 'a') {
    digitalWrite(sem1V, off);
    digitalWrite(sem1A,  on);
    digitalWrite(sem1R, off);
  }

  if (estado == 'r') {
    digitalWrite(sem1V, off);
    digitalWrite(sem1A, off);
    digitalWrite(sem1R,  on);
  }
}

void semaforo2(char estado) {
  if (estado == 'v') {
    digitalWrite(sem2V,  on);
    digitalWrite(sem2A, off);
    digitalWrite(sem2R, off);
  }

  if (estado == 'a') {
    digitalWrite(sem2V, off);
    digitalWrite(sem2A,  on);
    digitalWrite(sem2R, off);
  }

  if (estado == 'r') {
    digitalWrite(sem2V, off);
    digitalWrite(sem2A, off);
    digitalWrite(sem2R,  on);
  }
}

void semaforo3(char estado) {
  if (estado == 'v') {
    digitalWrite(sem3V,  on);
    digitalWrite(sem3A, off);
    digitalWrite(sem3R, off);
  }

  if (estado == 'a') {
    digitalWrite(sem3V, off);
    digitalWrite(sem3A,  on);
    digitalWrite(sem3R, off);
  }

  if (estado == 'r') {
    digitalWrite(sem3V, off);
    digitalWrite(sem3A, off);
    digitalWrite(sem3R,  on);
  }
}

void semaforo4(char estado) {
  if (estado == 'v') {
    digitalWrite(sem4V,  on);
    digitalWrite(sem4A, off);
    digitalWrite(sem4R, off);
  }
  

  if (estado == 'a') {
    digitalWrite(sem4V, off);
    digitalWrite(sem4A,  on);
    digitalWrite(sem4R, off);
  }

  if (estado == 'r') {
    digitalWrite(sem4V, off);
    digitalWrite(sem4A, off);
    digitalWrite(sem4R,  on);
  }
}

void semaforosOff() {
  digitalWrite(sem1V, off);
  digitalWrite(sem1A, off);
  digitalWrite(sem1R, off);

  digitalWrite(sem2V, off);
  digitalWrite(sem2A, off);
  digitalWrite(sem2R, off);

  digitalWrite(sem3V, off);
  digitalWrite(sem3A, off);
  digitalWrite(sem3R, off);

  digitalWrite(sem4V, off);
  digitalWrite(sem4A, off);
  digitalWrite(sem4R, off);

  digitalWrite(peaton1, off);
  digitalWrite(peaton2, off);
  digitalWrite(peaton3, off);
}

void iniciarSemaforos() {
  semaforo1('r');
  semaforo2('r');
  semaforo3('r');
  semaforo4('r');

  digitalWrite(peaton1, off);
  digitalWrite(peaton2, off);
  digitalWrite(peaton3, off);
}
