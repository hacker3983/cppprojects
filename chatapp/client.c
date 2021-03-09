#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void* send_input(void* arg) {
	int sock;
	sock = (int)arg;
	char str[5000];
	while(true) {
		printf("Me>> ");
		fgets(str, 5000, stdin);
		str[strlen(str)-1] = '\0';
		send(sock, str, strlen(str), 0);
	}
}
void* receive(void* arg) {
	int sock;
	sock = (int)arg;
	char msg[5000];
	memset(msg, 5000, 0);
	while(true) {
		recv(sock, msg, 5000, 0);
		printf("\nAnother User>> %s\n", msg);
		memset(msg, 5000, 0);
	}
}

int main() {
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(5000);
	server.sin_addr.s_addr = INADDR_ANY;
	connect(sock, (struct sockaddr*)&server, sizeof(server));
	pthread_t thread_one, thread_two;
	pthread_create(&thread_one, NULL, send_input, (void*)sock);
	pthread_create(&thread_two, NULL, receive, (void*)sock);
	pthread_join(thread_one, NULL);
	pthread_join(thread_two, NULL);
	return 0;
}
