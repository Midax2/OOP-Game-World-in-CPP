#include "Game.h"
Game::Game() {
	std::cout << "Enter height and width of game field\n";
	int temp_h, temp_w;
	std::cin >> temp_h >> temp_w;
	world = new World(temp_w, temp_h);
	player = new Human(world);
}

void Game::AddOrganismsToWorld() {
	world->AddOrganism(player);
	for (int organism = Wolf_t; organism <= Heracleum_t; organism++) {
		int random = GetRandomNumber(1, 10);
		for (int j = 0; j < random; j++) {
			switch (organism) {
			case Wolf_t:
				world->AddOrganism(new Wolf(world));
				break;
			case Turtle_t:
				world->AddOrganism(new Turtle(world));
				break;
			case Sheep_t:
				world->AddOrganism(new Sheep(world));
				break;
			case Fox_t:
				world->AddOrganism(new Fox(world));
				break;
			case Antelope_t:
				world->AddOrganism(new Antelope(world));
				break;
			case Belladonna_t:
				world->AddOrganism(new Belladonna(world));
				break;
			case Dandelion_t:
				world->AddOrganism(new Dandelion(world));
				break;
			case Grass_t:
				world->AddOrganism(new Grass(world));
				break;
			case Guarana_t:
				world->AddOrganism(new Guarana(world));
				break;
			case Heracleum_t:
				world->AddOrganism(new Heracleum(world));
				break;
			}
		}
	}
}

int Game::GetRandomNumber(int from, int to) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> Random(from, to);
	return Random(gen);
}

void Game::PrintInfo() {
	std::string legend[] = { "H - Human", "T - Turtle", "W - Wolf", "S - Sheep", "F - Fox", "A - Antelope",
	"B - Belladonna", "D - Dandelion", "G - Grass", "U - Guarana", "M - Heracleum"};
	int size_l = sizeof(legend) / sizeof(legend[0]);
	gotoxy(1, 2 * world->GetWidth() + 10);
	_cputs("Organisms:");
	for (int i = 0; i < size_l; i++) {
		gotoxy(i + 2, 2 * world->GetWidth() + 10);
		const char* cstr = legend[i].c_str();
		_cputs(cstr);
	}

	std::string controls[] = { "Arrows - Choose direction for human", "t - Make a turn", "s - Save the game", "l - Load the game", "p - Use super power"};
	int size_c = sizeof(controls) / sizeof(controls[0]);
	gotoxy(size_l + 3, 2 * world->GetWidth() + 10);
	_cputs("Controls:");
	for (int i = 0; i < size_c; i++) {
		gotoxy(size_l + i + 4, 2 * world->GetWidth() + 10);
		const char* cstr = controls[i].c_str();
		_cputs(cstr);
	}

	gotoxy(size_l + size_c + 6, 2 * world->GetWidth() + 10);
	_cputs("Game status:");
	gotoxy(size_l + size_c + 7, 2 * world->GetWidth() + 10);
	_cputs("Player/Creator: Dmytro Dzhusov nr. 196751");
	gotoxy(size_l + size_c + 8, 2 * world->GetWidth() + 10);
	std::string round = "Round: " + std::to_string(world->GetRound());
	const char* cstr = round.c_str();
	_cputs(cstr);
	gotoxy(size_l + size_c + 9, 2 * world->GetWidth() + 10);
	if (player->GetPower() == 5) _cputs("Super power is awaiable");
	else _cputs("Super power is not awaiable");

	gotoxy(world->GetHeight() + 4, 1);
	_cputs("Logs:");
	for (int i = 0; true; i++) {
		gotoxy(world->GetHeight() + 5 + i, 1);
		std::string text = world->GetMessage(i);
		if (text == "Nothing") break;
		const char* cstr = text.c_str();
		_cputs(cstr);
	}
	world->ClearMessages();
}

void Game::gotoxy(int row, int column) {
	printf("\033[%d;%dH", row, column);
}

void Game::Control() {
	while (true) {
		system("CLS");
		world->PrintWorld();
		PrintInfo();
		int code = _getch();
		switch (code) {
		case L_ARROW:
			player->SetTurn(LEFT);
			break;
		case UP_ARROW:
			player->SetTurn(UP);
			break;
		case R_ARROW:
			player->SetTurn(RIGHT);
			break;
		case DOWN_ARROW:
			player->SetTurn(DOWN);
			break;
		case 't':
			world->DoTurn();
			player->SetTurn(NONE);
			break;
		case 'p':
			player->ChangeSuperPower();
			break;
		case 's':
			Save();
			break;
		case 'l':
			Load();
			break;
		case ESC:
			return;
			break;
		}
	}
}

