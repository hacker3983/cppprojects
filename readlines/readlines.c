#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

void help(char* bin) {
	printf("usage: %s [-h] [-c CHARS] [-l LINES]\n\n"
	"Print the newline and character counts in a specified file.\n\n"
	"optional arguments:\n"
	"  -h, --help            show this help message and exit\n"
	"  -c CHARS, --chars CHARS\n"
	"                        Print the character counts\n"
	"  -l LINES, --lines LINES\n"
	"                        Print the newline counts\n", bin);
}
void countl(char* file) {
	FILE *f = fopen(file, "r");
	int lines = 0;
	char buffer[5000*500];
	while(fgets(buffer, 5000*500, f)) {
		lines++;
	}
	printf("%d %s\n", lines, file);
	fclose(f);
}
void countc(char* file) {
	FILE *f = fopen(file, "r");
	int count = 0;
	char buffer[1];
	while(fgetc(f) != EOF) {
		count++;
	}
	printf("%d %s\n", count, file);
	fclose(f);
}
int main(int argc, char** argv) {
	if(argc < 2) {
		help(argv[0]);
		return 1;
	}
	int it=0;
	bool listen = false;
	char* opt_args[2];
	for(int i=0;i<argc;i++) {
		if(listen == true) {
			opt_args[it] = argv[i];
			it = 0;
			break;
		} else if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
			help(argv[0]);
			break;
		} else if(strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--chars") == 0) {
			if(argc < 3) {
				printf("Please Specify a file -c/--chars <FILE>\n");
				return 1;
			}
			opt_args[it] = argv[i];
			listen = true;
			it++;
		} else if(strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--lines") == 0) {
			if(argc < 3) {
				printf("Please Specify a file -l/--lines <FILE>\n");
				return 1;
			}
			opt_args[it] = argv[i];
			listen = true;
			it++;
		}
	}

	if(strcmp(opt_args[0], "-c") == 0 || strcmp(opt_args[0], "--chars") == 0 && access(opt_args[1], X_OK))
		countc(opt_args[1]);
	else if(strcmp(opt_args[0], "-l") == 0 || strcmp(opt_args[0], "--lines") == 0 && access(opt_args[1], X_OK))
		countl(opt_args[1]);
	return 0;
}
