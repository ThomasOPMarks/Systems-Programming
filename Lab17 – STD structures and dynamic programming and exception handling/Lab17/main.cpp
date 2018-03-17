#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>
using std::cout;
uint64_t fibCalc(int n, std::vector<uint64_t> vector);
int main() {
	std::vector<uint64_t> fib;
	fib.push_back(0);
	fib.push_back(1);
	fib.push_back(1);

	std::unordered_map<uint64_t, int> fibMap;
	fibMap[1] = 2;
	//calculate for the first 93 numbers (otherwise it's too big)
	for (int i = 3; i < 94; i++) {
		fib.push_back(fibCalc(i, fib));
	}
	for (int i = 3; i < 94; i++) {
		fibMap[fib.at(i)] = i;
	}
	cout << "Fibonacci numbers in order:\n";
	int j = 0;
	for (auto i = fib.begin(); i < fib.end(); i++) {
		cout << j++ << " " << *i  << "\n";
	}
	cout << "Fibonacci numbers and indices, unordered:\n";
	for (auto i = fibMap.begin(); i != fibMap.end(); i++) {
		cout << i->second << " " << i->first << "\n";
	}
	cout << "Testing Fibonacci numbers from 1 to 15:\n";
	for (int i = 1; i <= 15; i++) {
		cout << i << " ";
		if (fibMap.find(i) != fibMap.end()) {
			cout << fibMap.at(i) << "\n";
		}
		else {
			cout << "no\n";
		}
	}
}


uint64_t fibCalc(int n, std::vector<uint64_t> vector)
{
	//Base cases 
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1;
	}
	
	uint64_t first;
	uint64_t second;
	//try seeing if this has already been calculated, otherwise calculate it, and store it in a vector 
	try {
		first = vector[n - 1];
	}
	catch (std::out_of_range e) {
		first = fibCalc(n - 1, vector);
	} 
	try {
		second = vector[n - 2];
	}
	catch (std::out_of_range e) {
		second = fibCalc(n - 2, vector);
	}
	return first + second;
}
