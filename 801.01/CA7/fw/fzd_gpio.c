/**
 ******************************************************************************
  * @file		: ZED_gpio.c
  * @brief		: Task scheduler source file
  *				  This file contains task structure of the application
  * @author		: Faruk Sozuer
  * @date		: 10.04.2024
  * @version	: 0.0.1
 ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 ZED TECH, All Rights Reserved </center></h2>
  *
  * All information contained herein is, and remains the property of ZED TECH. The
  * intellectual and technical concepts contained herein are proprietary to ZED TECH
  * and are protected by trade secret or copyright law. Dissemination of this
  * information or reproduction of this material is strictly forbidden unless
  * prior written permission is obtained from ZED TECH.  Access to the source code
  * contained herein is hereby forbidden to anyone except current ZED TECH employees,
  * managers or contractors who have executed Confidentiality and Non-disclosure
  * agreements explicitly covering such access.
  *
 ******************************************************************************
  */

#include "fzd_gpio.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * @brief
 *
 * @param
 *
 * @return
 *
 * */
int32_t gpioSet(uint8_t pin, uint8_t val)
{
	int32_t fd = -1;

	char pin_str[32];
	char path[256];

	// Export
	sprintf(pin_str, "%d",OUTPUT_PORT_MAP + pin);

	fd = open("/sys/class/gpio/export", O_WRONLY);

	if (fd < 0)
		return -1;

	write(fd, pin_str, strlen(pin_str) + 1);
	close(fd);
	fd = -1;

	// Direction
	sprintf(path, "/sys/class/gpio/gpio%s/direction", pin_str);

	fd = open(path, O_RDWR);

	if (fd < 0)
		return -1;

	write(fd, "out", 4);
	close(fd);
	fd = -1;

	// Value
	sprintf(path, "/sys/class/gpio/gpio%s/value", pin_str);

	fd = open(path, O_RDWR);

	if (fd < 0)
		return -1;

	write(fd, (val & 1U) ? "1" : "0", 2);
	close(fd);
	fd = -1;

	// Unexport
	fd = open("/sys/class/gpio/unexport", O_WRONLY);

	if (fd < 0)
		return -1;

	write(fd, pin_str, strlen(pin_str) + 1);
	close(fd);
	fd = -1;

	return 0;
}



/*
 * @brief
 *
 * @param
 *
 * @return
 *
 * */
uint8_t gpioGet(uint8_t pin)
{
	int32_t fd;
	char pin_str[32];
	char path[256];
	uint8_t ret = 0;
	sprintf(pin_str, "%d", INPUT_PORT_MAP + pin);

	fd = open("/sys/class/gpio/export", O_WRONLY);
	if (fd > 0) {
		write(fd, pin_str, strlen(pin_str) + 1);
		close(fd); fd = 0;
	}

	sprintf(path, "/sys/class/gpio/gpio%s/value", pin_str);
	FILE* fp = fopen(path, "r+");
	if (fp != NULL) {
		fscanf(fp, "%c", &ret);
		ret = ret == '1' ? 1 : 0;
		fclose(fp);
	}

	fd = open("/sys/class/gpio/unexport", O_WRONLY);
	if (fd > 0) {
		write(fd, pin_str, strlen(pin_str) + 1);
		close(fd); fd = 0;
	}

	return ret;
}
