#include "Heracleum.h"
Heracleum::Heracleum(World* world) {
	this->world = world;
	initiative = 0;
	power = 10;
	std::random_device rd;
	std::mt19937 gen(rd());
	do {
		std::uniform_int_distribution<> disX(1, world->GetWidth());
		std::uniform_int_distribution<> disY(1, world->GetHeight());
		X = disX(gen);
		Y = disY(gen);
	} while (this->world->GetElement(X, Y) != EOF);
	identity = 'M';
	name = "Heracleum";
	generation = 1;
}

Heracleum::Heracleum(World* world, int X, int Y, int generation) {
	this->world = world;
	initiative = 0;
	power = 10;
	this->X = X;
	this->Y = Y;
	identity = 'M';
	name = "Heracleum";
	this->generation = generation;
}

void Heracleum::Action() {
	for (int i = GetY() - 1; i <= GetY() + 1; i++) {
		for (int j = GetX() - 1; j <= GetX() + 1; j++) {
			if (world->GetOrganism(GetMe(), j, i) != nullptr) {
				Organism* org = world->GetOrganism(GetMe(), j, i);
				if (org->GetPower() > 0) {
					world->DeleteOrganism(org);
					delete org;
				}
			}
		}
	}
}

void Heracleum::Collision(Organism* organism) {
	if (organism == nullptr) return;
	world->DeleteOrganism(GetMe());
	world->DeleteOrganism(organism);
	std::string message;
	message += organism->GetName();
	message += " dead after eating Heracleum";
	world->AddMessage(message);
	delete organism;
	delete GetMe();
}

Organism* Heracleum::NewBorn(int X, int Y) {
	return new Heracleum(world, X, Y, generation + 1);
}

bool Heracleum::IsEatenDebuff(Organism* organism) {
	return true;
}