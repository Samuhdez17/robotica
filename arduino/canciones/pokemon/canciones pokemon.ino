#include "notas.txt"

int pinBuzzer = 13;

// Melodía del Centro Pokémon
int cancion1[] = {
  NOTE_G4, NOTE_E5, NOTE_D5, NOTE_B4, 
  NOTE_A4, NOTE_B4, NOTE_E4, NOTE_G4, 
  NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4,
  NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4,
  NOTE_G4, NOTE_E5, NOTE_D5, NOTE_B4, 
  NOTE_A4, NOTE_B4, NOTE_E4, NOTE_G4, 
  NOTE_FS4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4,
  NOTE_D4
};

int tempoCancion1[] = {
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 2,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  2
};

int cancion2[] = {
  NOTE_B5, NOTE_A5, NOTE_E6, 
  NOTE_B5, NOTE_A5, NOTE_FS6, NOTE_F6,
  NOTE_B5, NOTE_A5, NOTE_E6, NOTE_B5,
  NOTE_A5, NOTE_FS6, NOTE_F6,
  NOTE_G5, NOTE_F5, NOTE_D5,
  NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_D5,
  NOTE_G5, NOTE_F5, NOTE_D5,
  NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_D5,
  NOTE_E6
};

int tempoCancion2[] = {
  16, 16, 16,  
  16, 16, 32, 32,
  16, 16, 16, 16,
  16, 32, 32,
  16, 16, 16,
  16, 16, 32, 32,
  16, 16, 16,
  16, 16, 32, 32,
  8  
};

void setup() {
    pinMode(pinBuzzer, OUTPUT);
}

void loop() {
    cantar(1);
}

void cantar(int cancion){
  if (cancion == 1){
   int duracion = sizeof(cancion1) / sizeof(int);
  
     for (int notaActual = 0 ; notaActual < duracion ; notaActual++) {
      
       int duracionNota = 2000 / tempoCancion1[notaActual];

       tone(pinBuzzer, cancion1[notaActual], duracionNota);

       int pausaEntreNotas = duracionNota * 1.15;
       delay(pausaEntreNotas);
      
       noTone(pinBuzzer);
      
       delay(10);
     }

     delay(2000);
     
   } else if (cancion == 2){
      int duracion = sizeof(cancion2) / sizeof(int);
  
      for (int notaActual = 0; notaActual < duracion; notaActual++) {
        int duracionNota = 1900 / tempoCancion2[notaActual]; 
        tone(pinBuzzer, cancion2[notaActual], duracionNota);
    
        int pausaEntreNotas = duracionNota * 1.3; 
        delay(pausaEntreNotas);
    
        noTone(pinBuzzer);
        delay(10);
      }
  
      delay(3000);
     }
}
