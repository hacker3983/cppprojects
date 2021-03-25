#include <stdio.h>
#include <stdlib.h>

// opens a file
FILE* open(char* filename, char* mode) {
	FILE* f = fopen(filename, mode);
	if(f == NULL) {
		printf("%s: No such file or directory Or Invalid mode: '%s'\n", filename, mode);
	}
	return f;
}
// reads from a file
char* read(FILE* f) {
	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	char* buff = malloc(size * sizeof(char));
	rewind(f);
	if(fread(buff, size, 1, f) == 0) {
		puts("ReadError: not readable");
		exit(0);
	}
	return buff;
}
// writes to a file
int write(FILE* f, const char* ptr) {
	int len=0;
	while(ptr[len] != '\0') {len++;}
	if(fprintf(f, ptr, len) < 0) {
		puts("WriteError: not writeable");
		exit(0);
	}
	return 0;
}
// closes a file
void close(FILE* f) {
	fclose(f);
}
