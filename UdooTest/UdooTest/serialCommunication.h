#pragma once
#ifndef _SERIALCOMUNICATION_H_
//Inicializa la comunicacion Serial, retorna -1 si no se logró establecer
int serialCommunication_init(char* portname);
//Establece la velocidad de la conexion de la comunicaion Serial
int set_interface_attribs(int fd, int speed, int parity);
//Establece un bloqueo a la comunciacion, manda un 0 si deseas deshabilitar esta función
void set_blocking(int fd, int should_block);
//Leer puerto serial, retorna un valor nulo si no se establecio buena conexion
char* read_serialCommunication(int fd, char* buff);
//Escribir en puerto serial, retorna -1 si ocurrio un error
int write_serialCommunication(int fd, char* buff);
#endif

//CODIGO ARDUINO EN UDOO PARA COMUNICACION BIDIRECCIONAL
//void setup() {
//    Serial.begin(115200);
//    pinMode(11, OUTPUT);
//}
//
//void loop() {
//    if (Serial.available() > 0)
//    {
//        char c = Serial.read();
//        if (c == '1')
//        {
//            digitalWrite(11, HIGH);
//            Serial.write(c);
//        }
//        else if (c == '0')
//        {
//            digitalWrite(11, LOW);
//            Serial.write(c);
//        }
//    }
//}

//CODIGO ARDUINO EN UDOO PARA COMUNICACION UNIDIRECCIONAL (LECTURA)
//void setup() {
//int analogPin = A0;
//int val = 0;
//    Serial.begin(115200);
//}
//
//void loop() {
//	val = analogRead(analogPin);
//	Serial.println(val);
//}