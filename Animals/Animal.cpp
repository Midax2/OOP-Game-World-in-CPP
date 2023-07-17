#include "Animal.h"
void Animal::Action() {
	SetPrevX(GetX());
	SetPrevY(GetY());
	GetWorld()->SetOrganismOnPoint(GetX(), GetY(), EOF);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, DOWN + 1);
	int turn = dis(gen);
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

void Animal::Collision(Organism* organism) {
	if (organism == nullptr)
		return;
	if (GetIdentity() == organism->GetIdentity()) {
		if (GetGeneration() != organism->GetGeneration()) return;
		SetX(GetPrevX());
		SetY(GetPrevY());
		for (int i = GetX() - 1; i <= GetX() + 1; i++) {
			for (int j = GetY() - 1; j <= GetY() + 1; j++) {
				if (GetWorld()->GetElement(i, j) == EOF) {
					GetWorld()->AddOrganism(NewBorn(i, j));
					std::string message = "New ";
					message += GetName();
					message += " was born";
					world->AddMessage(message);
					return;
				}
			}
		}
	}
	else {
		if (organism->IsEatenDebuff(GetMe())) {
			organism->Collision(GetMe());
			return;
		}
		if (GetPower() >= organism->GetPower()) {
			if (organism->Defend(GetMe())) {
				organism->Collision(GetMe());
				return;
			}
			organism->GetWorld()->DeleteOrganism(organism);
			std::string message;
			message += organism->GetName();
			message += " was kiled by ";
			message += GetName();
			world->AddMessage(message);
			delete organism;
		}
		else {
			if (RunAway(organism)) {
				GetMe()->Collision(organism);
				return;
			}
			GetWorld()->DeleteOrganism(GetMe());
			std::string message;
			message += GetName();
			message += " was kiled by ";
			message += organism->GetName();
			world->AddMessage(message);
			delete GetMe();
		}
	}
}