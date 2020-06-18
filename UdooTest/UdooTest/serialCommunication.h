#pragma once
#ifndef _SERIALCOMUNICATION_H_
//Inicializa la comunicacion Serial, retorna -1 si no se logró establecer
int serialCommunication_init(char* portname);
//Establece la velocidad de la conexion de la comunicaion Serial
int set_interface_attribs(int fd, int speed, int parity);
//Establece un bloqueo a la comunciacion, manda un 0 si deseas deshabilitar esta función
void set_blocking(int fd, int should_block);
//Leer puerto serial, retorna -1 si no se establecio buena conexion
int read_serialCommunication(int fd, char* buff);
#endif