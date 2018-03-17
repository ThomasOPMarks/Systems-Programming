#pragma once
#include <stdint.h>
#include "BitVector.h"
#include "SharedQueue.h"
class VoxelModel {
public:
	VoxelModel(int nx, int ny, int nz);
	~VoxelModel();

	void clearModel();
	void fillModel();

	bool getBit(int x, int y, int z);
	void setBit(int x, int y, int z);
	void clearBit(int x, int y, int z);

	void addSphere(float cx, float cy, float cz, float r);
	void clearSphere(float cx, float cy, float cz, float r);
	void toggleSphere(float cx, float cy, float cz, float r);

	int getX();
	int getY();
	int getZ();
	

	
private:
	int getIndex(int nx, int ny, int nz);
	BitVector * map;
	int x; 
	int y; 
	int z;
};

void writeSTL(VoxelModel model, const char* filename);