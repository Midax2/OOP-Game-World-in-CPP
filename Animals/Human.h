#pragma once
#include "Animal.h"
class Human : public Animal {
private:
	int turn;
	bool super_power;	
public:
	Human(World* world);
	Human(World* world, int X, int Y, int generation);
	void Action() override;
	void Collision(Organism* organism) override;
	int GetTurn();
	void SetTurn(int turn);
	void ChangeSuperPower();
	Organism* NewBorn(int X, int Y) override;
	bool GetSuperPower();
	void SetSuperPower(bool power);
};