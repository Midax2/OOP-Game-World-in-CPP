#pragma once
#include "World.h"
class Organism {
protected:
	char identity;
	std::string name;
	int power;
	int initiative;
	int generation;
	int X, Y;
	int prev_X, prev_Y;
	World* world;
public:
	virtual void Action() = 0;
	virtual void Collision(Organism* organism) = 0;
	World* GetWorld();
	Organism* GetMe();
	virtual Organism* NewBorn(int X, int Y) = 0;
	int GetInitiative();
	int GetPower();
	void SetPower(int power);
	int GetX();
	int GetY();
	void SetX(int X);
	void SetY(int Y);
	int GetPrevX();
	int GetPrevY();
	void SetPrevX(int X);
	void SetPrevY(int Y);
	char GetIdentity();
	int GetGeneration();
	std::string GetName();
	virtual bool Defend(Organism* organism);
	virtual bool RunAway(Organism* organism);
	virtual bool IsEatenDebuff(Organism* organism);
	void Print();
};