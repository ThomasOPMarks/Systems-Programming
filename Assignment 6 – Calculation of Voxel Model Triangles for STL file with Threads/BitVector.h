#pragma once
#include <stdint.h>
#include "MyArray.h"

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
	MyArray<uint8_t>* bitArray;
};