#include <time.h>
#include <string.h>
#include <stdio.h>
#include "../lib/utils.h"

uint32_t GetTime(){
	return (uint32_t)time(NULL) + SEC_70;
}

void PrintTime(uint32_t time){
	time -= SEC_70;
	time_t ttime = (time_t)time;
	struct tm* loctime = localtime(&ttime);
	char time_str[TIME_STR_SIZE];
	strftime(time_str, TIME_STR_SIZE, "%Y-%m-%d %H:%M:%S", loctime);
	printf("\nCurrent time: %s\n", time_str);
}