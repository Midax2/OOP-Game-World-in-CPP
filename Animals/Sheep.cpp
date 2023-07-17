#include "Sheep.h"
Sheep::Sheep(World* world) {
	this->world = world;
	initiative = 4;
	power = 4;
	std::random_device rd;
	std::mt19937 gen(rd());
	do {
		std::uniform_int_distribution<> disX(1, world->GetWidth());
		std::uniform_int_distribution<> disY(1, world->GetHeight());
		X = disX(gen);
		Y = disY(gen);
	} while (this->world->GetElement(X, Y) != EOF);
	identity = 'S';
	name = "Sheep";
	generation = 1;
}

Sheep::Sheep(World* world, int X, int Y, int generation) {
	this->world = world;
	initiative = 4;
	power = 4;
	this->X = X;
	this->Y = Y;
	identity = 'S';
	name = "Sheep";
	this->generation = generation;
}

Organism* Sheep::NewBorn(int X, int Y) {
	return new Sheep(world, X, Y, generation + 1);
}