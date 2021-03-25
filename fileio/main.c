#include <stdio.h>
#include "fileio.h"

int main() {
	FILE* f = open("secret.txt", "r");
	if(f == NULL) {
		return 1;
	}
	printf("%s", read(f));
	write(f, "Test");
	close(f);
	return 0;
}
