/**
 ******************************************************************************
  * @file		: ZED_serial_com.h
  * @brief		: Task scheduler source file
  *				  This file contains task structure of the application
  * @author		: Faruk Sozuer
  * @date		: 25.04.2024
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

#ifndef FZD_SERIAL_COM_H_
#define FZD_SERIAL_COM_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>

#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/time.h>

#include <sys/socket.h>
#include <linux/can.h>
#include <linux/if.h>

#include <dirent.h>
#include <netinet/tcp.h>

#include <fcntl.h>
#include <sys/epoll.h>

void* readDataSerialPort(void *args);
void* readConfigSerialPort(void *args);
void* readCliSerialPort(void *args);

#endif /* SRC_FZD_SERIAL_COM_H_ */
