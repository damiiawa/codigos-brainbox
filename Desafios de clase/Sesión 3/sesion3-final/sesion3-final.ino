#include <DamiiawaLibs_Brainbox.h>

int camino = 0;
int rojo;
int azul;
int amarillo;

void setup() {
  usoMovimiento();
  usoSensores();
}

void loop() {

  rojo = leerBotonB();
  azul = leerBotonC();
  amarillo = leerBotonD();

  if (azul == 0) {
    camino = 1;
  } else if (amarillo == 0) {
    camino = 3;
  } else if (amarillo == 0 && rojo == 0) {
    camino = 2;
  }

  if (camino == 1) {
    avanzar(60);
    pausa(800);

    girarIzquierda(80);
    pausa(500);

    avanzar(60);
    pausa(2000);

    girarDerecha(80);
    pausa(500);

    avanzar(60);
    pausa(5000);

    finPrograma();
  } else if (camino == 2) {
    avanzar(80);
    pausa(7000);

    finPrograma();
  } else if
    if (camino == 3) {
      avanzar(100);
      pausa(500);

      girarDerecha(80);
      pausa(500);

      avanzar(100);
      pausa(1500);

      girarIzquierda(80);
      pausa(500);

      avanzar(100);
      pausa(4000);

      finPrograma();
    }
}
