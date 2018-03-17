#include <iostream>
#include "surfaceExtraction.hpp"
#include "VoxelModel.h"

int main() {
	//Testing the STL model, with a Pixelated 3-D DU model 
	uint64_t model = emptyModel();
	model = setBit(model, 0, 0, 0);
	model = setBit(model, 1, 0, 0);
	model = setBit(model, 2, 0, 0);
	model = setBit(model, 3, 0, 1);
	model = setBit(model, 3, 0, 2);
	model = setBit(model, 0, 0, 3);
	model = setBit(model, 1, 0, 3);
	model = setBit(model, 2, 0, 3);
	model = setBit(model, 0, 0, 1);
	model = setBit(model, 0, 0, 2);
	model = setBit(model, 0, 1, 0);
	model = setBit(model, 0, 2, 0);
	model = setBit(model, 0, 3, 0);
	model = setBit(model, 0, 3, 1);
	model = setBit(model, 0, 3, 2);
	model = setBit(model, 0, 3, 3);
	writeSTL(model, "test.stl");
	
	return 0;
}