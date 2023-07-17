#include "World.h"
#include "Organism.h"
World::World(int width, int height) {
	round = 1;
	this->height = height;
	this->width = width;
	WorldBoard = new char*[height + 2];
	for (int i = 0; i < height + 2; i++)
		WorldBoard[i] = new char[width + 2];
	for (int i = 0; i < (height + 2); i++) {
		for (int j = 0; j < (width + 2); j++) {
			if (i == 0 || i == height + 1) WorldBoard[i][j] = '-';
			else {
				if (j == 0 || j == width + 1) WorldBoard[i][j] = '|';
				else WorldBoard[i][j] = EOF;
			}
		}
	}
}

void World::SetOrganismOnPoint(int X, int Y, char identity) {
	WorldBoard[Y][X] = identity;
}

void World::SortOrganisms() {
	std::sort(organisms.begin(), organisms.end(), 
		[](Organism* a, Organism* b){
		return (a->GetInitiative() > b->GetInitiative() && a->GetGeneration() < b->GetGeneration()); });
}

void World::DoTurn() {
	for (int i = 0; i < organisms.size(); i++) {
		if (i >= organisms.size()) break;
		organisms[i]->Action();
		if (i >= organisms.size()) break;
		organisms[i]->Collision(organisms[i]->GetWorld()->GetOrganism(organisms[i], organisms[i]->GetX(), organisms[i]->GetY()));
		if (i >= organisms.size()) break;
		organisms[i]->Print();
	}
	round++;
	this->SortOrganisms();
}

void World::DeleteOrganism(Organism* something) {
	int index = -1;
	for (int i = 0; i < organisms.size(); i++) {
		if (something == organisms[i])
			index = i;
	}
	if (index != -1) organisms.erase(organisms.begin() + index);
}

void World::AddOrganism(Organism* something) {
	something->Print();
	organisms.push_back(something);
}

void World::PrintWorld() {
	for (int i = 0; i < height + 2; i++) {
		for (int j = 0; j < width + 2; j++) {
			std::cout << WorldBoard[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

char World::GetElement(int X, int Y) {
	return WorldBoard[Y][X];
}

std::vector<Organism*>* World::GetOrganisms() {
	return &organisms;
}

void World::AddMessage(std::string& name) {
	messages.push_back(name);
}

std::string World::GetMessage(int index) {
	if (index >= messages.size()) { return "Nothing"; };
	return messages[index];
}

void World::ClearMessages() {
	messages.clear();
}

Organism* World::GetOrganism(Organism* organismTest, int X, int Y) {
	for (auto organism : organisms) {
		if (organism->GetX() == X && organism->GetY() == Y && organism != organismTest)
			return organism;
	}
	return nullptr;
}

int World::GetHeight() {
	return height;
}

int World::GetWidth() {
	return width;
}

int World::GetRound() {
	return round;
}

void World::SetRound(int round) {
	this->round = round;
}

World::~World() {
	for (int i = 0; i < width + 2; i++)
		delete WorldBoard[i];
	delete WorldBoard;
	for (int i = 0; i < organisms.size(); i++) {
		delete organisms[i];
	}
	organisms.clear();
}