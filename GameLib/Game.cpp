#include "Game.hpp"

Game::Game(int difficulty) :
	TimedLayer()
{
	tags.insert("Game");
	switch (difficulty) {
		case 0:
			timeLimit = 240;
			numDoors = 16;
			numFloors = 4;
			break;
		case 1:
			timeLimit = 120;
			numDoors = 32;
			numFloors = 4;
			break;
		case 2:
			timeLimit = 60;
			numDoors = 48;
			numFloors = 6;
			break;
		default:
			timeLimit = 120;
			numDoors = 32;
			numFloors = 4;
			break;
	}
	createFloors(numFloors);
	int p_bez = 12;
	int player_floor = rand()%numFloors;
	int player_spawn_y = fheight* player_floor +p_bez;
	int pwidth = (1920 - Floor::bezel) / (numDoors / numFloors * 2);
	int player_spawn_x = Floor::bezel + rand() % pwidth * (1920 - Floor::bezel) / pwidth;
	Player* player = new Player(player_spawn_x+p_bez/2, player_spawn_y, pwidth - p_bez, fheight - Floor::height-p_bez, (1920.0f - Floor::bezel), Floor::bezel / 2, (1920 - Floor::bezel/2), player_floor,sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W);
	addEntity(player);
}

int Game::main()
{
	int res = TimedLayer::main();
	//Game Over
	if (gameTimer.getElapsedTime().asSeconds() > timeLimit)return 4;
	return res;
}

void Game::createFloors(int h)
{
	this->fheight = 1080 / h;
	int doorsPerFloor = numDoors / h;
	for (int i = 0; i < h; i++) {
		Floor* f = new Floor(i,fheight);
		addEntity(f);
	}
}

void Game::findBitArrays()
{
}

void Game::createDoors()
{
}

int Game::recieve(Layer& layer, int status)
{
	switch (status) {
		case -1:
			return -1;
		case 0:
			return 0;
		case 1://Player wins
		case 2://Players fails
		case 3://Grab timer data.
			break;
	}
	return 0;
}

void Game::notify(Layer& layer, int status)
{
}
