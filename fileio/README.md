# Fileio
* Fileio is a library used to make files in c more easier

# Raw code Examples:
```c
#include <stdio.h>
#include "fileio.h"

int main() {
	FILE* f = open("employees.txt", "w"); // open the file
	write(f, "Jim, Salesman\nPam, Receptionist\nOscar, Accounting"); // writes to file
	close(f); // close the file
	return 0;
}
```


# Examples:

![code](https://cdn.discordapp.com/attachments/709031059593101413/824458614944038953/unknown.png)
![run](https://cdn.discordapp.com/attachments/709031059593101413/824459075466035220/unknown.png)
