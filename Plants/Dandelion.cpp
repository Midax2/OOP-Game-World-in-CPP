#include "Dandelion.h"
Dandelion::Dandelion(World* world) {
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
	identity = 'D';
	name = "Dandelion";
	generation = 1;
}

Dandelion::Dandelion(World* world, int X, int Y, int generation) {
	this->world = world;
	initiative = 0;
	power = 0;
	this->X = X;
	this->Y = Y;
	identity = 'D';
	name = "Dandelion";
	this->generation = generation;
}

void Dandelion::Action() {
	for (int trying = 0; trying < 3; trying++) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> IsMoving(1, 2);
		if (IsMoving(gen) == 2) {
			Plant::Action();
			break;
		}
	}
}

Organism* Dandelion::NewBorn(int X, int Y) {
	return new Dandelion(world, X, Y, generation + 1);
}