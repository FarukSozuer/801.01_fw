/**
 ******************************************************************************
  * @file		: ZED_gpio.h
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

#ifndef SRC_ZED_GPIO_H_
#define SRC_ZED_GPIO_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INPUT_PORT_MAP 	1008
#define OUTPUT_PORT_MAP 1016

#define LED0		0
#define LED1		1
#define LED2 		2
#define LED3 		3
#define LED4		4
#define LED5		5
#define LED6        6
#define LED7        7

#define SWITCH0		0
#define SWITCH1		1
#define SWITCH2  	2
#define SWITCH3 	3
#define SWITCH4		4
#define SWITCH5		5
#define SWITCH6     6
#define SWITCH7     7

typedef union
{
	struct
	{
		uint8_t sw0 :1;
		uint8_t sw1 :1;
		uint8_t sw2 :1;
		uint8_t sw3 :1;
		uint8_t sw4 :1;
		uint8_t sw5 :1;
		uint8_t sw6 :1;
		uint8_t sw7 :1;
	}bits;
	uint8_t all;
}switch_value_type;

int32_t gpio_set(uint8_t pin, uint8_t val);
uint8_t gpio_get(uint8_t pin);

extern switch_value_type switch_value;

#endif /* SRC_ZED_GPIO_H_ */
