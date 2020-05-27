#pragma once
#ifndef _GPIOLIB_H_

//Devuelve -1 si no se puede exportar
int gpio_export(int gpio);
/* Setear direccion, 1 para salida, 0 para entrada*/
int gpio_direction(int gpio, int dir);
/* Libera el pin GPIO */
void gpio_unexport(int gpio);
/* Lee el valor del pin, devuelve 0 o 1 */
int gpio_read(int gpio);
/* Setea el pin, puedes enviar 1 o 0*/
int gpio_write(int gpio, int val);

#endif //_GPIOLIB_H_