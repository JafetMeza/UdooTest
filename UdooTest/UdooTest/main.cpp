#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <iostream>
#include <fstream>
#include <termios.h>    // POSIX terminal control definitions

#include "gpiolib.h"
#include "serialCommunication.h"
#include "adclib.h"
using namespace std;
constexpr auto INPUT = 0;;
constexpr auto OUTPUT = 1;;
constexpr auto HIGHT = 1;;
constexpr auto LOW = 0;;

//CODIGO PRUEBA PARA UTILIZAR LAS ENTRADAS Y SALIDAS DIGITALES DEL GPIO
//int main()
//{
//    int pin_27 = 25; //Pin 53
//    int gpio_pin = 22; //Pin 49
//
//    gpio_export(pin_27);
//    gpio_export(gpio_pin);
//    gpio_direction(pin_27, INPUT);
//    gpio_direction(gpio_pin, OUTPUT);
//
//    while (true)
//    {
//        int result = gpio_read(pin_27);
//        switch (result)
//        {
//        case 1:
//            printf(">> GPIO %d ON\n", pin_27);
//            gpio_write(gpio_pin, 1);
//            break;
//
//        case 0:
//            printf(">> GPIO %d OFF\n", pin_27);
//            gpio_write(gpio_pin, 0);
//            break;
//
//        case -1:
//            printf(">> ERROR AL LEER %d OFF\n", pin_27);
//            break;
//
//        default:
//            printf(">> ERROR\n");
//            break;
//        }
//    }
//    return 0;
//}


//CODIGO PRUEBA PARA COMUNICACION SERIAL LEER
//int main(void) {
//    //char* portname = "/dev/ttyS0";             //Nombre del puerto serial para udoo quad
//    char* portname = "/dev/ttyMCC";              //Nombre del puerto serial para udoo neo
//    int fd = 0;
//    
//    fd = serialCommunication_init(portname);
//    if (fd > 0)
//    {
//        set_interface_attribs(fd, B115200, 0);		// set speed to 115,200 bps, 8n1 (no parity)
//        set_blocking(fd, 0);						// set no blocking
//    }
//    
//    char buf[7];
//    char result[64];
//    while (true)
//    {
//        result = read_serialCommunication(fd, buf);
//        if (result != '\0')
//        {
//            cout << "Read: " << atoi(result) << endl;
//        }
//        else
//        {
//            cout << "Error reading " << endl;
//        }
//    }
//    close(fd);
//}

//CODIGO PRUEBA PARA COMUNICACION SERIAL LEER Y ESCRIBIR
int main(void) {
    //char* portname = "/dev/ttyS0";             //Nombre del puerto serial para udoo quad
    char* portname = "/dev/ttyMCC";              //Nombre del puerto serial para udoo neo
    int fd = 0;

    fd = serialCommunication_init(portname);
    if (fd > 0)
    {
        set_interface_attribs(fd, B115200, 0);		// set speed to 115,200 bps, 8n1 (no parity)
        set_blocking(fd, 0);						// set no blocking
    }

    char buf[7];
    char buff[7];
    int valueW;
    char *valueR;
    while (true)
    {
        cout << "Ingrese un 1 para prender un led o un 0 para apagarlo: ";
        cin >> buf;
        valueW = write_serialCommunication(fd, buf);
        if (valueW > 0)
        {
            valueR = read_serialCommunication(fd, buff);
            if (valueR > 0)
            {
                cout << "Lectura Recibida: " << valueR << endl;
                usleep(1000000);
            }
            else
            {
                cout << "Error de lectura" << endl;
            }
        }
    }
    close(fd);
}

//CODIGO PARA ADC
//int main(void)
//{
//	int value = 0;
//	while (true)
//	{
//		value = adc_read(0);
//		if (value > -1)
//		{
//			cout << "ADC Value: " << value << endl;
//		}
//		usleep(100000);
//	}
//}

//CODIGO PARA PWM
//int main(void)
//{
//	int efd;
//	char buf[50];
//	int gpiofd, ret;
//
//	// Checar si esta exportado  
//	int fd = open("/sys/class/pwm/pwmchip0/export", O_RDWR);
//	if (fd < 0)
//	{
//		cout << "Error" << endl;
//		return 0;
//	}
//}