#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	FILE* f = fopen("stories.json", "r");
	char buff[255];
	int i=0, n=255;
	char* contents = malloc(255 * sizeof(char));
	char* ptr;
	while(fgets(buff, 255, f)) {
		n++;
		ptr = realloc(contents, n * sizeof(char));
		strcat(contents, buff);
		contents = ptr;
	}
	printf("%s\n", contents);
	free(contents);
	printf("Dynamically Allocated Memory Management Success!\n");
	return 0;
}
