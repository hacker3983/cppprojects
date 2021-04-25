#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <regex.h>

bool isurl(char* string) {
	regex_t preg;
	char* pattern = "((http|https)://)[A-Za-z0-9]+\\.[A-Za-z0-9]+";
	regmatch_t pmatch[strlen(string)];
	regcomp(&preg, pattern, REG_EXTENDED);
	if(regexec(&preg, string, strlen(string)+1, pmatch, REG_NOTBOL) == 0) { regfree(&preg); return true; }
	regfree(&preg);
	return false;
}

int main(int argc, char** argv) {
	if(argc == 1) {
		puts("No arguments specified. Please specify one");
	}
	for(int i=1;i<argc;i++) {
		if(isurl(argv[i])) printf("%s is a valid url\n", argv[i]);
		else printf("%s is not a valid url\n", argv[i]);
	}
	return 0;
}
