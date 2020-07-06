# UdooTest
Creadas librerias para la utilización de las tarjetas udoo.

+------------------------------GPIOLIB------------------------------------------+
|  gpio_export         ---Inicializa el pin seleccionado de la tarjeta          |
|  gpio_direccion      ---Colocas la direccion del pin, entrada 0, salida 1     |
|  gpio_unexport       ---Inhablita el pin                                      |
|  gpio_read           ---Regresa el valor leido del pin                        |
|  gpio_write          ---Escribes 1 o 0 en el pin seleccionado                 | 
+-------------------------------------------------------------------------------+  


+--------------------------------------SERIALCOMMUNICATION--------------------------------------------------------------------+
|  serialCommunication_init(char* portname);                ---Inicializa la comunicacion Serial, retorna -1 si no se logró   |
|                                                              establecer                                                     |
|  set_interface_attribs(int fd, int speed, int parity);    ---Establece la velocidad de la conexion de la comunicaion Serial |
|  set_blocking(int fd, int should_block);                  ---Establece un bloqueo a la comunciacion                         |
|  read_serialCommunication(int fd, char* buff);            ---Leer puerto serial, retorna -1 si no lo leyó                   |
+----------------------------------------------------------------------------------------------------------------------------------+


+-----------------------------ADCLIB -----------------------------------------+
|    ****************************   NOTA  ******************************      | 
|    *******ESTA LIBRERIA SOLO FUNCIONA PARA LA UDO NEO   **************      |
|    ****DEBES DE HACER UN PAR DE CONFIGURACIONES EN LA TARJETA PARA****      |
|    ***HABILITAR LOS PINES ANALOGICOS Y ASI PODER LEERLOS DESDE LINUX**      |
|                                                                             |
|  adc_read(int adc_pin);      ---Devuelve el valor leido del pin analogico   | 
|                                                                             |
+-----------------------------------------------------------------------------+
