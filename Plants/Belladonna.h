#pragma once
#include "Plant.h"
class Belladonna : public Plant {
public:
	Belladonna(World* world);
	Belladonna(World* world, int X, int Y, int generation);
	void Collision(Organism* organism) override;
	bool IsEatenDebuff(Organism* organism) override;
	Organism* NewBorn(int X, int Y) override;
};