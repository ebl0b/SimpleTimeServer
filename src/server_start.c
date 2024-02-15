//Server
#include "../lib/sock.h"
#include "../lib/utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void main(int argc, char const *argv[]){
	if(argc!=2){
		puts("./serv <port>");
		exit(EXIT_FAILURE);
	}
	int				port = atoi(argv[1]);
	int				serv_sock;			
	uint32_t		time;	
	sockaddr_in		bind_addr, cli_addr;		
	socklen_t		bind_addrlen = sizeof(bind_addr);	
	socklen_t		cli_addrlen = sizeof(cli_addr);
	
	serv_sock = CreateSocket(AF_INET, SOCK_DGRAM);
	memset(&bind_addr, 0, sizeof(bind_addr));
	memset(&cli_addr, 0, sizeof(cli_addr));
	InitAddr(&bind_addr, AF_INET, port, INADDR_ANY);
	BindSocket(serv_sock, &bind_addr, bind_addrlen);

	for(;;){
		ReceiveMes(serv_sock, NULL, 0, MSG_WAITALL, &cli_addr, &cli_addrlen);
		time = htonl(GetTime());
		SendMes(serv_sock, &time, RES_SIZE, 0, &cli_addr, cli_addrlen);
	}
}
