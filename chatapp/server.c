#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

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

int main() {
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(5000);
	server.sin_addr.s_addr = INADDR_ANY;

	bind(sock, (struct sockaddr*)&server, sizeof(server));
	listen(sock, 0);
	printf("Listening\n");

	int sockc;
	struct sockaddr_in client;
	socklen_t len = sizeof(struct sockaddr_in);
	sockc = accept(sock, (struct sockaddr*)&client, &len);
	printf("Accepted connection!\n");

	pthread_t thread_one, thread_two;
	pthread_create(&thread_one, NULL, send_input, (void*)sockc);
	pthread_create(&thread_two, NULL, receive, (void*)sockc);
	pthread_join(thread_one, NULL);
	pthread_join(thread_two, NULL);
	return 0;
}
