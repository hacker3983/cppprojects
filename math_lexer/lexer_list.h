#include <string.h>
#include <stdlib.h>

typedef struct Lexlist_t {
	char* buff;
	int size;
	int malloced;
} lexer_t;

void push_back(lexer_t* list, char* buff) {
	if(list->malloced != 1) {
		list->size = 1;
		list->malloced = 1;
		list->buff = (char*)calloc(list->size, sizeof(char));
	}
	if(strlen(buff) != 0) {
		list->size += strlen(buff);
		char* ptr = (char*)calloc(list->size, sizeof(char));
		strcat(ptr, list->buff);
		strcat(ptr, buff);
		free(list->buff);
		list->buff = ptr;
	}
}
void push_c(lexer_t* list, char c) {
	if(list->malloced != 1) {
		list->size = 1;
		list->malloced = 1;
		list->buff = (char*)calloc(1, sizeof(char));
	}
	//list->buff[list->size-1] = c;
	char* ptr = calloc(list->size, sizeof(char));
	strcat(ptr, list->buff);
	ptr[list->size-1] = c;
	//list->buff[list->size-1] = c;
	list->size++;
	free(list->buff);
	list->buff = ptr;
}

void release(lexer_t* list) {
	if(list->malloced == 1) {
		list->size = 0;
		list->malloced = 0;
		free(list->buff);
	}
}
