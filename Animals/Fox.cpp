#include "Fox.h"
Fox::Fox(World* world) {
	this->world = world;
	initiative = 7;
	power = 3;
	std::random_device rd;
	std::mt19937 gen(rd());
	do {
		std::uniform_int_distribution<> disX(1, world->GetWidth());
		std::uniform_int_distribution<> disY(1, world->GetHeight());
		X = disX(gen);
		Y = disY(gen);
	} while (this->world->GetElement(X, Y) != EOF);
	identity = 'F';
	name = "Fox";
	generation = 1;
}

Fox::Fox(World* world, int X, int Y, int generation) {
	this->world = world;
	initiative = 7;
	power = 3;
	this->X = X;
	this->Y = Y;
	identity = 'F';
	name = "Fox";
	this->generation = generation;
}

void Fox::Action() {
	Animal::Action();
	Organism* org = world->GetOrganism(GetMe(), X, Y);
	if (org == nullptr) return;
	if (org->GetPower() > power) {
		X = prev_X;
		Y = prev_Y;
	}
}

Organism* Fox::NewBorn(int X, int Y) {
	return new Fox(world, X, Y, generation + 1);
}