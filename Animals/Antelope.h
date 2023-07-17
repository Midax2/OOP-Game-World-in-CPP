#pragma once
#include "Animal.h"
class Antelope : public Animal {
private:
	bool isRuning;
public:
	Antelope(World* world);
	Antelope(World* world, int X, int Y, int generation);
	Organism* NewBorn(int X, int Y) override;
	void Action() override;
	void Collision(Organism* organism) override;
	bool RunAway(Organism* organism) override;
	bool GetIsRuning();
	void SetIsRuning(bool run);
};