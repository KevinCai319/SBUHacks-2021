#include "Game.hpp"

Game::Game(int difficulty)
{
	switch (difficulty) {
		case 0:
			timeLimit = 240;
			break;
		case 1:
			timeLimit = 120;
			break;
		case 2:
			timeLimit = 60;
			break;
		default:
			timeLimit = 120;
			break;
	}
}

int Game::main()
{
	int res =TimedLayer::main();
	if (res) return res;

	return 0;
}

void Game::createFloors()
{
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
		case 3://Update opened doors.
	}
	return 0;
}

void Game::notify(Layer& layer, int status)
{
}
