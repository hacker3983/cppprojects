#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Properties { char* name; int age; } Properties;
Properties props;
struct Person {
	void (*setproperties) (char* name, int age);
	Properties (*getproperties) ();
};
void setproperties(char* name, int age) {
	props.age = age;
	props.name = malloc(strlen(name)*sizeof(char));
	strcpy(props.name, name);
}
Properties getproperties() { return props; }
void init_properties(struct Person* person) {
	person->setproperties = setproperties;
	person->getproperties = getproperties;
}
int main() {
	struct Person person;
	init_properties(&person);
	person.setproperties("Katara", 21);
	Properties props = person.getproperties();
	printf("Name:%s\nAge:%d\n", props.name, props.age);
	free(props.name);
	return 0;
}
