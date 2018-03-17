#include <iostream>
#include <algorithm>

#include "TestLab6.h"
#include "PackedArray.h"

// Test PackedArray with specified array size
//

void TestLab6(int numRows)
{
  std::cout << std::dec << std::showbase;
  std::cout << "Testing PackedArray with " << numRows << " rows" << std::endl;
  PackedArray a = CreateArray(numRows);
  
  if (!a.rows)
  {
    std::cout << "ERROR: PackedArray rows is null\n";
    return;
  }
  
  
  // Clear array and check that all fields are 0
  ClearArray(a);
  for (int row = 0; row < numRows; ++row)
  {
    for (int col = 0; col < 32; ++col)
    {
      if (GetEntry(a, row, col) != 0)
      {
        std::cout << "ERROR: PackedArray row " << row << " column " << col << " is non-zero after clear\n";
        return;
      }
    }
  }
  
  // Check get/set entries
  for (int row = 0; row < numRows; ++row)
  {
    for (int col = 0; col < 32; ++col)
    {
      SetEntry(a, row, col, (row+col)%4);
    }
  }
  for (int row = 0; row < numRows; ++row)
  {
    for (int col = 0; col < 32; ++col)
    {
      uint64_t expected = (row + col)%4;
      uint64_t actual = GetEntry(a, row, col);
      if (expected != actual)
      {
        std::cout << "ERROR: at row " << row << ", col " << col << " expected ";
        std::cout << expected << ", actual " << actual << std::endl;
        return;
      }
    }
  }
  
  for (int i = 0; i <= 3; i++)
  {
    FillArray(a, i);
    uint64_t expected = numRows * 32 * i;
    uint64_t actual = SumEntries(a);

   if (expected != actual)
    {
      std::cout << "ERROR: fill and sum of " << i << " expected ";
      std::cout << expected << ", actual " << actual << std::endl;
      return;
    }
  }
  
  FreeArray(a);
  std::cout << "Completed testing, no errors found\n";
}
