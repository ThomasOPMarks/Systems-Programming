#include <iostream>
#pragma warning(disable : 4996)
void stackOverflow();
char* reverse(char* s);
using namespace std;
//reversing a c string, as well writing a function that results in a stack overflow
int main() {
	stackOverflow();
	char a[] = "isthisfunbackwards";

	char* rev = reverse(a);
	cout << rev << "\n";
	delete[] rev;

	return 0;
}
//Here's a simple function that results in a stack overflow
void stackOverflow() {
	
	stackOverflow();
}
//function that returns a new, reversed string.
char* reverse(char* s) {
	char* rs = new char[strlen(s) + 1];
	for (int i = 0; i < strlen(s); i++) {
		rs[strlen(s) - i - 1] = s[i];
	}
	rs[strlen(s)] = '\0';
	return rs;
}