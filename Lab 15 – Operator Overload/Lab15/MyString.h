#pragma once
#include <iostream>
class MyString {
public:
	MyString();
	MyString(const MyString &);
	MyString(const char *);
	~MyString();
	//Added the operators below
	MyString &operator=(const MyString &);
	//Adds the second string to the first
	MyString &operator+=(const MyString &);
	//Returns the character at the index, and can update it 
	char operator[](size_t i) const;
	char &operator[](size_t i);
	size_t length() const;
	const char *cString() const;
private:
	char *string;
};

MyString operator+(const MyString &s1, const MyString &s2);

std::ostream& operator<<(std::ostream& os, const MyString& s);
