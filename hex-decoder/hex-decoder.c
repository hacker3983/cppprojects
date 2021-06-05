#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "list/char.h"
#include "list/list.h"

struct hex {
	char c;
	int digit;
};

int hex_getval(struct hex* hex, char c) {
	for(int i=0;i<16;i++) {
		if(hex[i].c == tolower(c)) {
			return hex[i].digit;
		}
	}
	return -1;
}

int main(int argc, char** argv) {
	struct list values[argc-1];
	struct hex hex[16] =
	{
		{'0', 0x0}, {'1', 0x1}, {'2', 0x2}, {'3', 0x3},
		{'4', 0x4}, {'5', 0x5}, {'6', 0x6}, {'7', 0x7},
		{'8', 0x8}, {'9', 0x9}, {'a', 0xA}, {'b', 0xB},
		{'c', 0xC}, {'d', 0xD}, {'e', 0xE}, {'f', 0xF}
	};
	for(int i=1;i<argc;i++) {
		set(&values[i-1]);
		int pos = 0;
		for(int x=strlen(argv[i])-1;x>=0;x--) {
			int val = hex_getval(hex, argv[i][x]);
			if(val != -1) {
				int exp = pow(16, pos);
				append(&values[i-1], val*exp);
				pos++;
			}
		}
		int sum = 0;
		for(int j=0;j<values[i-1].size;j++) {
			sum += values[i-1].arr[j];
		}
		printf("%s:%d\n", argv[i], sum);
		release(&values[i-1]);
	}
	return 0;
}
