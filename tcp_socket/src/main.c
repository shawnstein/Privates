/*
git add * && git commit -m "Kommentar" && git push origin master
cc tcp_socket/src/main.c -std=c99 -g -o tcp_socket/bin/a.out && ./tcp_socket/bin/a.out
cc tcp_socket/src/main.c -std=c99 -g -o tcp_socket/bin/a.out && gdb ./tcp_socket/bin/a.out

*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct sockaddr_in {
	uint8_t 		sin_len;
	sa_family_t		sin_family;
	in_port_t		sin_port;
	struct in_addr	sin_addr;
	char			sin_zero[];
};

struct in_addr {
	in_addr_t 		s_addr;
};

int connect(int sockfd, struct sockaddr *address, socklen_t adress_length);

int main() {
	struct sockaddr__in addr;
	memset(&addr, 0, sizeof(addr));

	return 0;
}