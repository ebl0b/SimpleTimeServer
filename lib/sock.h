#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#ifndef SOCK
#define SOCK

#define SERV_IPV4		inet_addr("127.0.0.1")
#define PORT			8080
#define REQ_SIZE		1
#define RES_SIZE		sizeof(time_t)

typedef struct sockaddr_in	sockaddr_in;
typedef struct sockaddr	sockaddr;

#endif

int		CreateSocket	(int family, int sock_type);
void	InitAddr		(sockaddr_in* addr, int family, int port, int IPv4_addr);
void	BindSocket		(int socket_id, sockaddr_in* addr, int addrlen);
int		ReceiveMes		(int sock_id, void* buffer, int buf_size, int flag, sockaddr_in* addr, int* addrlen);
void	SendMes			(int sock_id, void* buffer, int buf_size, int flag, sockaddr_in* addr, int addrlen);
