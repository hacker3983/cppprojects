# Dynamic Memory Management
 
* Lets say we have a File that we want to read from in c
* How can we read from the file without making a buffer and concating it with another buffer we can allocate memory
* Here is a Example:
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	FILE* f = fopen("stories.json", "r");
	char buff[255];
	int i=0, n=255;
	char* contents = malloc(255 * sizeof(char));
	char* ptr;
	while(fgets(buff, 255, f)) {
		n++;
		ptr = realloc(contents, n * sizeof(char));
		strcat(contents, buff);
		contents = ptr;
	}
	printf("%s\n", contents);
	free(contents);
	printf("Dynamically Allocated Memory Management Success!\n");
	return 0;
}

```
# Code
![code]("https://cdn.discordapp.com/attachments/470253814235136044/823762510804811807/unknown.png")
# Compiling and running
![compilation]("https://cdn.discordapp.com/attachments/470253814235136044/823762427874246656/unknown.png")
