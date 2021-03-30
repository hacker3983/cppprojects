#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

//#define red "\033[u001b[31m"
int pos;
// this is used to do the animation made it dynamically allocated so no segmentation fault
void download(char* name, char* c, int max, float delay) {
	int size = strlen(c);
	int progress = 0;char* bar = malloc(size+1 * sizeof(char));
	memset(bar, 0, size+1);
	for(int i=0;i<max;i++) {
		size += size;bar = realloc(bar, size+1 * sizeof(char));
		strcat(bar, c);progress++;
		printf("\033[%d;1H%d of %d\n", pos, progress, max);
		printf("%s - [%s]\n", name, bar);
		sleep(delay);
	}
	free(bar);
	pos+=2;
}

int main() {
	// char bar[500];
	// tasks to accomplish
	char* tasks[] = {
	"Downloading Wannacry", "Downloading Memz",
	"Downloading Slammer", "Downloading ILOVEYOU",
	"Installing Wannacry", "Installing Memz",
	"Installing Slammer", "Installing ILOVEYOU"};
	int len = sizeof(tasks)/sizeof(tasks[0]);
	printf("\033[2J"); // clears the screen
	pos = 1; // position of the cursor in the terminal
	char buff[1000];
	memset(buff, 0, 1000);
	for(int i=0;i<1000;i++) {strcat(buff, "A");}
	for(int i=0;i<len;i++) {
		download(tasks[i], "\033[31m#\033[0m", 10, 1);
	}
	//download("No More Buffer Overflow Vulnerability", buff, 10, 1);
	printf("100%% Complete\n");
	//printf("%sHello There\n", red);
	return 0;
}
