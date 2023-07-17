#include "Grass.h"
Grass::Grass(World* world) {
	this->world = world;
	initiative = 0;
	power = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	do {
		std::uniform_int_distribution<> disX(1, world->GetWidth());
		std::uniform_int_distribution<> disY(1, world->GetHeight());
		X = disX(gen);
		Y = disY(gen);
	} while (this->world->GetElement(X, Y) != EOF);
	identity = 'G';
	name = "Grass";
	generation = 1;
}

Grass::Grass(World* world, int X, int Y, int generation) {
	this->world = world;
	initiative = 0;
	power = 0;
	this->X = X;
	this->Y = Y;
	identity = 'G';
	name = "Grass";
	this->generation = generation;
}

Organism* Grass::NewBorn(int X, int Y) {
	return new Grass(world, X, Y, generation + 1);
}
