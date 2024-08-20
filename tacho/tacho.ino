#include <Servo.h>
#include "Ultrasonido.h"
#include "Alarma.h"


Ultrasonido ultrasonido(4, 2);
Alarma alarma(7);

Servo servo;

void setup() {
  servo.attach(5);
  Serial.begin(9600);
  servo.write(0);
}

void loop() {

  int distancia = ultrasonido.obtenerDistancia();

  if(distancia > 0 && distancia <= 10){
    alarma.prenderPitido();
    servo.write(90);
    delay(1000);
    alarma.apagarPitido();
    servo.write(0);
    delay(1000);
  } 

  Serial.print("Distancia: ");
  Serial.print(distancia);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
}
