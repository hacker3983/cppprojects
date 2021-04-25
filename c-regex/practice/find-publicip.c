#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

char* find_ipv4(char* string) {
	regex_t preg;
	char* pattern = "([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})",
	str[16], *ip = (char*)malloc(16*sizeof(char));
	regmatch_t pmatch[strlen(string)];
	regcomp(&preg, pattern, REG_EXTENDED); // compile regular expression
	// excute expression
	if(regexec(&preg, string, strlen(string)+1, pmatch, REG_NOTBOL) == 0) puts("sucessfully executed");
	else { puts("failed to execute"); regfree(&preg); exit(0); }
	printf("Match found in %d:%d\n", pmatch[0].rm_so, pmatch[0].rm_eo);
	memset(str, 0, 16);
	for(int i=pmatch[0].rm_so;i<pmatch[0].rm_eo;i++) { int index = strlen(str)+1; str[index-1] = string[i]; }
	strcpy(ip, str);
	regfree(&preg); // frees some memory
	return ip;
}

int main() {
	int sock = socket(AF_INET, SOCK_STREAM, 0); // creates a socke connection
	struct sockaddr_in server;
	struct hostent* he = gethostbyname("api.ipify.org"); // get the ip address of the server
	struct in_addr** addr_list;
	if(he == NULL) { puts("Failed to resolve ip. Please check your connection!"); return 0; }
	char* header="GET / HTTP/1.1\r\nHost: api.ipify.org\r\n\r\n", buff[500];
	addr_list = (struct in_addr**)he->h_addr_list; // puts the ip address of the server in a unique format
	server.sin_family = AF_INET;
	server.sin_port = htons(80);
	server.sin_addr.s_addr = inet_addr(inet_ntoa(*addr_list[0])); // ip address of the server
	connect(sock, (struct sockaddr*)&server, sizeof(server)); // connect to the server
	send(sock, header, strlen(header), 0); // send http header to the server
	recv(sock, buff, 500, 0); // receives data from the server
	close(sock); // disconnect from the server
	char* ip = find_ipv4(buff); // our public ip address
	printf("Match is %s\n", ip);
	free(ip); // frees the buffer that has been allocated
	//puts(buff);
	return 0;
}
