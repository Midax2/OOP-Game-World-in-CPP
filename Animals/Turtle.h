#pragma once
#include "Animal.h"
class Turtle : public Animal {
private:
	bool isMoving;
public:
	Turtle(World* world);
	Turtle(World* world, int X, int Y, int generation);
	void Action() override;
	void Collision(Organism* organism) override;
	bool Defend(Organism* organism) override;
	Organism* NewBorn(int X, int Y) override;
	bool GetIsMoving();
	void SetIsMoving(bool move);
};