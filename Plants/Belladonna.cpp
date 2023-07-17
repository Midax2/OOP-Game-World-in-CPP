#include "Belladonna.h"
Belladonna::Belladonna(World* world) {
	this->world = world;
	initiative = 0;
	power = 99;
	std::random_device rd;
	std::mt19937 gen(rd());
	do {
		std::uniform_int_distribution<> disX(1, world->GetWidth());
		std::uniform_int_distribution<> disY(1, world->GetHeight());
		X = disX(gen);
		Y = disY(gen);
	} while (this->world->GetElement(X, Y) != EOF);
	identity = 'B';
	name = "Belladonna";
	generation = 1;
}

Belladonna::Belladonna(World* world, int X, int Y, int generation) {
	this->world = world;
	initiative = 0;
	power = 99;
	this->X = X;
	this->Y = Y;
	identity = 'B';
	name = "Belladonna";
	this->generation = generation;
}

void Belladonna::Collision(Organism* organism) {
	if (organism == nullptr) return;
	world->DeleteOrganism(GetMe());
	world->DeleteOrganism(organism);
	std::string message;
	message += organism->GetName();
	message += " dead after eating Belladona";
	world->AddMessage(message);
	delete organism;
	delete GetMe();
}

Organism* Belladonna::NewBorn(int X, int Y) {
	return new Belladonna(world, X, Y, generation + 1);
}

bool Belladonna::IsEatenDebuff(Organism* organism) {
	return true;
}