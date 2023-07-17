#pragma once
#include "Plant.h"
class Dandelion : public Plant {
public:
	Dandelion(World* world);
	Dandelion(World* world, int X, int Y, int generation);
	void Action() override;
	Organism* NewBorn(int X, int Y) override;
};