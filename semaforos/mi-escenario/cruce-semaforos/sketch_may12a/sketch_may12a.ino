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
#define sem4V 4
#define sem4A 17
#define sem4R 16

// Peaton 1
#define peaton1 35 // Aqui hay un segundo semaforo conectado en paralelo, con lo que son el mismo

// Peaton 2
#define peaton2 5 // Aqui hay un segundo semaforo conectado en paralelo, con lo que son el mismo

// Peaton 3
#define peaton3 2 // Aqui hay un segundo semaforo conectado en paralelo, con lo que son el mismo
 
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

bool peatonEn1 = false;
bool peatonEn2 = false;
bool peatonEn3 = false;

bool darPasoEn1 = false;
bool darPasoEn2 = false;
bool darPasoEn3 = false;

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
    PT_WAIT_WHILE(pt, (t + 3000) < millis());
    if (peatonEn1) {
      peatonEn1 = false;
      darPasoEn1 = true;

      t = millis();
      PT_WAIT_WHILE(pt, (t + 3000) < millis());

      darPasoEn1 = false;
    }

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
    PT_WAIT_WHILE(pt, (t + 3000) < millis());
    if (peatonEn2) {
      darPasoEn2 = true;
      peatonEn2 = false;

      t = millis();
      PT_WAIT_WHILE(pt, (t + 3000) < millis());

      darPasoEn2 = false;
    }

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
    PT_WAIT_WHILE(pt, (t + 3000) < millis());
    if (peatonEn3) {
      darPasoEn3 = true;
      peatonEn3 = false;

      t = millis();
      PT_WAIT_WHILE(pt, (t + 3000) < millis());

      darPasoEn3 = false;
    }

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
    PT_WAIT_WHILE(pt, (t + 3000) < millis());

    t = millis();
    estadoSemaforo(4, 'a');
    PT_WAIT_WHILE(pt, (t + 1500) < millis());
  }

  PT_END(pt);
}

static int ptSemP1(struct pt *pt) {
  PT_BEGIN(pt);

  while (darPasoEn1) {
    digitalWrite(peaton1, on);

    t = millis();
    PT_WAIT_WHILE(pt, (t + 1500) < millis());

    long tiempoBucle = millis();
    while (millis() - tiempoBucle < 1500) {
      digitalWrite(peaton1, off);
      t = millis();
      PT_WAIT_WHILE(pt, millis() - t < 250);

      digitalWrite(peaton1, on);
      t = millis();
      PT_WAIT_WHILE(pt, millis() - t < 250);
    }

    digitalWrite(peaton1, off);
  }

  PT_END(pt);
}
static int ptSemP2(struct pt *pt) {
  PT_BEGIN(pt);

  while (darPasoEn2) {
    digitalWrite(peaton2, on);

    t = millis();
    PT_WAIT_WHILE(pt, (t + 1500) < millis());

    long tiempoBucle = millis();
    while (millis() - tiempoBucle < 1500) {
      digitalWrite(peaton2, off);
      t = millis();
      PT_WAIT_WHILE(pt, millis() - t < 250);

      digitalWrite(peaton2, on);
      t = millis();
      PT_WAIT_WHILE(pt, millis() - t < 250);
    }

    digitalWrite(peaton2, off);
  }

  PT_END(pt);
}
static int ptSemP3(struct pt *pt) {
  PT_BEGIN(pt);

  while (darPasoEn3) {
    digitalWrite(peaton3, on);

    t = millis();
    PT_WAIT_WHILE(pt, (t + 1500) < millis());

    long tiempoBucle = millis();
    while (millis() - tiempoBucle < 1500) {
      digitalWrite(peaton3, off);
      t = millis();
      PT_WAIT_WHILE(pt, millis() - t < 250);

      digitalWrite(peaton3, on);
      t = millis();
      PT_WAIT_WHILE(pt, millis() - t < 250);
    }

    digitalWrite(peaton3, off);
  }

  PT_END(pt);
}

static int ptPuls1(struct pt *pt) {
  PT_BEGIN(pt);

  while (1) {
    static bool ultimoEstadoBoton = off;  // Guarda el estado anterior del botón
    int estadoBoton = digitalRead(pulsador1);

    if (estadoBoton == on && ultimoEstadoBoton == off && !peatonEn1) {
      peatonEn1 = !peatonEn1;  // Cambia el estado del peaton en dicho semaforo
    }

    ultimoEstadoBoton = estadoBoton;  // Guarda el estado actual del botón
  }

  PT_END(pt);
}
static int ptPuls2(struct pt *pt) {
  PT_BEGIN(pt);

  while (1) {
    static bool ultimoEstadoBoton = off;  // Guarda el estado anterior del botón
    int estadoBoton = digitalRead(pulsador2);

    if (estadoBoton == on && ultimoEstadoBoton == off && !peatonEn2) {
      peatonEn2 = !peatonEn2;  // Cambia el estado del peaton en dicho semaforo
    }

    ultimoEstadoBoton = estadoBoton;  // Guarda el estado actual del botón
  }

  PT_END(pt);
}
static int ptPuls3(struct pt *pt) {
  PT_BEGIN(pt);

  while (1) {
    static bool ultimoEstadoBoton = off;  // Guarda el estado anterior del botón
    int estadoBoton = digitalRead(pulsador3);

    if (estadoBoton == on && ultimoEstadoBoton == off && !peatonEn3) {
      peatonEn3 = !peatonEn3;  // Cambia el estado del peaton en dicho semaforo
    }

    ultimoEstadoBoton = estadoBoton;  // Guarda el estado actual del botón
  }

  PT_END(pt);
}

void setup() {
  iniciarSemaforos();
  
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

  PT_INIT(&semC1);
  PT_INIT(&semC2);
  PT_INIT(&semC3);
  PT_INIT(&semC4);

  PT_INIT(&semP1);
  PT_INIT(&semP2);
  PT_INIT(&semP3);

  PT_INIT(&puls1);
  PT_INIT(&puls2);
  PT_INIT(&puls3);
}

void loop() {
  ptSemC1(&semC1);
  ptSemC2(&semC2);
  ptSemC3(&semC3);
  ptSemC4(&semC4);
  
  ptPuls1(&puls1);
  ptPuls2(&puls2);
  ptPuls3(&puls3);
  
  ptSemP1(&semP1);
  ptSemP2(&semP2);
  ptSemP3(&semP3);
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
