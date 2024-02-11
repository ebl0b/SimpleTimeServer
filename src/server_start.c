//Server
#include "sock.h"
#include "utils.h"
#include "proc_req.h"
#include <string.h>

void main(void){
	int				s_sock;			
	char			buffer[REQ_SIZE];
	char			response[RES_SIZE];	
	sockaddr_in		s_addr, c_addr;		
	socklen_t		s_addrlen = sizeof(s_addr);	
	socklen_t		c_addrlen = sizeof(c_addr);
	
	s_sock = CreateSocket(AF_INET, SOCK_DGRAM);
	memset(&s_addr, 0, sizeof(s_addr));
	memset(&c_addr, 0, sizeof(c_addr));
	InitAddr(&s_addr, AF_INET, PORT, INADDR_ANY);
	BindSocket(s_sock, s_addr, s_addrlen);

	for(;;){
		ReceiveMes(s_sock, buffer, REQ_SIZE, MSG_WAITALL, &c_addr, c_addrlen);
		GenerateRes(reponse);
		SendMes(s_sock, response, RES_SIZE, 0, &c_addr, c_addrlen);
	}
}
