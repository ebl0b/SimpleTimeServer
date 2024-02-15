//Client
#include "../lib/sock.h"
#include "../lib/utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	if(argc!=3){
		puts("./cli <IPv4> <port>");
		exit(EXIT_FAILURE);
	}
	const int		serv_IPv4 = inet_addr(argv[1]);
	const int		port = atoi(argv[2]);
	int				cli_sock;
	uint32_t		time;
	sockaddr_in		serv_addr;
	socklen_t		serv_addrlen = sizeof(serv_addr);

	cli_sock = CreateSocket(AF_INET, SOCK_DGRAM);
	memset(&serv_addr, 0, sizeof(serv_addr));
	InitAddr(&serv_addr, AF_INET, port, serv_IPv4);	
	
	SendMes(cli_sock, NULL, 0, 0, &serv_addr, serv_addrlen);
	ReceiveMes(cli_sock, &time, RES_SIZE, MSG_WAITALL, NULL, NULL);
	time = ntohl(time);
	PrintTime(time);

	return 0;
}
