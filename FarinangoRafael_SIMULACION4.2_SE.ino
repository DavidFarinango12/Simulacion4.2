/*
 *CAPITULO IV: PERIFERICOS ESPECIALES
 *CODIGO 15: CAD Y SERVO
 *OBJETIVO: REALIZAR EL GIRO DE UN UN SERVO MOTOR HASTA EL LIMITE INGRESADO POR COMNICACION SERIAL
 *NOMBRE: RAFAEL FARINANGO
 *FUNCIONES:  analogRead(conversor)
 *            analogWrite(pin,dutty)
 */

#include <Servo.h>

Servo servo1;     //crea objeto para servo1
Servo servo2;     //crea objeto para servo2
int conversor1;   
int conversor2;
String dato;      //para comunicacion serial
int giro = 0;     //variable limite de giro


void setup() {
  Serial.begin(9600);
  servo1.attach(10);    //configuracion servo 1
  servo2.attach(9);     //configuracion servo 2
  Serial.println("Ingrese un valor numerico entre 0 y 180:");
}

void loop() {
  conversor1 = analogRead(0);                 //lectura de conversor 1
  conversor1 = map(conversor1,0,1023,0,180);  //funcion cambio de limite
  servo1.write(conversor1);                   //imprime valor en servo1
  delay(50);                                  //espera de estabilizacion

  conversor2 = analogRead(1);
  if(Serial.available() > 0){
    dato = Serial.readString();    //almacena dato en la variable
    giro = dato.toInt();          //convierte de string a entero   
  }
  if(giro < 180){               //si cumple condicion maxima de giro
      conversor2 = map(conversor2,0,1023,0,giro);
      servo2.write(conversor2);
  }
  else{
    Serial.println("Dato Invalido");
    delay(50);
  }
}
