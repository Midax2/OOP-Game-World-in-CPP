#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <fstream>
#include "Animals/Human.h"
#include "Animals/Wolf.h"
#include "Plants/Grass.h"
#include "Animals/Turtle.h"
#include "Plants/Guarana.h"
#include "Animals/Fox.h"
#include "Plants/Belladonna.h"
#include "Animals/Antelope.h"
#include "Plants/Dandelion.h"
#include "Plants/Heracleum.h"
#include "Animals/Sheep.h"
#define ESC 27
#define L_ARROW 75
#define UP_ARROW 72
#define R_ARROW 77
#define DOWN_ARROW 80
enum { Wolf_t, Turtle_t, Sheep_t, Fox_t, Antelope_t, Belladonna_t, Dandelion_t, Grass_t, Guarana_t, Heracleum_t };
class Game {
private:
	Human* player;
	World* world;
private:
	int GetRandomNumber(int from, int to);
	void Save();
	void Load();
	void gotoxy(int row, int column);
public:
	Game();
	void AddOrganismsToWorld();
	void PrintInfo();
	void Control();
};