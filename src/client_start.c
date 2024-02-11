//Client
#include "sock.h"
#include "utils.h"
#include "proc_req.h"
#include <string.h>

void main(void){
	int				c_sock;
	char			buffer[REQ_SIZE];
	const char		sig = '1';
	char*			request = sig;
	sockaddr_in		s_addr, c_addr;
	socklen_t		s_addrlen = sizeof(s_addr);
	socklen_t		c_addrlen = sizeof(c_addr);

	c_sock = CreateSocket(AF_INET, SOCK_DGRAM);
	memset(&c_addr, 0, sizeof(c_addr));
	memset(&s_addr, 0, sizeof(s_addr));
	InitAddr(&s_addr, AF_INET, PORT, SERV_IPV4);
	BindSocket(c_sock, c_addr, );	
	
	SendMes(request);
	ReceiveMes(buffer);
	PrintMes();

}
