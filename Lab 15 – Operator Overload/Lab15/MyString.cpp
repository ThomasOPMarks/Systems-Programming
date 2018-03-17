#include "MyString.h"
#include <cstring>
MyString::MyString()
{
	
	this->string = new char[1];
	this->string[0] = '\0';
}

MyString::MyString(const MyString &a)
{
	char* temp = new char[(a.length()) + 1];
	for (int i = 0; i <= (a.length()); i++) {
		temp[i] = a.string[i];
	}
	this->string = temp;
}

MyString::MyString(const char *f)
{
	char* temp = const_cast<char*> (f);
	this->string = new char[strlen(temp) + 1];
	int i = 0;
	while (*temp) {
		this->string[i] = *temp;
		i++;
		temp++;
	}
	this->string[i] = '\0';

}

MyString::~MyString()
{
	delete[] (this->string);
	this->string = NULL;
}

MyString & MyString::operator=(const MyString &a)
{
	if (this != &a) {
		delete[](this->string);
		this->string = new char[strlen(a.string) + 1];
		for (int i = 0; i < strlen(a.string) + 1; i++) {
			this->string[i] = a.string[i];
		}
		
	}
	return *this;
}

MyString & MyString::operator+=(const MyString &s)
{

	
	char* newString = new char[length() + s.length() + 1];
	int index = 0;
 	for (int i = 0; i < length(); i++) {
		newString[index] = string[i];
		index++;
	}
	for (int j = 0; j < s.length(); j++) {
		newString[index] = s.string[j];
		index++;
	}
	newString[index] = '\0';
	delete[] this->string;
	this->string = newString;
	return *this;
}

char MyString::operator[](size_t i) const
{
	
	return string[i];
}

char & MyString::operator[](size_t i)
{
	return string[i];
}

size_t MyString::length() const
{
	return strlen(string);
}

const char * MyString::cString() const
{
	return string;
}

MyString operator+(const MyString & s1, const MyString & s2)
{
	MyString temp(s1);
	MyString temp2(s2);
	temp += temp2;
	return temp;
}

std::ostream & operator<<(std::ostream & os, const MyString & s)
{
	os << s.cString();
	return os;
}
