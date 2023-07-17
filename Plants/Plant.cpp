#include "Plant.h"
void Plant::Action() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 9999);
	int posibility = dis(gen);
	if (posibility % 36 == 0) {
		std::uniform_int_distribution<> dis(0, 8);
		int pos = dis(gen);
		int count = 0;
		for (int i = GetX() - 1; i <= GetX() + 1; i++) {
			for (int j = GetY() - 1; j <= GetY() + 1; j++) {
				if (GetWorld()->GetElement(i, j) == EOF && count == pos) {
					GetWorld()->AddOrganism(NewBorn(i, j));
					return;
				}
				count++;
			}
		}
	}
}

void Plant::Collision(Organism* organism) {
	if (organism == nullptr)
		return;
	if (organism->IsEatenDebuff(GetMe())) {
		organism->Collision(GetMe());
		return;
	}
	if (GetPower() > organism->GetPower()) {
		organism->GetWorld()->DeleteOrganism(organism);
		std::string message;
		message += organism->GetName();
		message += " was kiled by ";
		message += GetName();
		world->AddMessage(message);
		delete organism;
	}
	else {
		GetWorld()->DeleteOrganism(GetMe());
		std::string message;
		message += GetName();
		message += " was kiled by ";
		message += organism->GetName();
		world->AddMessage(message);
		delete GetMe();
	}
}