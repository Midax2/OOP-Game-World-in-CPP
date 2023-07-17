#pragma once
#include "../Organism.h"
class Animal : public Organism {
public:
	virtual void Action() override;
	virtual void Collision(Organism* organism) override;
};