#include <DamiiawaLibs_Brainbox.h>

int contador = 0;

void setup() {
  usoMovimiento();
  usoSensores();
}

void loop() {

  int bC = leerBotonC();
  int bD = leerBotonD();



  if (bC == 0) {
    contador++;
    pausa(500);
  }

  if (bD == 0) {

    if (contador == 1) {
      girarDerecha(85);
      pausa(500);
    }

    if (contador == 2) {
      girarIzquierda(85);
      pausa(500);
    }
  }
}
