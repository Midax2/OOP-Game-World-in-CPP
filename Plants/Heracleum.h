#pragma once
#include "Plant.h"
class Heracleum : public Plant {
public:
	Heracleum(World* world);
	Heracleum(World* world, int X, int Y, int generation);
	void Action() override;
	void Collision(Organism* organism) override;
	bool IsEatenDebuff(Organism* organism) override;
	Organism* NewBorn(int X, int Y) override;
};