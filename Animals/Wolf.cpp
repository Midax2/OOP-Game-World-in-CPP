#include "Wolf.h"
Wolf::Wolf(World* world) {
	this->world = world;
	initiative = 5;
	power = 9;
	std::random_device rd;
	std::mt19937 gen(rd());
	do {
		std::uniform_int_distribution<> disX(1, world->GetWidth());
		std::uniform_int_distribution<> disY(1, world->GetHeight());
		X = disX(gen);
		Y = disY(gen);
	} while (this->world->GetElement(X, Y) != EOF);
	identity = 'W';
	name = "Wolf";
	generation = 1;
}

Wolf::Wolf(World* world, int X, int Y, int generation) {
	this->world = world;
	initiative = 5;
	power = 9;
	this->X = X;
	this->Y = Y;
	identity = 'W';
	name = "Wolf";
	this->generation = generation;
}

Organism* Wolf::NewBorn(int X, int Y) {
	return new Wolf(world, X, Y, generation + 1);
}