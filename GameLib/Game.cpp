#include "Game.hpp"

Game::Game(int difficulty)
{
	tags.insert("Game");
	switch (difficulty) {
		case 0:
			timeLimit = 240;
			numDoors = 16;
			createFloors(4);
			break;
		case 1:
			timeLimit = 120;
			numDoors = 32;
			createFloors(4);
			break;
		case 2:
			timeLimit = 60;
			numDoors = 48;
			createFloors(6);
			break;
		default:
			timeLimit = 120;
			numDoors = 32;
			createFloors(4);
			break;
	}
}

int Game::main()
{
	int res =TimedLayer::main();
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
