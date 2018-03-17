#include <iostream>
#include "MyString.h"

int main(int argc, const char * argv[])
{
	//Testing of the MyString Class

	//Default constructor 
	MyString s;
	std::cout << "Empty: '" << s.cString() << "'\n";
	//Assingment operator
	s = "hello";
	std::cout << "After operator=: '" << s.cString() << "'\n";
	{
		//Copy constructor 
		MyString t(s);
		std::cout << "After copy: '" << t.cString() << "'\n";
		s = t;
	}

	MyString m(" world");
	std::cout << "After constructor: '" << m.cString() << "'\n";
	m = s;
	std::cout << "After operator=: '" << m.cString() << "'\n";
	m = m;
	std::cout << "After operator=: '" << m.cString() << "'\n";


	//Heap testing for default, from a string, operator=, and copy constructor
	MyString* q = new MyString;
	std::cout << "Empty Heap String: '" <<  q->cString() << "'\n";

	MyString* p = new MyString("hi");

	*q = *p;
	std::cout << "After operator=: '" << q->cString() << "'\n";

	MyString* z = new MyString(s);

	std::cout << "After copy: '" << z->cString() << "'\n";

	delete z;
	z = NULL;
	delete p;
	p = NULL;
	delete q;
	q = NULL;

	return 0;
}