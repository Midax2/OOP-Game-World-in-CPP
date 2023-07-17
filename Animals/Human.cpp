#include "Human.h"
Human::Human(World *world) {
	this->world = world;
	initiative = 4;
	power = 5;
	turn = NONE;
	super_power = false;
	std::random_device rd;
	std::mt19937 gen(rd());
	do {
		std::uniform_int_distribution<> disX(1, world->GetWidth());
		std::uniform_int_distribution<> disY(1, world->GetHeight());
		X = disX(gen);
		Y = disY(gen);
	} while (this->world->GetElement(X, Y) != EOF);
	identity = 'H';
	name = "Human";
	generation = 1;
}

Human::Human(World* world, int X, int Y, int generation) {
	this->world = world;
	initiative = 4;
	power = 5;
	this->X = X;
	this->Y = Y;
	turn = NONE;
	super_power = false;
	identity = 'H';
	name = "Human";
	this->generation = generation;
}

void Human::Action() {
	SetPrevX(GetX());
	SetPrevY(GetY());
	GetWorld()->SetOrganismOnPoint(GetX(), GetY(), EOF);
	switch (turn) {
	case LEFT:
		if (GetX() - 1 >= 1) SetX(GetX() - 1);
		break;
	case UP:
		if (GetY() - 1 >= 1) SetY(GetY() - 1);
		break;
	case RIGHT:
		if (GetX() + 1 <= GetWorld()->GetWidth()) SetX(GetX() + 1);
		break;
	case DOWN:
		if (GetY() + 1 <= GetWorld()->GetHeight()) SetY(GetY() + 1);
		break;
	}
}

void Human::Collision(Organism* organism) {
	if (super_power) {
		power += 5;
		super_power = !super_power;
		Animal::Collision(organism);
		return;
	}
	if (!super_power && power > 5) {
		power--;
	}
	Animal::Collision(organism);
}

int Human::GetTurn() {
	return turn;
}

void Human::SetTurn(int turn) {
	this->turn = turn;
}

void Human::ChangeSuperPower() {
	if (power == 5) {
		super_power = !super_power;
	}
}

Organism* Human::NewBorn(int X, int Y) {
	return new Human(world, X, Y, generation + 1);
}

bool Human::GetSuperPower() {
	return super_power;
}

void Human::SetSuperPower(bool power) {
	this->super_power = power;
}