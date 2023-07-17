#pragma once
#include "Animal.h"
class Wolf : public Animal {
public:
	Wolf(World* world);
	Wolf(World* world, int X, int Y, int generation);
	Organism* NewBorn(int X, int Y) override;
};