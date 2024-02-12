#include <time.h>
#include <string.h>
#include "../lib/utils.h"

unsigned GetTime(){
	return (unsigned)time(NULL);
}

void PrintTime(int time){
	struct tm* loctime = localtime(&time);
	char time_str[TIME_STR_SIZE];
	strftime(time_str, TIME_STR_SIZE);
	printf("\nCurrent time: %s\n", time_str);
}