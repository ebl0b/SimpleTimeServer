//Server
#include "sock.h"
#include "utils.h"
#include "proc_req.h"
#include <string.h>

void main(void){
	int		s_sock;			
	char		buffer[1];
	char		response[BUFFER_SIZE];	
	sockaddr_in	s_addr, c_addr;		
	socklen_t	s_addrlen = sizeof(s_addr);	
	
	s_sock = CreateSocket();
	memset(&s_addr, 0, sizeof(s_addr));
	memset(&c_addr, 0, sizeof(c_addr));
	InitAddr(&s_addr);
	BindSocket();

	for(;;){
		ReceiveMes(buffer);
		GenerateRes(reponse);
		SendMes(response);
	}
}
