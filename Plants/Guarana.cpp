#include "Guarana.h"
Guarana::Guarana(World* world) {
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
	identity = 'U';
	name = "Guarana";
	generation = 1;
}

Guarana::Guarana(World* world, int X, int Y, int generation) {
	this->world = world;
	initiative = 0;
	power = 0;
	this->X = X;
	this->Y = Y;
	identity = 'U';
	name = "Guarana";
	this->generation = generation;
}

void Guarana::Collision(Organism* organism) {
	if (organism == nullptr) return;
	organism->SetPower(organism->GetPower() + 3);
	world->DeleteOrganism(GetMe());
	std::string message;
	message += organism->GetName();
	message += " has eaten Guarana and got 3 more power";
	world->AddMessage(message);
	delete GetMe();
}

Organism* Guarana::NewBorn(int X, int Y) {
	return new Guarana(world, X, Y, generation + 1);
}

bool Guarana::IsEatenDebuff(Organism* organism) {
	return true;
}