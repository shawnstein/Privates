/*
tcp_socket by shawnstein


git add * && git commit -m "Kommentar" && git push origin master
cc tcp_socket/src/main.c -std=c99 -g -o tcp_socket/bin/a.out && ./tcp_socket/bin/a.out
cc tcp_socket/src/main.c -std=c99 -g -o tcp_socket/bin/a.out && gdb ./tcp_socket/bin/a.out

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdint.h>

typedef uint8_t u_int

int connect(int sockfd, struct sockaddr *address, socklen_t adress_length);

int main() {
	struct sockaddr__in addr;
	memset(&addr, 0, sizeof(addr));

	return 0;
}