#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <random>
enum { LEFT, UP, RIGHT, DOWN, NONE };
class Organism;
class World {
private:
	int height;
	int width;
	int round;
	char** WorldBoard;
	std::vector<Organism*> organisms;
	std::vector<std::string> messages;
public:
	World(int width, int height);
	void SetOrganismOnPoint(int X, int Y, char identity);
	void SortOrganisms();
	void DeleteOrganism(Organism* something);
	void AddOrganism(Organism* something);
	void DoTurn();
	void PrintWorld();
	char GetElement(int X, int Y);
	std::vector<Organism*>* GetOrganisms();
	void AddMessage(std::string& message);
	std::string GetMessage(int index);
	void ClearMessages();
	Organism* GetOrganism(Organism* organismTest, int X, int Y);
	int GetHeight();
	int GetWidth();
	int GetRound();
	void SetRound(int round);
	~World();
};