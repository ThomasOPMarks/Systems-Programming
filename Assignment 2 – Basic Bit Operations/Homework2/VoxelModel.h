#pragma once
#include <stdint.h>
uint8_t getIndex(int x, int y, int z);
uint8_t getX(uint8_t index);
uint8_t getY(uint8_t index);
uint8_t getZ(uint8_t index);
uint64_t emptyModel();
uint64_t fullModel();
uint64_t setBit(uint64_t model, int x, int y, int z);
uint64_t clearBit(uint64_t model, int x, int y, int z);
uint64_t toggleBit(uint64_t model, int x, int y, int z);

bool getBit(uint64_t model, int x, int y, int z);