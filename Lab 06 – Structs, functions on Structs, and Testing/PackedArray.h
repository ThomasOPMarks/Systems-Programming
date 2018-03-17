
#ifndef __Lab_5__PackedArray__
#define __Lab_5__PackedArray__

#include <cstdint>

#include "PackedArray.h"

// PackedArray is a struct which holds a packed square array of entries.
// Each row is stored in a single uint64_t value, which may hold up to 12 5-bit entries
struct PackedArray
{
	// Stores an array of uint64_t which are used for the bits
	uint64_t *rows;      // pointer to dynamically allocated rows
	size_t numRows;        // number of rows in the array
};

// Create the array; initialize memory
PackedArray CreateArray(int aSize);

// Frees memory for the array
void FreeArray(PackedArray &array);

// Sets all entries in the array to value parameter
void FillArray(PackedArray &array, uint64_t value);

// Clears all entries to 0 in the array
void ClearArray(PackedArray &array);

// Get the value of the entry at the specified row and col.
// If row or col are outside of the range for this PackedArray,
// returns 0.
int GetEntry(const PackedArray &array, int row, int col);


// Sets entry in the location row, col to the specified value.
// If row or col are outside of the range for this PackedArray,
// function has no effect.
void SetEntry(PackedArray &array, int row, int col, uint64_t value);


// Sum all the entries in the array
int SumEntries(const PackedArray &array);


#endif /* defined(__Lab_5__PackedArray__) */
