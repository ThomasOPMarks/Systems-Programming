#include <iostream>
#include <chrono>
#include <ctime>
// A look at passing by value, pointer, and reference for primatives and structs
struct pair
{
	int x;
	int y;
};

struct biggo {
	int x[100000];
	char name;
};

void swap_value(int a, int b);
void swap_reference(int& a, int& b);
void swap_pointer(int* a, int* b);

void swap_value(pair p);
void swap_reference(pair& p);
void swap_pointer(pair* p);

int sum_first_five(biggo copy);
int sum_first_five_reference(biggo& copy);

//using namespace std;



int main() {
	int a = 1;
	int b = 2;

	std::cout << "Values before swap_value: " << a << " " << b << std::endl;
	swap_value(a, b);
	std::cout << "After: " << a << " " << b << std::endl;

	std::cout << "Values before swap_reference: " << a << " " << b << std::endl;
	swap_reference(a, b);
	std::cout << "After: " << a << " " << b << std::endl;

	a = 1;
	b = 2;

	std::cout << "Values before swap_reference: " << a << " " << b << std::endl;
	swap_pointer(&a, &b);
	std::cout << "After: " << a << " " << b << std::endl;
	
	//Value doesn't work, the other two do
	std::cout << "Value doesn't work, the other two do" << std::endl;

	pair x{ 1, 2 };

	std::cout << "Values before swap_value: " << (x.x) << " " << (x.y) << std::endl;
	swap_value(x);
	std::cout << "After: " << (x.x) << " " << (x.y) << std::endl;

	std::cout << "Values before swap_reference: " << (x.x) << " " << (x.y) << std::endl;
	swap_reference(x);
	std::cout << "After: " << (x.x) << " " << (x.y) << std::endl;
	
	x.x = 1;
	x.y = 2;

	std::cout << "Values before swap_reference: " << (x.x) << " " << (x.y) << std::endl;
	swap_pointer(&x);
	std::cout << "After: " << (x.x) << " " << (x.y) << std::endl;

	//Value doesn't work, the other two do
	std::cout << "Value doesn't work, the other two do" << std::endl;

	
	biggo mine;
	mine.name = 'a';

	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	for (int i = 0; i < 10000; i++) {
		sum_first_five(mine);
	}

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "Elapsed time by value: " << elapsed_seconds.count() << "s" << std::endl;

	std::chrono::time_point<std::chrono::system_clock> start2, end2;
	start2 = std::chrono::system_clock::now();

	for (int i = 0; i < 10000; i++) {
		sum_first_five_reference(mine);
	}

	end2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
	std::cout << "Elapsed time by reference: " << elapsed_seconds2.count() << "s" << std::endl;

	std::chrono::time_point<std::chrono::system_clock> start3, end3;
	start3 = std::chrono::system_clock::now();

	for (int i = 0; i < 10000; i++) {
		//sum_first_five_reference(mine);
	}

	end3 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds3 = end3 - start3;
	std::cout << "Elapsed time by for loop only (orders of magnitude below the other times): " << elapsed_seconds3.count() << "s" << std::endl;


	return 0;
}

void swap_value(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap_reference(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap_pointer(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_pointer(pair* p)
{
	int temp = p->x;
	p->x = p->y;
	p->y = temp;
}

void swap_reference(pair& p)
{
	int temp = p.x;
	p.x = p.y;
	p.y = temp;
}

void swap_value(pair p)
{
	int temp = p.x;
	p.x = p.y;
	p.y = temp;
}

int sum_first_five(biggo copy) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += copy.x[i];
	}
	return sum;
}

int sum_first_five_reference(biggo& copy) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += copy.x[i];
	}
	return sum;
}
