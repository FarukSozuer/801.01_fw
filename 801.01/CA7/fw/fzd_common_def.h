#ifndef UMFA_COMMON_DEF_H_
#define UMFA_COMMON_DEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread.h>

typedef void *(*THREAD_FUNCTION_T)(void *pArg);

typedef struct _THREAD_ATTR_
{
    char *nName;
	THREAD_FUNCTION_T nThreadFunction;
    uint64_t nSysThreadID;
    uint8_t nThreadID;
	uint8_t nSetCPU;
	uint8_t nCPUID;
	uint8_t nSetPri;
	int nPolicy;
	struct sched_param nParam;
}S_THREAD_ATTR, *PS_THREAD_ATTR;

typedef enum
{
    THREAD_RFLINK_ID,
	THREAD_CONFIG_SERIAL,
	THREAD_DATA_SERIAL,
	THREAD_CLI_SERIAL,
    THREAD_MAIN_LOOP_ID,
    TOTAL_NUMBER_OF_THREAD
}ps_thread_type;

void set_schedular_info(PS_THREAD_ATTR pThreadAttr);

#endif // UMFA_COMMON_DEF_H_
