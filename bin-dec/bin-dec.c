#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* input(char* prompt) {
	char* buff = calloc(1, sizeof(char*)), c;
	printf("%s", prompt);
	size_t size = 0;
	while((c = fgetc(stdin))) {
		if(c == '\n') break;
		buff[size] = c;
		size++;
		char* temp = buff;
		buff = calloc(size+1, sizeof(char*));
		strcpy(buff, temp);
		free(temp);
	}
	return buff;
}

signed long long int parse_calculate(char* num) {
	int pos=strlen(num)-1, i=0;
	signed long long int sum = 0;
	while(num[i] != '\0') {
		if(num[i] == '1' || num[i] == '0') {
			sum += (num[pos] - '0') * pow(2, i);
			i++;
		} else {
			printf("Invalid binary number %s\n", num);
			return -1;
		}
		pos--;
	}
	return sum;
}

int main() {
	while(1) {
		char* binary = input("Enter the binary number to convert: ");
		signed long long int dec = parse_calculate(binary);
		if(dec != -1) {
			printf("%s in binary is %lld\n", binary, dec);
		}
		free(binary);
	}
	return 0;
}
