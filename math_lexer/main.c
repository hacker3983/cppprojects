#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "banner.h"
#include "lexer.h"
int main() {
	lexer_t list;
	char* input;
	print_banner();
	printf("Please Enter your mathematical expression: ");
	scanf("%m[^\n]", &input);
	list = tokenize(input);
	printf("%s\n", list.buff);
	release(&list);
	free(input);
	return 0;
}
