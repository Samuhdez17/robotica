#define pinBuzzer 13
//                      Do , Do#, Re,  Re#, Mi,  Fa,  Fa#, Sol, Sol#, La, La#, Si
const int tonos[]    = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
const int countTonos = 10;
   
void setup()
{
  pinMode(pinBuzzer, OUTPUT);
}

void loop()
{
  for (int iTono = 0; iTono < countTonos; iTono++)
  {
    tone(pinBuzzer, tonos[iTono]);
    delay(1000);
  }

  noTone(pinBuzzer);
}
/*
void cantar()
{
  int duracion = sizeof(cancion1) / sizeof(int);
  
  for (int notaActual = 0 ; notaActual < duracion ; notaActual++) {
    int duracionNota = 500 / tempoCancion1[notaActual];

    tone(altavoz, cancion1[notaActual], duracionNota);

    int pausaEntreNotas = duracionNota * 1.15;
    
    delay(pausaEntreNotas);
      
    noTone(altavoz);
      
    delay(10);

  }
}