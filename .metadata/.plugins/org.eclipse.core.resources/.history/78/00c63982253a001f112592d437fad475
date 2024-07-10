/**
 ******************************************************************************
  * @file		: ZED_serial.h
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


#ifndef SRC_ZED_UART_H_
#define SRC_ZED_UART_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define __PACKED __attribute__((packed))

typedef enum __PACKED
{
	MODEM_SERIAL_BAUD_9600 = 0,
	MODEM_SERIAL_BAUD_19200,
	MODEM_SERIAL_BAUD_38400,
	MODEM_SERIAL_BAUD_57600,
	MODEM_SERIAL_BAUD_115200,
	MODEM_SERIAL_BAUD_230400,
	MODEM_SERIAL_BAUD_460800,
	MODEM_SERIAL_BAUD_500000,
	MODEM_SERIAL_BAUD_576000,
	MODEM_SERIAL_BAUD_921600,
	MODEM_NUM_OF_BAUDRATE
} modem_serial_baudrate_et;

typedef enum __PACKED
{
	MODEM_SERIAL_PARITY_NONE = 0,
	MODEM_SERIAL_PARITY_EVEN,
	MODEM_SERIAL_PARITY_ODD,
	MODEM_NUM_OF_SERIAL_PARITY
} modem_serial_parity_et;

typedef struct __PACKED
{
	uint8_t  enabled;
	uint8_t  baudrate;
	uint8_t  parity_bit;
	uint8_t  two_stop_bit_enable;
	uint8_t  rs485_en;
} modem_serial_settings_st;

typedef struct
{
	int32_t data_fd;
	int32_t config_fd;
	int32_t cli_fd;
	int32_t null_fd;

}serial_port_fd_type;

extern serial_port_fd_type serial_port_fd;

int32_t uartInitialize(void);
int32_t config_tty(int32_t tty_fd, modem_serial_baudrate_et baud, modem_serial_parity_et par, uint8_t two_stop_enable);
int32_t	get_tty_config(int32_t tty_fd, modem_serial_settings_st* settings);
void flush_serial(int32_t tty_fd);


#endif /* SRC_ZED_UART_H_ */
