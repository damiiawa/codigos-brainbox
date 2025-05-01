#include <DamiiawaLibs_Brainbox.h>

  int li, ld;

  int ui = 300;
  int ud = 310;

  void setup() {
    usoMovimiento();
    usoSensores();
  }

  void loop() {

    li = leerLineaIzquierda();
    ld = leerLineaDerecha();

    if (li > ui && ld > ud) {
      avanzar(80, 80);
    } else if (li < ui && ld > ud) {
      avanzar(80,0);
    } else if (li > ui && ld < ud) {
      avanzar(0, 80);
    }
  }