#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "adclib.h"

int adc_read(int adc_pin)
{
	char val[7] = { 0, 0, 0, 0, 0, 0, 0 };
	char buf[50];
	int nread, adcfd;
	sprintf(buf, "/sys/bus/iio/devices/iio:device%d/in_voltage%d_raw", adc_pin, adc_pin);
	adcfd = open(buf, O_RDONLY);
	if (adcfd < 0) {
		fprintf(stderr, "Failed to open gpio %d value\n", adc_pin);
		perror("adc failed");
	}

	do {
		nread = read(adcfd, val, sizeof val);
		lseek(adcfd, 0, SEEK_SET);
	} while (nread == 0);
	if (nread == -1) {
		perror("ADC Read failed");
		return -1;
	}

	close(adcfd);
	return atoi(val);
}