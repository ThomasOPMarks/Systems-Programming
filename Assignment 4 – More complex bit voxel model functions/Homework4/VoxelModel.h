#pragma once
#include <stdint.h>

struct VoxelModel {
	int x;
	int y; 
	int z;
	uint8_t* bitmap;
};
VoxelModel allocateModel(int nx, int ny, int nz);
void clearModel(VoxelModel& model);
void fillModel(VoxelModel& model);
void deleteModel(VoxelModel& model);

int getIndex(const VoxelModel& model, int x, int y, int z);
void getXYZ(const VoxelModel& model, int index, int& x, int& y, int& z);
bool getBit(VoxelModel model, int x, int y, int z);
void setBit(VoxelModel model, int x, int y, int z);
void clearBit(VoxelModel model, int x, int y, int z);
int getByteNumber(int index);
uint8_t getBitNumber(int index);

void addSphere(VoxelModel& model, float cx, float cy, float cz, float r);
void clearSphere(VoxelModel& model, float cx, float cy, float cz, float r);
void toggleSphere(VoxelModel& model, float cx, float cy, float cz, float r);