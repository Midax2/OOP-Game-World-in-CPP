#include "Turtle.h"
Turtle::Turtle(World* world) {
	this->world = world;
	initiative = 1;
	power = 2;
	std::random_device rd;
	std::mt19937 gen(rd());
	do {
		std::uniform_int_distribution<> disX(1, world->GetWidth());
		std::uniform_int_distribution<> disY(1, world->GetHeight());
		X = disX(gen);
		Y = disY(gen);
	} while (this->world->GetElement(X, Y) != EOF);
	identity = 'T';
	name = "Turtle";
	generation = 1;
	isMoving = false;
}

Turtle::Turtle(World* world, int X, int Y, int generation) {
	this->world = world;
	initiative = 1;
	power = 2;
	this->X = X;
	this->Y = Y;
	identity = 'T';
	name = "Turtle";
	this->generation = generation;
	isMoving = false;
}

void Turtle::Action() {
	isMoving = false;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> IsMoving(1, 4);
	if (IsMoving(gen) == 4) {
		Animal::Action();
	}
	isMoving = true;
}

void Turtle::Collision(Organism* organism) {
	if (organism == nullptr) return;
	if (!isMoving) {
		organism->SetX(organism->GetPrevX());
		organism->SetY(organism->GetPrevY());
		std::string message;
		message += organism->GetName();
		message += " was pushed back to his previous position by Turtle";
		world->AddMessage(message);
	}
	else {
		Animal::Collision(organism);
	}
	isMoving = false;
}

bool Turtle::Defend(Organism* organism) {
	if (organism->GetPower() <= 5) return true;
	else return false;
}

Organism* Turtle::NewBorn(int X, int Y) {
	return new Turtle(world, X, Y, generation + 1);
}

bool Turtle::GetIsMoving() {
	return isMoving;
}

void Turtle::SetIsMoving(bool move) {
	this->isMoving = move;
}