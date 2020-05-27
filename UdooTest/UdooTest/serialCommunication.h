#pragma once
#ifndef _SERIALCOMUNICATION_H_
//Establece la velocidad de la conexion de la comunicaion Serial
int set_interface_attribs(int fd, int speed, int parity);
void set_blocking(int fd, int should_block);
#endif