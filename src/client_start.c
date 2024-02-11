//Client
#include "sock.h"
#include "utils.h"
#include "proc_req.h"

void main(void){
	int		c_sock;
	char		buffer[BUFFER_SIZE];
	const char	sig = '1';
	char*		request = sig;
	sockaddr_in	s_addr, c_addr;
	socklen_t	s_addrlen = sizeof(c_addr);

	c_sock = CreateSocket();
	memset(&c_addr, 0, sizeof(c_addr));
	memset(&s_addr, 0, sizeof(s_addr));
	InitAddr(&c_addr);	
	
	for(;;){
		SendMes(request);
		ReceiveMes(buffer);
		PrintMes();
	}
}
