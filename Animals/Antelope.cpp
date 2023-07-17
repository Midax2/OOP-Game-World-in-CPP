#include "Antelope.h"
Antelope::Antelope(World* world) {
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
	identity = 'A';
	name = "Antelope";
	generation = 1;
	isRuning = false;
}

Antelope::Antelope(World* world, int X, int Y, int generation) {
	this->world = world;
	initiative = 4;
	power = 4;
	this->X = X;
	this->Y = Y;
	identity = 'A';
	name = "Antelope";
	this->generation = generation;
	isRuning = false;
}

void Antelope::Action() {
	Animal::Action();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> SecondMove(1, 2);
	if (SecondMove(gen) == 2) {
		Animal::Action();
	}
}

void Antelope::Collision(Organism* organism) {
	if (organism == nullptr) return;
	if (isRuning) {
		if (organism->GetPower() > GetPower()) {
			for (int i = GetY() - 1; i <= GetY() + 1; i++) {
				for (int j = GetX() - 1; j <= GetX() + 1; j++) {
					if (world->GetElement(j, i) == EOF) {
						SetX(j);
						SetY(i);
						isRuning = false;
						std::string message = "Antelope runed away from ";
						message += organism->GetName();
						world->AddMessage(message);
						return;
					}
				}
			}
		}
	}
	Animal::Collision(organism);
}

Organism* Antelope::NewBorn(int X, int Y) {
	return new Antelope(world, X, Y, generation + 1);
}

bool Antelope::RunAway(Organism* organism) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> RunedAway(1, 2);
	if (RunedAway(gen) == 2) {
		isRuning = true;
		return true;
	}
	else return false;
}

bool Antelope::GetIsRuning() {
	return isRuning;
}

void Antelope::SetIsRuning(bool run) {
	this->isRuning = run;
}