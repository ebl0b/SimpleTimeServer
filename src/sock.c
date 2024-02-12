#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "../lib/sock.h"

int CreateSocket(int family, int sock_type){
	int sock_id;
	if ((sock_id = socket(family, sock_type, 0)) < 0){
		perror("Socket");
		exit(EXIT_FAILURE);
	}
	return sock_id;
}

void InitAddr(sockaddr_in* addr, int family, int port, int IPv4_addr){
	addr->sin_family = family;
	addr->sin_port = htons(port);
	addr->sin_addr.s_addr = IPv4_addr;
}

void BindSocket(int socket_id, sockaddr_in* addr, int addrlen){
	if (bind(socket_id, (const sockaddr*)addr, addrlen) < 0){
		perror("Bind");
		exit(EXIT_FAILURE);
	}
}

int ReceiveMes(int sock_id, void* buffer, int buf_size, int flag, sockaddr_in* addr, int* addrlen){
	int n;
	if ((n = recvfrom(sock_id, buffer, buf_size, flag, (sockaddr*)addr, addrlen)) == -1){
		perror("Receive");
		exit(EXIT_FAILURE);
	}
	return n;
}

void SendMes(int sock_id, void* buffer, int buf_size, int flag, sockaddr_in* addr, int addrlen){
if ((sendto(sock_id, buffer, buf_size, flag, (sockaddr*)addr, addrlen)) == -1){
		perror("Send");
		exit(EXIT_FAILURE);
	}
}
