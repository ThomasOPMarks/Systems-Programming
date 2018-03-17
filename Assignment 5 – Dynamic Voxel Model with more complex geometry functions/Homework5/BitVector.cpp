#include "BitVector.h"
#include <iostream>

BitVector::BitVector(int size)
{
	bitArray = new uint8_t[(size / 8) + 1];
	this->numberOfArray = (size / 8) + 1;
	this->size = size;
	this->Clear();
}

BitVector::~BitVector()
{
	this->size = 0;
	delete[] this->bitArray;
	this->bitArray = NULL;
	this->numberOfArray = 0;
}

void BitVector::Fill()
{
	if (this->size % 8 == 0) {
		for (int i = 0; i < this->numberOfArray - 1; i++) {
			bitArray[i] = 0xFF;
		}
	}
	else{
		for (int i = 0; i < this->numberOfArray - 1; i++) {
			bitArray[i] = 0xFF;
		}
		bitArray[numberOfArray - 1] = 0xFF >> (8 - (size % 8));
	}
}

void BitVector::Clear()
{
	for (int i = 0; i < this->numberOfArray; i++) {
		bitArray[i] = 0;
	}
}

bool BitVector::Get(int index)
{
	if (index > size - 1) {
		return NULL;
	}
	int indexA = index / 8;
	int offset = index % 8;

	return (bitArray[indexA] & (1 << offset));
}

void BitVector::Set(int index, int value)
{
	if (index > size - 1) {
		return;
	}
	int indexA = index / 8;
	int offset = index % 8;

	uint8_t val = 1 << offset;

	if (value) {
		bitArray[indexA] = val | bitArray[indexA];
	}
	else {
		bitArray[indexA] = (~val) & bitArray[indexA];
	}

}

void BitVector::Resize(int newSize)
{
	uint8_t* temp = new uint8_t[(newSize / 8) + 1];
	int newSizeMember = (newSize / 8) + 1;
	for (int i = 0; i < this->numberOfArray; i++) {
		temp[i] = this->bitArray[i];
	}
	for (int i = this->numberOfArray; i < newSizeMember; i++) {
		temp[i] = 0;
	}
	delete[] bitArray;
	bitArray = temp;
	this->numberOfArray = (newSize / 8) + 1;
	this->size = newSize;
}

int BitVector::Size()
{
	return size;
}
