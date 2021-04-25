#include <stdio.h>
#include <regex.h>
#include <string.h>

int main() {
	regex_t preg;
	char* regex="[0-9]+", *string = "FIND THE NUMBER IN THIS STRING \"1234\" USING REGULAR EXPRESSIONS";
	regmatch_t pmatch[strlen(string)];
	if(regcomp(&preg, regex, REG_EXTENDED) == 0) puts("sucessfully compiled regex!");
	else puts("error compiling regex!");
	if(regexec(&preg, string, strlen(string)+1, pmatch, REG_NOTBOL) == 0) puts("successfully executed!");
	else puts("error executing");
	printf("Match found in %d:%d\n", pmatch[0].rm_so, pmatch[0].rm_eo);
	printf("Match in \"%s\" is ", string);
	for(int i=pmatch[0].rm_so;i<pmatch[0].rm_eo;i++) printf("%c", string[i]);
	puts("");
	regfree(&preg);
	return 0;
}
