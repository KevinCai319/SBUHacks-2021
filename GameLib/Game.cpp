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
			timeLimit = 5;
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
	srand(std::time(NULL));
	int player_floor = rand()%numFloors;
	int pheight = fheight - Floor::height - p_bez;
	int player_spawn_y = 1080 - (fheight * (player_floor)) - Floor::height - pheight;
	int pwidth = numFloors*(1920 - Floor::bezel) / (2*numDoors) -p_bez;
	int player_spawn_x = Floor::bezel / 2 + (rand()%pwidth) * ((1920 - Floor::bezel) / pwidth);
	Player* player = new Player(player_spawn_x, player_spawn_y, pwidth, pheight, (1920.0f - Floor::bezel), Floor::bezel / 2, (1920 - Floor::bezel/2), player_floor,sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W);
	addEntity(player);
	createEntities();
	createTeleporters();
}

int Game::main()
{
	int res = TimedLayer::main();
	//Game Over
	if (gameTimer.getElapsedTime().asSeconds() > timeLimit)return 7;
	return res;
}

void Game::createFloors(int h)
{
	this->fheight = 1080 / h;
	int doorsPerFloor = numDoors / h;
	for (int i = 0; i < h; i++) {
		Floor* f = new Floor(i,fheight,doorsPerFloor);
		addEntity(f);
	}
}

void Game::findBitArrays()
{
}

void Game::createDoors()
{
}

void Game::createTeleporters()
{
	std::set<Layer*> floors = getTag("Floor");
	int W = (1920-Floor::bezel)/(numDoors / numFloors);
	int H = fheight / 6;
	std::vector<Teleporter*> tp;
	for (Layer* floor : floors) {
		//std::cout << "cool" << std::endl;
		tp.push_back(dynamic_cast<Floor*>(floor)->placeT(W,H));
		tp.push_back(dynamic_cast<Floor*>(floor)->placeT(W,H));
	}
	int i = 0;
	int j = 0;
	std::vector<int> available;
	available.resize(numFloors+1);
	for (int k:available) {
		k = 0;
	}
	int s = tp.size();
	while(!tp.size()==0) {
		i = rand() % (s);
		j = rand() % (s);
		while (i==j||tp[i]->floor == tp[j]->floor || available[tp[i]->floor]>1 || available[tp[j]->floor] >1) {
			i = rand() % (s);
			j = rand() % (s);
		}
		tp[i]->updateLinked(tp[j]);
		tp[j]->updateLinked(tp[i]);
		addEntity(tp[i]);
		addEntity(tp[j]);
		available[tp[i]->floor]++;
		available[tp[j]->floor]++;
		if (i > j) {
			tp.erase(tp.begin() + i);
			tp.erase(tp.begin() + j);
		}else {
				tp.erase(tp.begin() + j);
				tp.erase(tp.begin() + i);

		}
		s -= 2;
	}
	
}

int Game::recieve(Layer& layer, int status)
{
	switch (status) {
		case -1:
			return -1;
		case 0:
			return 0;
		case 1://Player wins
			return 10;
		case 4://Players fails
			return 7;
		case 3://Grab timer data.

			break;
	}
	return 0;
}

void Game::notify(Layer& layer, int status)
{
}
