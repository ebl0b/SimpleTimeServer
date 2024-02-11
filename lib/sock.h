#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifndef SOCK
#define SOCK

#define SERV_IPV4		inet_addr("127.0.0.1")
#define PORT			8080
#define REQ_SIZE		1
#define MES_SIZE		128

typedef struct sockaddr_in	sockaddr_in;
typedef struct sockaddr_in	sockaddr;

#endif

int		CreateSocket	(int family, int sock_type);
void	InitAddr		(sockaddr_in* addr, int family, int port, int IPv4_addr);
void	BindSocket		(int socket_id, sockaddr_in* addr, int addrlen);
int		ReceiveMes		(int sock_id, char* buffer, int buf_size, int flag, sockaddr_in* addr, int* addrlen);
void	sendMes			(int sock_id, char* buffer, int buf_size, int flag, sockaddr_in* addr, int* addrlen);