void Game::Save() {
	std::ofstream save;
	std::string saveName;
	system("CLS");
	std::cout << "Enter the name of the saved file\n";
	std::cin >> saveName;
	save.open(saveName, std::ios::out);
	std::vector<Organism*> orgs = *world->GetOrganisms();
	save << world->GetRound();
	save << " ";
	save << world->GetHeight();
	save << " ";
	save << world->GetWidth();
	save << " ";
	for (int i = 0; i < orgs.size(); i++) {
		save << orgs[i]->GetIdentity();
		save << " ";
		save << orgs[i]->GetX();
		save << " ";
		save << orgs[i]->GetY();
		save << " ";
		save << orgs[i]->GetGeneration();
		save << " ";
		save << orgs[i]->GetPower();
		save << " ";
		if (orgs[i]->GetIdentity() == 'H') {
			save << dynamic_cast<Human*>(orgs[i])->GetSuperPower();
			save << " ";
		}
		if (orgs[i]->GetIdentity() == 'A') {
			save << dynamic_cast<Antelope*>(orgs[i])->GetIsRuning();
			save << " ";
		}
		if (orgs[i]->GetIdentity() == 'T') {
			save << dynamic_cast<Turtle*>(orgs[i])->GetIsMoving();
			save << " ";
		}
	}
	save.close();
}

void Game::Load() {
	std::ifstream load;
	std::string saveName;
	system("CLS");
	std::cout << "Enter the name for the save file\n";
	std::cin >> saveName;
	load.open(saveName);
	if (!load) return;
	int temp_h, temp_w, round;
	load >> round;
	load >> temp_h;
	load >> temp_w;
	if (world != nullptr) delete world;
	world = new World(temp_w, temp_h);
	world->SetRound(round);
	while (!load.eof()) {
		char identity;
		int X, Y, Gen, Power;
		load >> identity;
		load >> X;
		load >> Y;
		load >> Gen;
		load >> Power;
		switch (identity) {
		case 'H':
		{
			player = new Human(world, X, Y, Gen);
			world->AddOrganism(player);
			player->SetPower(Power);
			bool SuperPower;
			load >> SuperPower;
			player->SetSuperPower(SuperPower);
			break;
		}
		case 'W':
		{
			Wolf* wolf = new Wolf(world, X, Y, Gen);
			world->AddOrganism(wolf);
			wolf->SetPower(Power);
			break;
		}
		case 'A':
		{
			Antelope* antelope = new Antelope(world, X, Y, Gen);
			world->AddOrganism(antelope);
			antelope->SetPower(Power);
			bool isRuning;
			load >> isRuning;
			antelope->SetIsRuning(isRuning);
			break;
		}
		case 'F':
		{
			Fox* fox = new Fox(world, X, Y, Gen);
			world->AddOrganism(fox);
			fox->SetPower(Power);
			break;
		}
		case 'S':
		{
			Sheep* sheep = new Sheep(world, X, Y, Gen);
			world->AddOrganism(sheep);
			sheep->SetPower(Power);
			break;
		}
		case 'T':
		{
			Turtle* turtle = new Turtle(world, X, Y, Gen);
			world->AddOrganism(turtle);
			turtle->SetPower(Power);
			bool isMoving;
			load >> isMoving;
			turtle->SetIsMoving(isMoving);
			break;
		}
		case 'B':
		{
			Belladonna* belladonna = new Belladonna(world, X, Y, Gen);
			world->AddOrganism(belladonna);
			break;
		}
		case 'D':
		{
			Dandelion* dandelion = new Dandelion(world, X, Y, Gen);
			world->AddOrganism(dandelion);
			break;
		}
		case 'G':
		{
			Grass* grass = new Grass(world, X, Y, Gen);
			world->AddOrganism(grass);
			break;
		}
		case 'U':
		{
			Guarana* guarana = new Guarana(world, X, Y, Gen);
			world->AddOrganism(guarana);
			break;
		}
		case 'M':
		{
			Heracleum* heracleum = new Heracleum(world, X, Y, Gen);
			world->AddOrganism(heracleum);
			break;
		}
		}
	}
	load.close();
}