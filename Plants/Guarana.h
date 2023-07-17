#pragma once
#include "Plant.h"
class Guarana : public Plant {
public:
	Guarana(World* world);
	Guarana(World* world, int X, int Y, int generation);
	void Collision(Organism* organism) override;
	bool IsEatenDebuff(Organism* organism) override;
	Organism* NewBorn(int X, int Y) override;
};