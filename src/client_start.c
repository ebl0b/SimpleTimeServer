//Client
#include "../lib/sock.h"
#include "../lib/utils.h"
#include <string.h>

int main(void){
	int				cli_sock;
	uint32_t		time;
	sockaddr_in		serv_addr;
	socklen_t		serv_addrlen = sizeof(serv_addr);

	cli_sock = CreateSocket(AF_INET, SOCK_DGRAM);
	memset(&serv_addr, 0, sizeof(serv_addr));
	InitAddr(&serv_addr, AF_INET, PORT, SERV_IPV4);	
	
	SendMes(cli_sock, NULL, 0, 0, &serv_addr, serv_addrlen);
	ReceiveMes(cli_sock, &time, RES_SIZE, MSG_WAITALL, NULL, NULL);
	time = ntohl(time);
	PrintTime(time);

	return 0;
}
