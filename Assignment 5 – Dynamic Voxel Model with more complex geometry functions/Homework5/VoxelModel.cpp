#include <stdint.h>
#include <iostream>
#include "VoxelModel.h"
#pragma warning (disable:4996)

VoxelModel::VoxelModel(int nx, int ny, int nz)
{
	x = nx;
	y = ny;
	z = nz;
	map = new BitVector(nx * ny * nz);
}
VoxelModel::~VoxelModel()
{
	x = 0;
	y = 0;
	z = 0;
	delete map;
	map = NULL;
}

void VoxelModel::clearModel()
{
	map->Clear();
}

void VoxelModel::fillModel()
{
	map->Fill();
}

bool VoxelModel::getBit(int nx, int ny, int nz)
{
	return map->Get(getIndex(nx, ny, nz));
}
int VoxelModel::getIndex(int nx, int ny, int nz)
{
//	std::cout << "Index: " << (z * y * nx + z * ny + z) << "\n";
	return z * y * nx + z * ny + nz;
}
void VoxelModel::setBit(int nx, int ny, int nz)
{
	map->Set(getIndex(nx, ny, nz), 1);
}

void VoxelModel::clearBit(int nx, int ny, int nz)
{
	map->Set(getIndex(nx, ny, nz), 0);
}

void VoxelModel::addSphere(float cx, float cy, float cz, float r)
{
	for (int x = -r + 1 + cx; x < r + cx; x++) {
		for (int y = -r + 1 + cy; y < r + cy; y++) {
			for (int z = -r + 1 + cz; z < r + cz; z++) {
				if ((x) >= 0 && (x) < x && (y) >= 0 && (y) < y && (z) >= 0 && (z) < z && (x - cx) * (x - cx) + (y - cy) * (y - cy) + (z - cz) * (z - cz) < r * r) {
					setBit(x, y, z);
				}
			}
		}
	}
}

void VoxelModel::clearSphere(float cx, float cy, float cz, float r)
{
	for (int x = -r + 1 + cx; x < r + cx; x++) {
		for (int y = -r + 1 + cy; y < r + cy; y++) {
			for (int z = -r + 1 + cz; z < r + cz; z++) {
				if ((x) >= 0 && (x) < x && (y) >= 0 && (y) < y && (z) >= 0 && (z) < z && (x - cx) * (x - cx) + (y - cy) * (y - cy) + (z - cz) * (z - cz) < r * r) {
					clearBit(x, y, z);
				}
			}
		}
	}
}

void VoxelModel::toggleSphere(float cx, float cy, float cz, float r)
{
	for (int x = -r + 1 + cx; x < r + cx; x++) {
		for (int y = -r + 1 + cy; y < r + cy; y++) {
			for (int z = -r + 1 + cz; z < r + cz; z++) {
				if ((x) >= 0 && (x) < x && (y) >= 0 && (y) < y && (z) >= 0 && (z) < z && (x - cx) * (x - cx) + (y - cy) * (y - cy) + (z - cz) * (z - cz) < r * r) {
					if (getBit(x, y, z)) {
						clearBit(x, y, z);
					}
					else {
						setBit(x, y, z);
					}
				}
			}
		}
	}
}

int VoxelModel::getX()
{
	return x;
}

int VoxelModel::getY()
{
	return y;
}

int VoxelModel::getZ()
{
	return z;
}


enum FaceType {
	NX,
	NY,
	NZ,
	PX,
	PY,
	PZ
};

struct Triangle {
	float normal[3];
	float v1[3];
	float v2[3];
	float v3[3];
};

inline void fillPlane(int a1, int a2, int b1, int b2, int c, int cInd, Triangle& t1, Triangle& t2) {
	t1.v1[cInd] = c;
	t2.v1[cInd] = c;
	t1.v2[cInd] = c;
	t2.v2[cInd] = c;
	t1.v3[cInd] = c;
	t2.v3[cInd] = c;
	int aInd = (cInd + 1) % 3;
	int bInd = (cInd + 2) % 3;

	t1.v1[aInd] = a1;
	t1.v2[aInd] = a2;
	t1.v3[aInd] = a2;

	t2.v1[aInd] = a1;
	t2.v2[aInd] = a2;
	t2.v3[aInd] = a1;

	t1.v1[bInd] = b1;
	t1.v2[bInd] = b1;
	t1.v3[bInd] = b2;

	t2.v1[bInd] = b1;
	t2.v2[bInd] = b2;
	t2.v3[bInd] = b2;

}

