#include "lexer_list.h"

int pos, sourceLength;
bool isnumber(char* number) {
	if(strlen(number) == 0) { return false; }
	for(int i=0;i<strlen(number);i++) { if(isdigit(number[i]) || number[i] == '.') { i++; } else { return false; } }
	return true;
}
char* getnumber(lexer_t* list, char* source) {
	int digit = 0, dots_count = 0;
	while(isdigit(source[pos])) { push_c(list, source[pos]); pos++; }
	if(source[pos] == '.') {
		for(int i=pos;i<sourceLength;i++) {
			if(ispunct(source[i]) && source[i] != '.') { break; }
			else {
				if(isdigit(source[i])) { push_c(list, source[i]); }
				else if(source[i] == '.') { push_c(list, source[i]); }
				else { break; }
				pos++;
			}
		}
	}
	for(int i=0;i<strlen(list->buff);i++) {
		if(list->buff[i] == '.') { dots_count++; }
	}
	if(dots_count > 1) { return NULL; }
	if(isnumber(list->buff)) { return list->buff; }
	return NULL;
}
lexer_t tokenize(char* source) {
	pos = 0; sourceLength = strlen(source);
	lexer_t list[2];
	while(pos < sourceLength) {
		char* number = getnumber(&list[1], source);
		if(number != NULL) {
			push_back(&list[0], "Number:");
			push_back(&list[0], number);
			push_back(&list[0], "\n");
		} else {
			if(isalpha(source[pos])) {
				push_back(&list[0], "Invalid token:'");
				for(int i=pos;i<sourceLength;i++) { push_c(&list[0], source[pos]); pos++; }
				if(!isalpha(source[pos])) { pos--; }
				push_back(&list[0], "'\n");
			}
		}
		release(&list[1]);
		switch(source[pos]) {
			case '+': push_back(&list[0], "Operator: PLUS, +\n"); break;
			case '-': push_back(&list[0], "Operator: SUB, -\n"); break;
			case '/': push_back(&list[0], "Operator: DIV, /\n"); break;
			case '*': push_back(&list[0], "Operator: MUL, *\n"); break;
		}
		pos++;
	}
	return list[0];
}
