#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int CreateSocket(){
	int sock_id;
	if ((sock_id = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror(Socket);
		exit(EXIT_FAILURE);
	}
	return sock_id;
}

void InitServAddr(sockaddr_in* s_addr){

}

void InitCliAddr(sockaddr_in* c_addr){

}
