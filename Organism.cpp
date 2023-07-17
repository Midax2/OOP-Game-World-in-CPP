#include "Organism.h"
World* Organism::GetWorld() {
	return world;
}

Organism* Organism::GetMe() {
	return this;
}

int Organism::GetInitiative() {
	return initiative;
}

int Organism::GetPower() {
	return power;
}

std::string Organism::GetName() {
	return name;
}

void Organism::SetPower(int power) {
	this->power = power;
}

int Organism::GetX() {
	return X;
}

int Organism::GetY() {
	return Y;
}

void Organism::SetX(int X) {
	this->X = X;
}

void Organism::SetY(int Y) {
	this->Y = Y;
}

int Organism::GetPrevX() {
	return prev_X;
}

int Organism::GetPrevY() {
	return prev_Y;
}

void Organism::SetPrevX(int X) {
	this->prev_X = X;
}

void Organism::SetPrevY(int Y) {
	this->prev_Y = Y;
}

char Organism::GetIdentity() {
	return identity;
}

int Organism::GetGeneration() {
	return generation;
}

void Organism::Print() {
	GetWorld()->SetOrganismOnPoint(GetX(), GetY(), GetIdentity());
}

bool Organism::Defend(Organism* organism) {
	return false;
}
bool Organism::RunAway(Organism* organism) {
	return false;
}
bool Organism::IsEatenDebuff(Organism* organism) {
	return false;
}