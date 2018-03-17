#include <stdint.h>
#include <iostream>
#include "VoxelModel.h"

VoxelModel allocateModel(int nx, int ny, int nz){	
	VoxelModel* a = new VoxelModel();
	a->x = nx;
	a->y = ny;
	a->z = nz;
	a->bitmap = new uint8_t[nx*ny*nz];
	return *a;
}

void clearModel(VoxelModel & model)
{
	for (int i = 0; i < (model.x * model.y * model.z) >> 3; i++) {
		model.bitmap[i] = 0;
	}
}

void fillModel(VoxelModel & model){
	for (int i = 0; i < (model.x * model.y * model.z) >> 3; i++) {
		model.bitmap[i] = UINT8_MAX;
	}
}

void deleteModel(VoxelModel & model)
{
	model.x = 0;
	model.y = 0;
	model.z = 0;
	delete[] model.bitmap;
	model.bitmap = NULL;
}

int getIndex(const VoxelModel& model, int x, int y, int z) {
	return model.z * model.y * x + model.z * y + z;
}

void getXYZ(const VoxelModel& model, int index, int& x, int& y, int& z) {
	x = index / (model.y * model.z);
	z = index % model.z;
	y = index % (model.y * model.z) / (model.z);

}

uint8_t getX(uint8_t index) {
	return index / 16;
}

uint8_t getY(uint8_t index) {
	return (index % 16) / 4;
}

uint8_t getZ(uint8_t index) {
	return index % 4;
}


int getByteNumber(int index)
{
	return index>>3;
}
uint8_t getBitNumber(int index)
{
	int temp = index & 7;
	return static_cast<uint8_t> (temp);
}

void addSphere(VoxelModel & model, float cx, float cy, float cz, float r)
{
	for (int x = -r + 1 + cx; x < r + cx; x++) {
		for (int y = -r + 1 + cy; y < r + cy; y++) {
			for (int z = -r + 1 + cz; z < r + cz; z++) {
				if ((x) >= 0 && (x) < model.x && (y) >= 0 && (y) < model.y && (z) >= 0 && (z) < model.z && (x - cx) * (x - cx) + (y - cy) * (y - cy) + (z - cz) * (z - cz) < r * r){
					setBit(model, x, y , z);
				}
			}
		}
	}
}

void clearSphere(VoxelModel & model, float cx, float cy, float cz, float r)
{
	for (int x = -r + 1 + cx; x < r + cx; x++) {
		for (int y = -r + 1 + cy; y < r + cy; y++) {
			for (int z = -r + 1 + cz; z < r + cz; z++) {
				if ((x) >= 0 && (x) < model.x && (y) >= 0 && (y) < model.y && (z) >= 0 && (z) < model.z && (x - cx) * (x - cx) + (y - cy) * (y - cy) + (z - cz) * (z - cz) < r * r) {
					clearBit(model, x, y, z);
				}
			}
		}
	}
}

void toggleSphere(VoxelModel & model, float cx, float cy, float cz, float r)
{
	for (int x = -r + 1 + cx; x < r + cx; x++) {
		for (int y = -r + 1 + cy; y < r + cy; y++) {
			for (int z = -r + 1 + cz; z < r + cz; z++) {
				if ((x) >= 0 && (x) < model.x && (y) >= 0 && (y) < model.y && (z) >= 0 && (z) < model.z && (x - cx) * (x - cx) + (y - cy) * (y - cy) + (z - cz) * (z - cz) < r * r) {
					if (getBit(model, x, y, z)) {
						clearBit(model, x, y, z);
					}
					else {
						setBit(model, x, y, z);
					}
				}
			}
		}
	}
}

bool getBit(VoxelModel model, int x, int y, int z) {
	uint8_t temp = model.bitmap[getByteNumber(getIndex(model, x, y, z))];
	uint8_t set = 1 << getBitNumber(getIndex(model, x, y, z));
	return temp & set;
}

void setBit(VoxelModel model, int x, int y, int z) {
	uint8_t temp = model.bitmap[getByteNumber(getIndex(model, x, y, z))];
	uint8_t set = 1 << getBitNumber(getIndex(model, x, y, z));
	model.bitmap[getByteNumber(getIndex(model, x, y, z))] = temp | set;

}

void clearBit(VoxelModel model, int x, int y, int z) {
	uint8_t temp = model.bitmap[getByteNumber(getIndex(model, x, y, z))];
	uint8_t clear = ~(1 << getBitNumber(getIndex(model, x, y, z)));
	model.bitmap[getByteNumber(getIndex(model, x, y, z))] = temp & clear;
}

