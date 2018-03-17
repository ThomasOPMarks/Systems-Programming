#include <iostream>
#include <string>
#include "TemplateFunction.h"
//Demo of templated functions, takes in a type and prints it out
int main() {
	
	char input[100];
	std::cout << "What type do you want? ";
	std::cin.getline(input, 100);

	if (strcmp(input, "uint8_t")) {
		ReadAndPrint<int8_t>(input);
	}
	else if(strcmp(input, "uint16_t")) {
		ReadAndPrint<int16_t>(input);
	}
	else if (strcmp(input, "uint32_t")) {
		ReadAndPrint<int32_t>(input);
	}
	else if (strcmp(input, "uint64_t")) {
		ReadAndPrint<int64_t>(input);
	}
	else {
		std::cout << "Using an int";
		ReadAndPrint<int>(input);
	}
	


}