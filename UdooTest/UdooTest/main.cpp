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
using namespace std;
constexpr auto INPUT = 0;;
constexpr auto OUTPUT = 1;;
constexpr auto HIGHT = 1;;
constexpr auto LOW = 0;;

//CODIGO PRUEBA PARA UTILIZAR LAS ENTRADAS Y SALIDAS DIGITALES DEL GPIO
//int main()
//{
//    /*char buff[3];
//    char* echo = "out";
//    int pin49 = open("/gpio/pin49/direction", O_WRONLY);
//    write(pin49, echo, sizeof(echo));
//    int pin27 = open("/gpio/pin27/direction", O_WRONLY);
//    write(pin27, "in", 2);
//
//    pin49 = open("/gpio/pin49/value", O_WRONLY);
//    pin27 = open("/gpio/pin27/value", O_WRONLY);
//    while (true)
//    {
//        read(pin27, buff, sizeof(buff));
//        write(pin49, "1", 1);
//        usleep(100000);
//        write(pin49, "0", 1);
//        usleep(100000);
//    }
//    close(pin49);
//    close(pin27);*/
//
//    int pin_27 = 88; //Pin 53
//    int gpio_pin = 104; //Pin 49
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


//CODIGO PRUEBA PARA COMUNICACION SERIAL
int main(void) {
    char* portname = "/dev/ttyS0";

    int fd = open("/dev/ttymxc3", O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0)
    {
        cout <<"error %d opening " << errno <<" /dev/ttymxc3 " << strerror(errno);
        return 0;
    }

    set_interface_attribs(fd, B115200, 0);		// set speed to 115,200 bps, 8n1 (no parity)
    set_blocking(fd, 0);						// set no blocking

    char buf[7];
    int n;
    while (true)
    {
        n = read(fd, buf, sizeof buf); 	// read up to 7 characters if ready to read
        if (n > 0)
        {
            cout << "Read: " << atoi(buf) << endl;
        }
        else
        {
            cout << "Error reading " << buf << endl;
        }
    }
    close(fd);
}