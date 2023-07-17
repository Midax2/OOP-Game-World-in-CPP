#pragma once
#include "Animal.h"
class Fox : public Animal {
public:
	Fox(World* world);
	Fox(World* world, int X, int Y, int generation);
	Organism* NewBorn(int X, int Y) override;
	void Action() override;
};