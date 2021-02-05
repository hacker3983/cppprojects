#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char** argv) {
	if(argc < 2) {
		printf("I require hostname but it is not specified\n");
		return -1;
	}
	struct hostent *he = gethostbyname(argv[1]);
	struct in_addr **addr_list = (struct in_addr **)he->h_addr_list;
	char* ip = inet_ntoa(*addr_list[0]);
	printf("%s resolved to %s\n", argv[1], ip);
	return 0;
}
