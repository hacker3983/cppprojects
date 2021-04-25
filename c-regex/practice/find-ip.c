#include <stdio.h>
#include <regex.h>
#include <string.h>

int main() {
	regex_t preg;
	char* regex="[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}", *string="IP ADDRESS: 192.168.1.1";
	regmatch_t pmatch[strlen(string)];
	char ip[16];
	memset(ip, 0, 16);
	if(regcomp(&preg, regex, REG_EXTENDED) == 0) puts("successfully compiled regex!");
	if(regexec(&preg, string, strlen(string)+1, pmatch, REG_NOTBOL) == 0) puts("sucessfully executed");
	printf("Match found in %d:%d\n", pmatch[0].rm_so, pmatch[0].rm_eo);
	for(int i=pmatch[0].rm_so;i<pmatch[0].rm_eo;i++) {
		int index = strlen(ip)+1;
		ip[index-1] = string[i];
	}
	puts(ip);
	regfree(&preg);
	return 0;
}
