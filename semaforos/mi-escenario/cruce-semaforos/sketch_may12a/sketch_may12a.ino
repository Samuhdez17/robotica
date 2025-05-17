               // Variables constantes
#define on HIGH
#define off LOW

// Semaforo 1
#define sem1V 34
#define sem1A 23
#define sem1R 22

// Semaforo 2
#define sem2V 18
#define sem2A 19
#define sem2R 21

// Semaforo 3
#define sem3V 13
#define sem3A 14
#define sem3R 12

// Semaforo 4
#define sem4V 467
#define sem4A 1
#define sem4R 1

// Peaton 1
#define peaton1 35

// Peaton 2
#define peaton2 5

// Peaton 3
#define peaton3 2
 
// Pulsadores
#define pulsador1 32 
#define pulsador2 33
#define pulsador3 25

// ESTRUCTURA DEL PROTOTHREAD
#include <pt.h>

static struct pt semC1;
static struct pt semC2;
static struct pt semC3;
static struct pt semC4;

static struct pt semP1;
static struct pt semP2;
static struct pt semP3;

static struct pt puls1;
static struct pt puls2;
static struct pt puls3;
long t = millis();

static int ptSemC1(struct pt *pt) {
  PT_BEGIN(pt);

  while (1) {
    t = millis();
    estadoSemaforo(1, 'v');
    PT_WAIT_WHILE(pt, (t + 2000) < millis());

    t = millis();
    estadoSemaforo(1, 'a');
    PT_WAIT_WHILE(pt, (t + 1500) < millis());
    
    t = millis();
    estadoSemaforo(1, 'r');
    PT_WAIT_WHILE(pt, (t + 3500) < millis());

    t = millis();
    estadoSemaforo(1, 'a');
    PT_WAIT_WHILE(pt, (t + 1500) < millis());
  }

  PT_END(pt);
}

static int ptSemC2(struct pt *pt) {
  PT_BEGIN(pt);

  while (1) {
    t = millis();
    estadoSemaforo(2, 'r');
    PT_WAIT_WHILE(pt, (t + 3500) < millis());

    t = millis();
    estadoSemaforo(2, 'a');
    PT_WAIT_WHILE(pt, (t + 1500) < millis());
    
    t = millis();
    estadoSemaforo(2, 'v');
    PT_WAIT_WHILE(pt, (t + 2000) < millis());

    t = millis();
    estadoSemaforo(2, 'a');
    PT_WAIT_WHILE(pt, (t + 1500) < millis());
  }

  PT_END(pt);
}

static int ptSemC3(struct pt *pt) {
  PT_BEGIN(pt);

  while (1) {
    t = millis();
    estadoSemaforo(3, 'r');
    PT_WAIT_WHILE(pt, (t + 3500) < millis());

    t = millis();
    estadoSemaforo(3, 'a');
    PT_WAIT_WHILE(pt, (t + 1500) < millis());
    
    t = millis();
    estadoSemaforo(3, 'v');
    PT_WAIT_WHILE(pt, (t + 2000) < millis());

    t = millis();
    estadoSemaforo(3, 'a');
    PT_WAIT_WHILE(pt, (t + 1500) < millis());
  }

  PT_END(pt);
}

static int ptSemC4(struct pt *pt) {
  PT_BEGIN(pt);

  while (1) {
    t = millis();
    estadoSemaforo(4, 'v');
    PT_WAIT_WHILE(pt, (t + 2000) < millis());

    t = millis();
    estadoSemaforo(4, 'a');
    PT_WAIT_WHILE(pt, (t + 1500) < millis());

    t = millis();
    estadoSemaforo(4, 'r');
    PT_WAIT_WHILE(pt, (t + 3500) < millis());

    t = millis();
    estadoSemaforo(4, 'a');
    PT_WAIT_WHILE(pt, (t + 1500) < millis());
  }

  PT_END(pt);
}

void setup() {
  //iniciarSemaforos();
  semaforosOff();

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

 // PT_INIT(&semaforo1);
}

void loop() {
//  ptSemC1(&semaforo1);
//  ptSemC2(&semaforo2);
//  ptSemC3(&semaforo3);
//  ptSemC4(&semaforo4);
  int estadoBoton1 = digitalRead(pulsador1);
  int estadoBoton2 = digitalRead(pulsador2);
  int estadoBoton3 = digitalRead(pulsador3);
  
  estadoSemaforo(1, 'v');
  estadoSemaforo(2, 'v');
  estadoSemaforo(3, 'v');
  estadoSemaforo(4, 'v');

  if (estadoBoton1 == on) digitalWrite(peaton1, on);
  if (estadoBoton2 == on) digitalWrite(peaton2, on);
  if (estadoBoton3 == on) digitalWrite(peaton3, on);

  delay(500);

  estadoBoton1 = digitalRead(pulsador1);
  estadoBoton2 = digitalRead(pulsador2);
  estadoBoton3 = digitalRead(pulsador3);

  estadoSemaforo(1, 'a');
  estadoSemaforo(2, 'a');
  estadoSemaforo(3, 'a');
  estadoSemaforo(4, 'a');

  if (estadoBoton1 == on) digitalWrite(peaton1, on);
  if (estadoBoton2 == on) digitalWrite(peaton2, on);
  if (estadoBoton3 == on) digitalWrite(peaton3, on);

  delay(500);

  estadoBoton1 = digitalRead(pulsador1);
  estadoBoton2 = digitalRead(pulsador2);
  estadoBoton3 = digitalRead(pulsador3);

  estadoSemaforo(1, 'r');
  estadoSemaforo(2, 'r');
  estadoSemaforo(3, 'r');
  estadoSemaforo(4, 'r');

  if (estadoBoton1 == on) digitalWrite(peaton1, on);
  if (estadoBoton2 == on) digitalWrite(peaton2, on);
  if (estadoBoton3 == on) digitalWrite(peaton3, on);

  delay(500);
}

void estadoSemaforo(int semaforo, char estado) {
  switch(semaforo) {
    case 1: 
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

    break;

    case 2:
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

    break;

    case 3:
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

    break;

    case 4:
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
    
    break;
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
  estadoSemaforo(1, 'r');
  estadoSemaforo(2, 'r');
  estadoSemaforo(3, 'r');
  estadoSemaforo(4, 'r');

  digitalWrite(peaton1, off);
  digitalWrite(peaton2, off);
  digitalWrite(peaton3, off);
}
