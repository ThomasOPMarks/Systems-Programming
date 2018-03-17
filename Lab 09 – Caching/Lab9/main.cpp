#include <iostream>
#include <ctime>
#include <conio.h>
//Demostration of the benefits of caching 
int main() {
	//2-D array
	int* two = new int[1000*1000];
	//3-D array
	int* three = new int[100 * 100 * 100];
	clock_t start = clock();

	//an cache optimized array
	int total = 0;
	for (int turns = 0; turns < 1000; turns++) {
		for (int x = 0; x < 1000; x++) {
			for (int y = 0; y < 1000; y++) {
				total += two[x * 1000 + y];
			}
		}
	}

	clock_t end = clock();

	std::cout << "Optimized 2D: " << (end - start) << "ms" << std::endl;

	//Trying not to use as much caching, about 130% longer that the optimized loop on my local computer 
	start = clock();
	total = 0;
	for (int turns = 0; turns < 1000; turns++) {
		for (int y = 0; y < 1000; y++) {
			for (int x = 0; x < 1000; x++) {
				total += two[x*1000 + y];
			}
		}
	}
	end = clock();
	std::cout << "Not optimized 2D: " << (end - start) << "ms" << std::endl;


	//Optimized 3-D caching loop
	start = clock();
	total = 0;
	for (int turns = 0; turns < 1000; turns++) {
		for (int x = 0; x < 100; x++) {
			for (int y = 0; y < 100; y++) {
				for (int z = 0; z < 100; z++) {
					total += two[x * 10000 + y * 100 + z];
				}
			}
		}
	}
	end = clock();
	std::cout << "Optimized 3D: " << (end - start) << "ms" << std::endl;

	//A loop that tries to not use caching as much as possible, about 150% slower than the first 3-D loop
	start = clock();
	total = 0;
	for (int turns = 0; turns < 1000; turns++) {
		for (int z = 0; z < 100; z++) {
			for (int y = 0; y < 100; y++) {
				for (int x = 0; x < 100; x++) {
					total += two[x * 10000 + y * 100 + z];
				}
			}
		}
	}
	end = clock();
	std::cout << "Not optimized 3D: " << (end - start) << "ms" << std::endl;

	//A loop that uses some caching, about 130% slower than the first
	start = clock();
	total = 0;
	for (int turns = 0; turns < 1000; turns++) {
		for (int y = 0; y < 100; y++) {
			for (int z = 0; z < 100; z++) {
				for (int x = 0; x < 100; x++) {
					total += two[x * 10000 + y * 100 + z];
				}
			}
		}
	}
	end = clock();
	std::cout << "Not optimized 3D: " << (end - start) << "ms" << std::endl;



	return 0;
}