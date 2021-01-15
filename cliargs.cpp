#include <iostream>
using namespace std;

int convert_list(char** args, int size, char** mod) {
	char* arr[size];
	for (int i=0;i<size;i++) {
		arr[i] = args[i];
	}
	for (int i=0;i<size;i++) {
		mod[i] = arr[i];
	}
	return 0;
}


int main(int argc, char** argv) {
	cout << "You have entered " << argc << " arguments:" << endl;
	char* mod[argc];
	convert_list(argv, argc, mod);
	for (auto i : mod) {
		cout << i << endl;
	}
	return 0;
}
