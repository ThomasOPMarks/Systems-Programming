#pragma once
#include <stdint.h>
// a class that allows for a dynamic bit array and manipulating it 
class BitVector {
public:
	BitVector(int size);
	~BitVector();
	void Fill();
	void Clear();
	bool Get(int index);
	void Set(int index, int value);
	void Resize(int newSize);
	int Size();

private:
	int size;
	int numberOfArray;
	uint8_t* bitArray;
};