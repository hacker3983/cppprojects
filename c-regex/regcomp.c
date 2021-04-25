// What is regcomp function?
// Regcomp is used to compile a regular expression into a form that is suitable for subsequent regexec function
#include <stdio.h>
#include <string.h>
#include <regex.h>

int main() {
	regex_t preg;
	char* regex = "[0-9]+", *string="FIND THE NUMBERS 1234 IN THIS STRING WITH REGEX";
	regmatch_t pmatch[strlen(string)];
	// compiles regex
	if(regcomp(&preg, regex, REG_EXTENDED) == 0) puts("successfully compiled regex!");
	else puts("error compiling regex!");
	// executes compile regex
	if(regexec(&preg, string, strlen(string)+1, pmatch, REG_NOTBOL) == 0) puts("successfully executed!");
	else puts("error executing");
	printf("Match found in: %d:%d\n", pmatch[0].rm_so, pmatch[0].rm_eo); // shows the match of an element
	regfree(&preg); // frees memory
	return 0;
}
