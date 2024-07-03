/**
 ******************************************************************************
  * @file		: ZED_uio.c
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


#include "zed_uio.h"

#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int32_t* uio_device_init(const char * device_name, const uint32_t mmap_size)
{
    int32_t uio_fd = 0;
    int32_t* ptr = NULL;

    if(!device_name)
        return NULL;

    // Open uio device
    uio_fd = open(device_name, O_RDWR);
    if(uio_fd < 0)
        return NULL;

    // Mmap memory region containing counters value
    ptr = (int32_t*)mmap(NULL, mmap_size, PROT_READ | PROT_WRITE, MAP_SHARED, uio_fd, 0);
    if(ptr == MAP_FAILED)
    {
        close(uio_fd);
        return NULL;
    }

    return ptr;
}

int32_t uio_device_read(const uint32_t* base, const uint32_t offset, uint32_t* value)
{
    if (!base)
        return -1;

    *value = *(base + (uint32_t)(offset / sizeof (uint32_t)));

    return 0;
}

int32_t uio_device_write(uint32_t* base, const uint32_t offset, const uint32_t value)
{
    if (!base)
        return -1;

    *(base + (uint32_t)(offset / sizeof (uint32_t))) = value;

    return 0;
}
