#include <time.h>
#include <string.h>
#include <stdio.h>
#include "../lib/utils.h"

unsigned GetTime(){
	return (unsigned)time(NULL);
}

void PrintTime(time_t time){
	struct tm* loctime = localtime(&time);
	char time_str[TIME_STR_SIZE];
	strftime(time_str, TIME_STR_SIZE, "%Y-%m-%d %H:%M:%S", loctime);
	printf("\nCurrent time: %s\n", time_str);
}