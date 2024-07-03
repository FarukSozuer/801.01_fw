/**
 ******************************************************************************
  * @file		: ZED_spi.c
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


#ifndef SRC_MISC_TIMING_H_
#define SRC_MISC_TIMING_H_

#include <stdio.h>
#include <string.h>
#include <stdint.h>

// call this function to start a nanosecond-resolution timer
struct timespec timer_start();
// call this function to end a timer, returning nanoseconds elapsed as a long
uint64_t timer_end(struct timespec start_time);
uint64_t timer_get_ns(struct timespec* timer);
uint64_t timer_get_us(struct timespec* timer);
uint64_t timer_get_ms(struct timespec* timer);
uint64_t get_systime_ms();

#endif /* SRC_MISC_TIMING_H_ */
