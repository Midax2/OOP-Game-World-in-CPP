#pragma once
#include "Animal.h"
class Sheep : public Animal {
public:
	Sheep(World* world);
	Sheep(World* world, int X, int Y, int generation);
	Organism* NewBorn(int X, int Y) override;
};