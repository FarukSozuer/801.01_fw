/**
 ******************************************************************************
  * @file		: ZED_serial.c
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

#include "fzd_uart.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <termios.h>
#include <sys/stat.h>
#include <fcntl.h>

serial_port_fd_type serial_port_fd;




/*
 * @brief uartInitialize
 *
 *@param
 *
 *@return
 *
 * */
int32_t uartInitialize(void)
{
	//ttyUL2 --> Serial port config line
	//ttyUL3 --> Serial port data line

	int32_t ret = EXIT_SUCCESS;

	// Data Serial Port
	int32_t data_fd = open("/dev/ttyUL1", O_RDWR | O_NONBLOCK);

	if (data_fd > 0)
	{
		config_tty(data_fd, MODEM_SERIAL_BAUD_115200, MODEM_SERIAL_PARITY_NONE, 0);
		serial_port_fd.data_fd  = dup(data_fd);
		close(data_fd);
	}
	else
	{
		serial_port_fd.data_fd  = dup(serial_port_fd.null_fd);
		ret = EXIT_FAILURE;
	}

	// Configuration Serial Port
	int32_t config_fd = open("/dev/ttyUL2",O_RDWR | O_NONBLOCK);

	if(config_fd > 0)
	{
		config_tty(config_fd, MODEM_SERIAL_BAUD_115200, MODEM_SERIAL_PARITY_NONE, 0);
		serial_port_fd.config_fd = dup(config_fd);
		close(config_fd);
	}
	else
	{
		serial_port_fd.config_fd  = dup(serial_port_fd.null_fd);
		ret = EXIT_FAILURE;
	}


	// Cli Serial Port
	int32_t cli_fd = open("/dev/ttyUL3",O_RDWR | O_NONBLOCK);

	if(cli_fd > 0)
	{
		config_tty(cli_fd, MODEM_SERIAL_BAUD_115200, MODEM_SERIAL_PARITY_NONE, 0);
		serial_port_fd.cli_fd = dup(cli_fd);
		close(cli_fd);
	}
	else
	{
		serial_port_fd.cli_fd  = dup(serial_port_fd.null_fd);
		ret = EXIT_FAILURE;
	}

	return ret;
}



/*
 * @brief config_tty
 *
 *@param
 *
 *@return
 *
 * */
int32_t config_tty(int32_t tty_fd, modem_serial_baudrate_et baud, modem_serial_parity_et par, uint8_t two_stop_enable)
{
	struct termios tty_attr = {0};
	speed_t baudrate_return;

	if (isatty(tty_fd) <= 0)
	{
		return EXIT_FAILURE;
	}

	if ( tcgetattr ( tty_fd, &tty_attr ) != 0 )
	{
		memset(&tty_attr, 0, sizeof(tty_attr));
	}

	switch (baud)
	{
		case MODEM_SERIAL_BAUD_9600:
			baudrate_return = B9600;
		break;
		case MODEM_SERIAL_BAUD_19200:
			baudrate_return = B19200;
		break;
		case MODEM_SERIAL_BAUD_38400:
			baudrate_return = B38400;
		break;
		case MODEM_SERIAL_BAUD_57600:
			baudrate_return = B57600;
		break;
		case MODEM_SERIAL_BAUD_115200:
			baudrate_return = B115200;
		break;
		case MODEM_SERIAL_BAUD_230400:
			baudrate_return = B230400;
		break;
		case MODEM_SERIAL_BAUD_460800:
			baudrate_return = B460800;
		break;
		case MODEM_SERIAL_BAUD_500000:
			baudrate_return = B500000;
		break;
		case MODEM_SERIAL_BAUD_576000:
			baudrate_return = B576000;
		break;
		case MODEM_SERIAL_BAUD_921600:
			baudrate_return = B921600;
		break;
		default:
			baudrate_return = B115200;
		break;
	}

	cfmakeraw(&tty_attr);
	cfsetspeed(&tty_attr, baudrate_return);

	if (par == MODEM_SERIAL_PARITY_NONE)
	{
		tty_attr.c_cflag     &=  ~PARENB;
	}
	else if (par == MODEM_SERIAL_PARITY_ODD)
	{
		tty_attr.c_cflag     |=  (PARENB | PARODD);
	}
	else if (par == MODEM_SERIAL_PARITY_EVEN)
	{
		tty_attr.c_cflag     |=  (PARENB);
		tty_attr.c_cflag     &=  ~PARODD;
	}

	if (two_stop_enable)
	{
		tty_attr.c_cflag     |=  CSTOPB;
	}
	else
	{
		tty_attr.c_cflag     &=  ~CSTOPB;
	}

	tty_attr.c_cflag     &=  ~CSIZE;
	tty_attr.c_cflag     |=  CS8;

	tty_attr.c_cflag     &=  ~CRTSCTS;           // no flow control
	tty_attr.c_cc[VMIN]   =  1;                  // read doesn't block
	tty_attr.c_cc[VTIME]  =  0;                 // 1 second read timeout
	tty_attr.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

	tcsetattr(tty_fd, TCSANOW, &tty_attr);

	return EXIT_SUCCESS;
}



/*
 * @brief get_tty_config
 *
 *@param
 *
 *@return
 *
 * */
int32_t	get_tty_config(int32_t tty_fd, modem_serial_settings_st* settings)
{
	struct termios tty_attr = {0};
	speed_t baudrate;

	if (isatty(tty_fd) <= 0)
	{
		printf("get_tty_config not a TTY\n");
		return EXIT_FAILURE;
	}

	if ( tcgetattr ( tty_fd, &tty_attr ) != 0 )
	{
		printf("get_tty_config get not get TTY config\n");
		return EXIT_FAILURE;
	}

	baudrate = cfgetispeed(&tty_attr);

	switch (baudrate)
	{
		case B9600:
			settings->baudrate = MODEM_SERIAL_BAUD_9600;
		break;
		case B19200:
			settings->baudrate = MODEM_SERIAL_BAUD_19200;
		break;
		case B38400:
			settings->baudrate = MODEM_SERIAL_BAUD_38400;
		break;
		case B57600:
			settings->baudrate = MODEM_SERIAL_BAUD_57600;
		break;
		case B115200:
			settings->baudrate = MODEM_SERIAL_BAUD_115200;
		break;
		case B230400:
			settings->baudrate = MODEM_SERIAL_BAUD_230400;
		break;
		case B460800:
			settings->baudrate = MODEM_SERIAL_BAUD_460800;
		break;
		case B500000:
			settings->baudrate = MODEM_SERIAL_BAUD_500000;
		break;
		case B576000:
			settings->baudrate = MODEM_SERIAL_BAUD_576000;
		break;
		case B921600:
			settings->baudrate = MODEM_SERIAL_BAUD_921600;
		break;
		default:
		break;
	}

	settings->two_stop_bit_enable = (tty_attr.c_cflag & CSTOPB) != 0;

	if (0 != (tty_attr.c_cflag & PARENB))
	{
		if (0 != (tty_attr.c_cflag  & PARODD))
		{
			settings->parity_bit = MODEM_SERIAL_PARITY_ODD;
		}
		else
		{
			settings->parity_bit = MODEM_SERIAL_PARITY_EVEN;
		}
	}
	else
	{
		settings->parity_bit = MODEM_SERIAL_PARITY_NONE;
	}

	return EXIT_SUCCESS;
}



/*
 * @brief flush_serial
 *
 *@param
 *
 *@return
 *
 * */
void flush_serial(int32_t tty_fd)
{
	tcflush(tty_fd, TCIFLUSH);
}
