#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/stat.h>

#include "gpiolib.h"

int gpio_direction(int gpio, int dir)
{
	int ret = 0;
	char buf[50];
	sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);
	int gpiofd = open(buf, O_WRONLY);
	if (gpiofd < 0) {
		perror("Couldn't open IRQ file");
		ret = -1;
	}

	if (dir == 1 && gpiofd) {
		if (3 != write(gpiofd, "out", 3)) {
			perror("Couldn't set GPIO direction to out");
			ret = -3;
		}
	}
	else if (gpiofd) {
		if (2 != write(gpiofd, "in", 2)) {
			perror("Couldn't set GPIO directio to in");
			ret = -4;
		}
	}

	close(gpiofd);
	return ret;
}

int gpio_export(int gpio)
{
	int efd;
	char buf[50];
	int gpiofd, ret;

	// Checar si esta exportado  
	sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);
	efd = open(buf, O_WRONLY);
	if (efd != -1) {
		close(efd);
		return 0;
	}

	efd = open("/sys/class/gpio/export", O_WRONLY);

	if (efd != -1) {
		sprintf(buf, "%d", gpio);
		ret = write(efd, buf, strlen(buf));
		if (ret < 0) {
			perror("Export failed");
			return -2;
		}
		close(efd);
	}
	else {
		return -1;
	}
	return 0;
}

void gpio_unexport(int gpio)
{
	int gpiofd, ret;
	char buf[50];
	gpiofd = open("/sys/class/gpio/unexport", O_WRONLY);
	sprintf(buf, "%d", gpio);
	ret = write(gpiofd, buf, strlen(buf));
	close(gpiofd);
}

int gpio_read(int gpio)
{
	char in[3] = { 0, 0, 0 };
	char buf[50];
	int nread, gpiofd;
	sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);
	gpiofd = open(buf, O_RDWR);
	if (gpiofd < 0) {
		fprintf(stderr, "Failed to open gpio %d value\n", gpio);
		perror("gpio failed");
	}

	do {
		nread = read(gpiofd, in, 1);
	} while (nread == 0);
	if (nread == -1) {
		perror("GPIO Read failed");
		return -1;
	}

	close(gpiofd);
	return atoi(in);
}

int gpio_write(int gpio, int val)
{
	char buf[50];
	int nread, ret, gpiofd;
	sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);
	gpiofd = open(buf, O_RDWR);
	if (gpiofd > 0) {
		snprintf(buf, 2, "%d", val);
		ret = write(gpiofd, buf, 2);
		if (ret < 0) {
			perror("failed to set gpio");
			return 1;
		}

		close(gpiofd);
		if (ret == 2) return 0;
	}
	return 1;
}
