/**
 ******************************************************************************
  * @file		: ZED_rflink.h
  * @brief		: Task scheduler source file
  *				  This file contains task structure of the application
  * @author		: Faruk Sozuer
  * @date		: 20.04.2024
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

#include "zed_common_def.h"
#include "zed_cpu_info.h"
#include "zed_uart.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/gpio.h>
#include "zed_rflink.h"
#include "fzd_stpmic1.h"

int64_t temp;
int32_t fd_gpio;
int32_t ret;
uint32_t counter;

/*
 * @brief
 *
 * @param
 *
 * @return
 * */
void* rflinkLoop(void* args)
{
	set_schedular_info((PS_THREAD_ATTR)args);

	char chrdev_name[20];

	strcpy(chrdev_name, "/dev/gpiochip0");

	/*  Open device: gpiochip0 for GPIO bank A */
	fd_gpio = open(chrdev_name, 0);

	while(1)
	{
		counter++;

		printf("RF Link Thread %5.2f 0x%x\r\n",get_used_cpu(),read_stpmicVersion());
		sleep(1);
	}
}
