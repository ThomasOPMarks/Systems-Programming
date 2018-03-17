#pragma once
#include <iostream>
template <typename T>
//Takes in a string, and puts the input of the string into the type of the template 
void ReadAndPrint(char* s) {
	std::cout << "Please input a " << s << "\n";
	T variable;
	std::cin >> variable;
	std::cout << "Value in decimal: " << std::dec << variable << std::endl;
	std::cout << "Value in hex: " << std::hex << variable << std::endl;

}