#include <iostream>

#include "PackedArray.h"

// Create the array; initialize memory
PackedArray CreateArray(int aSize)
{
	PackedArray z;
	z.numRows = aSize;
	z.rows = new uint64_t[z.numRows];


	return z;

}

// Frees memory for the array
void FreeArray(PackedArray &array)
{
	delete [] array.rows;
	array.rows = 0;
}

// Sets all entries in the array to value parameter
void FillArray(PackedArray &array, uint64_t value)
{
	uint64_t total = value;
	for (int i = 0; i < 31; i++) {
		total <<= 2;
		total |= value;
	}
	
	for (int i = 0; i < array.numRows; i++) {
		array.rows[i] = total;
	}

	
	
}

// Clears all entries to 0 in the array
void ClearArray(PackedArray &array)
{
	for (int i = 0; i < array.numRows; i++) {
		array.rows[i] = 0;
	}
}

// Get the value of the entry at the specified row and col.
// If row or col are outside of the range for this PackedArray,
// returns 0.
int GetEntry(const PackedArray &array, int row, int col)
{
	if (row > array.numRows || col > 31) {
		return 0;
	}

	uint64_t current = array.rows[row];
	current = current >> (col * 2) & 3;
	return current;

}

// Sets entry in the location row, col to the specified value.
// If row or col are outside of the range for this PackedArray,
// function has no effect.
void SetEntry(PackedArray &array, int row, int col, uint64_t value)
{
	if (row > array.numRows || col > 31) {
		return;
	}
	array.rows[row] = array.rows[row] | value << (2 * col);
}

// Sum all the entries in the array
int SumEntries(const PackedArray &array)
{
	int sum = 0;
	for (int i = 0; i < array.numRows; i++) {
		for (int j = 0; j < 32; j++) {
			sum += GetEntry(array, i, j);
		}
	}
	return sum;

}