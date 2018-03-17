#pragma once
class MyString {
public:
	MyString();
	MyString(const MyString &);
	MyString(const char *);
	~MyString();
	MyString &operator=(const MyString &);
	size_t length() const;
	const char *cString() const;
private:
	char *string;
};