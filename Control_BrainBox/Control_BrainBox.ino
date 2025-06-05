#include <ESP32MotorControl.h>

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>


ESP32MotorControl MotorControl = ESP32MotorControl();

const int MAX_SPEED = 255;

void setup() {

  MotorControl.attachMotors(21, 23, 5, 15);


  Dabble.begin("BrainBox");
}

void loop() {
  Dabble.processInput();

  float x = GamePad.getx_axis(); 
  float y = GamePad.gety_axis(); 
  
  int velocidadIzquierda = constrain((y - x) * (MAX_SPEED / 7), -MAX_SPEED, MAX_SPEED);
  int velocidadDerecha = constrain((y + x) * (MAX_SPEED / 7), -MAX_SPEED, MAX_SPEED);

  if (velocidadIzquierda > 0) {
    MotorControl.motorForward(0, velocidadIzquierda);
  } else if (velocidadIzquierda < 0) {
    MotorControl.motorReverse(0, -velocidadIzquierda);
  } else {
    MotorControl.motorStop(0);
  }

  if (velocidadDerecha > 0) {
    MotorControl.motorForward(1, velocidadDerecha);
  } else if (velocidadDerecha < 0) {
    MotorControl.motorReverse(1, -velocidadDerecha);
  } else {
    MotorControl.motorStop(1);
  }

  if (x == 0 && y == 0) {
    MotorControl.motorsStop();
  }

    if (GamePad.isCirclePressed()) {
    tone(25, 261.6, 250);
    delay(250);
    noTone(25);
    delay(50);
  }
}
