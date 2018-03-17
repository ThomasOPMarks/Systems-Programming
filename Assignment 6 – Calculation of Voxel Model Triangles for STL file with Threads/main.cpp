#include <iostream>
#include "BitVector.h"
#include <assert.h>
#include "VoxelModel.h"
#include <chrono>
using std::cout;

int main() {
	//Calculating of the triangles has been changed to use threads 
	int x = 250;
	int y = 250;
	int z = 250;
	VoxelModel* v = new VoxelModel(x, y, z);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {
				if ((i + j + k) % 4 == 0) {
					v->setBit(i, j, k);
				}
			}
		}
	}
	
	v->fillModel();
	v->setBit(0, 0, 0);
	v->setBit(1, 0, 0);
	v->setBit(2, 0, 0);
	v->setBit(3, 0, 1);
	v->setBit(3, 0, 2);
	v->setBit(0, 0, 3);
	v->setBit(1, 0, 3);
	v->setBit(2, 0, 3);
	v->setBit(0, 0, 1);
	v->setBit(0, 0, 2);
	v->setBit(0, 1, 0);
	v->setBit(0, 2, 0);
	v->setBit(0, 3, 0);
	v->setBit(0, 3, 1);
	v->setBit(0, 3, 2);
	v->setBit(0, 3, 3);
	writeSTL(*v, "Test.stl");

}