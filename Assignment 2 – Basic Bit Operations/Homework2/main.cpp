#include <iostream>
#include <cassert>
#include "VoxelModel.h"
#include <stdint.h>
using namespace std;

int main() {
	//Using a uint64_t as a 4x4x4 voxel modle, and calling various functions on it
	//operating on a bit level
	for (int i = 0; i < 64; i++) {
		assert(getIndex(getX(i), getY(i), getZ(i)) == i);
	}

	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			for (int z = 0; z < 4; z++) {
				assert(getX(getIndex(x,y,z)) == x);
				assert(getY(getIndex(x, y, z)) == y);
				assert(getZ(getIndex(x, y, z)) == z);
			}
		}
	}

	cout << hex;

	uint64_t test = emptyModel();
	cout << "Empty Model: " << test << "\n";

	test = setBit(test, 1, 0, 0);
	cout << "Set Bit: " << test << "\n";
	test = setBit(test, 0, 0, 0);
	cout << "Set Bit: " << test << "\n";
	test = clearBit(test, 0, 0, 0);
	cout << "Clear Bit: " << test << "\n";
	bool survive = getBit(test, 1, 0, 0);
	cout << survive << "\n";
	test = toggleBit(test, 1, 1, 0);
	cout << "Toggle Bit: " << test << "\n";
	test = toggleBit(test, 1, 1, 0);
	cout << "Toggle Bit (now toggle it off): " << test << "\n";

	uint64_t axis = emptyModel();
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			for (int z = 0; z < 4; z++) {
				if ((x == 0 && y == 0) || (x == 0 && z == 0) || (y == 0 && x == 0)) {
					axis = setBit(axis, x, y, z);
				}
			}
		}
	}
	cout << "Axis: " << axis << "\n";
	return 0;
}

