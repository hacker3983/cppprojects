#include <iostream>
#include <typeinfo>
using namespace std;
template <class any>
int len(any (&arr)) {
	int length = 0;
	if (typeid(arr[0]).name() == typeid(char).name()) {
		for (auto i : arr) {
			length++;
		}
		length--;
	} else {
		for (size_t i=0;i<sizeof(arr)/sizeof(arr[0]);i++) {
			length++;
		}
	}
	/*for (auto i : arr) {
		cout << i << endl;
	}*/
	return length;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	string hello[] = {"Hello", "World", "Python", "Is", "The", "Best"};
	cout << len(arr) << endl;
	cout << len(hello) << endl;
	cout << len("Hello World") << endl;
	return 0;
}
