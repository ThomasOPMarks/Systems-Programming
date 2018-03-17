#include <iostream>
#include "surfaceExtraction.hpp"
#include "VoxelModel.h"
#include <assert.h>

int main() {
	//Adding more complex functions, like adding a sphere to the model
	int x = 1000;
	int y = 1000;
	int z = 1000;

	VoxelModel model = allocateModel(x, y, z);
	for (int i = 0; i < x * y * z; i++) {
		int a, b, c;
		getXYZ(model, i, a, b, c);
		assert(i == getIndex(model, a, b, c));
	}
	clearModel(model);
	setBit(model, 0, 0, 0);
	setBit(model, 1, 0, 0);
	setBit(model, 2, 0, 0);
	setBit(model, 3, 0, 1);
	setBit(model, 3, 0, 2);
	setBit(model, 0, 0, 3);
	setBit(model, 1, 0, 3);
	setBit(model, 2, 0, 3);
	setBit(model, 0, 0, 1);
	setBit(model, 0, 0, 2);
	setBit(model, 0, 1, 0);
	setBit(model, 0, 2, 0);
	setBit(model, 0, 3, 0);
	setBit(model, 0, 3, 1);
	setBit(model, 0, 3, 2);
	setBit(model, 0, 3, 3);
	addSphere(model, 10, 10, 10, 6);
	clearSphere(model, 8, 8, 8, 5);
	toggleSphere(model, 0, 0, 0, 10);
	writeSTL(model, "test.stl");

	return 0;
}