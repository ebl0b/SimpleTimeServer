#include <stdint.h>

#ifndef UTILS
#define UTILS

#define TIME_STR_SIZE	64
#define SEC_70 			(uint32_t)(70*365+17)*24*60*60
#define CONVERT70_00(x) x+SEC_70

#endif

unsigned	GetTime();
void		PrintTime(uint32_t time);