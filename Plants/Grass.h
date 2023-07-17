#pragma once
#include "Plant.h"
class Grass : public Plant {
public:
	Grass(World* world);
	Grass(World* world, int X, int Y, int generation);
	Organism* NewBorn(int X, int Y) override;
};