void extractFace(int x, int y, int z, FaceType face, Triangle& t1, Triangle& t2) {
	for (int i = 0; i < 3; i++) {
		t1.normal[i] = 0;
		t2.normal[i] = 0;
	}
	switch (face) {
	case NX:
		t1.normal[0] = -1;
		t2.normal[0] = -1;
		fillPlane(y + 1, y, z, z + 1, x, 0, t1, t2);
		break;
	case NY:
		t1.normal[1] = -1;
		t2.normal[1] = -1;
		fillPlane(z + 1, z, x, x + 1, y, 1, t1, t2);
		break;
	case NZ:
		t1.normal[2] = -1;
		t2.normal[2] = -1;
		fillPlane(x + 1, x, y, y + 1, z, 2, t1, t2);
		break;
	case PX:
		t1.normal[0] = 1;
		t2.normal[0] = 1;
		fillPlane(y, y + 1, z, z + 1, x + 1, 0, t1, t2);
		break;
	case PY:
		t1.normal[1] = 1;
		t2.normal[1] = 1;
		fillPlane(z, z + 1, x, x + 1, y + 1, 1, t1, t2);
		break;
	case PZ:
		t1.normal[2] = 1;
		t2.normal[2] = 1;
		fillPlane(x, x + 1, y, y + 1, z + 1, 2, t1, t2);
		break;
	}
}

void writeTriangles(Triangle t1, Triangle t2, FILE* file) {
	uint16_t zero = 0;
	fwrite(t1.normal, sizeof(t1.normal[0]), 3, file);
	fwrite(t1.v1, sizeof(t1.v1[0]), 3, file);
	fwrite(t1.v2, sizeof(t1.v2[0]), 3, file);
	fwrite(t1.v3, sizeof(t1.v3[0]), 3, file);
	fwrite(&zero, sizeof(zero), 1, file);

	fwrite(t2.normal, sizeof(t2.normal[0]), 3, file);
	fwrite(t2.v1, sizeof(t2.v1[0]), 3, file);
	fwrite(t2.v2, sizeof(t2.v2[0]), 3, file);
	fwrite(t2.v3, sizeof(t2.v3[0]), 3, file);
	fwrite(&zero, sizeof(zero), 1, file);


}
void writeSTL(VoxelModel model, const char* filename) {
	FILE* file = fopen(filename, "wb");
	uint8_t zeros[80] = { 0,0 };

	uint32_t numTriangles = 0;

	fwrite(zeros, sizeof(uint8_t), 80, file);

	fwrite(&numTriangles, sizeof(uint32_t), 1, file);

	for (int x = 0; x < model.getX(); x++) {
		for (int y = 0; y < model.getY(); y++) {
			for (int z = 0; z < model.getZ(); z++) {
				bool a = model.getBit(x, y, z);
				if (model.getBit(x, y, z)) {
					if (x == 0 || !model.getBit(x - 1, y, z)) {
						Triangle t1;
						Triangle t2;
						extractFace(x, y, z, NX, t1, t2);
						numTriangles += 2;
						writeTriangles(t1, t2, file);
					}
					if (x == model.getX() - 1 || !model.getBit(x + 1, y, z)) {
						Triangle t1;
						Triangle t2;
						extractFace(x, y, z, PX, t1, t2);
						numTriangles += 2;
						writeTriangles(t1, t2, file);
					}
					if (y == 0 || !model.getBit(x, y - 1, z)) {
						Triangle t1;
						Triangle t2;
						extractFace(x, y, z, NY, t1, t2);
						numTriangles += 2;
						writeTriangles(t1, t2, file);
					}
					if (y == model.getY() - 1 || !model.getBit(x, y + 1, z)) {
						Triangle t1;
						Triangle t2;
						extractFace(x, y, z, PY, t1, t2);
						numTriangles += 2;
						writeTriangles(t1, t2, file);
					}

					if (z == 0 || !model.getBit(x, y, z - 1)) {
						Triangle t1;
						Triangle t2;
						extractFace(x, y, z, NZ, t1, t2);
						numTriangles += 2;
						writeTriangles(t1, t2, file);
					}
					if (z == model.getZ() - 1 || !model.getBit(x, y, z + 1)) {
						Triangle t1;
						Triangle t2;
						extractFace(x, y, z, PZ, t1, t2);
						numTriangles += 2;
						writeTriangles(t1, t2, file);
					}

				}
			}
		}
	}
	fseek(file, 80, SEEK_SET);
	fwrite(&numTriangles, sizeof(numTriangles), 1, file);
	fclose(file);
}