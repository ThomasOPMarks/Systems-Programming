#pragma once
#include "Produce.h"
class Apples : public Produce {
public:
	Apples(double weight) : Produce(weight, "Apples", 9.89) {}
};