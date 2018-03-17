#include <stdint.h>

uint8_t getIndex(int x, int y, int z) {
	return 16 * x + 4 * y + z;
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

uint64_t emptyModel() {
	return 0;
}

uint64_t fullModel() {
	return UINT64_MAX;
}

bool getBit(uint64_t model, int x, int y, int z) {
	uint64_t a = (static_cast<uint64_t> (1)) << getIndex(x, y, z);
	uint64_t b = a & model;
	return b;
}

uint64_t setBit(uint64_t model, int x, int y, int z) {
	return model | ((static_cast<uint64_t> (1)) << getIndex(x, y, z));
}

uint64_t clearBit(uint64_t model, int x, int y, int z) {
	return model & (~(1 << getIndex(x, y, z)));
}

uint64_t toggleBit(uint64_t model, int x, int y, int z) {
	return model ^ (1 << getIndex(x, y, z));
}