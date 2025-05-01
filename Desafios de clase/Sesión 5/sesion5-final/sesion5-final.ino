#include <DamiiawaLibs_Brainbox.h>

int azul;
int amarillo;

void setup() {
  usoMovimiento();
  usoSensores();
}

void loop() {

  azul = leerBotonC();
  amarillo = leerBotonD();

  if(azul == 1 && amarillo == 1){
    avanzar(80);
  }
  
  while (azul == 0) {

    avanzar(100, 0);

    if (azul == 0) {
      azul = leerBotonC();
    }
  }


  while (amarillo == 0) {

    avanzar(0, 100);

    if (amarillo == 0) {
      amarillo = leerBotonD();
    }
  }

}