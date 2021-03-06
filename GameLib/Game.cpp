#include "Game.hpp"
#include "Dimension.h"

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
			numFloors = 4; break;
	}
	createFloors(numFloors);
    fontptr = new sf::Font(); 
	fontptr->loadFromFile("Assets\\youmurdererbb_reg.ttf"); 
	timeLabel.setFont(*fontptr); 
	timeLabel.setPosition(0, 0); 
	timeLabel.setCharacterSize(BUTTON_SIZE); 
	timeLabel.setFillColor(sf::Color::White); 

	attemptsLabel.setFont(*fontptr);
	attemptsLabel.setPosition(0,WIN_HEIGHT*.75);
	attemptsLabel.setCharacterSize(BUTTON_SIZE);
	attemptsLabel.setFillColor(sf::Color::White);
	attemptsLabel.setString("Attempts\nLeft:\n3");

	clueLabel.setFont(*fontptr); 
	clueLabel.setPosition(WIN_WIDTH - Floor::bezel / 2, 0); 
	clueLabel.setCharacterSize(BUTTON_SIZE); 
	clueLabel.setFillColor(sf::Color::White); 

	gameTimer.restart();
	updateTimer();
	srand(std::time(NULL));
	createPlayer(sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::S, sf::Keyboard::W,true);
	createPlayer(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Down, sf::Keyboard::Up,false);
	createEntities();
	createTeleporters();
	createDoors(); 
}

int Game::main()
{
	int res = TimedLayer::main();
	//Game Over
	if (gameTimer.getElapsedTime().asSeconds() > timeLimit)return 7;
	updateTimer(); 
	updateClue(); 
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

void Game::createClues(const Door* door)
{
	const std::string COLORS[] = {"Yellow", "Red", "Green", "Blue", "Magenta", "Cyan"};
	const std::string SHAPES[] = {"H Line", "Square", "Circle", "V Line"};

	if (door->id % 2 == 0)
		clues.push_back("Door is \n even");
	else
		clues.push_back("Door is \n odd");

	if (door->floor % 2 == 0)
		clues.push_back("Door is \n on even \n floor");
	else
		clues.push_back("Door is \n on odd \n floor"); 

	clues.push_back("Door is \n" + COLORS[door->color]); 
	clues.push_back("Door is \n" + SHAPES[door->shape]);
}

void Game::createDoors()
{
	int doorsOnFloor = numDoors / numFloors;
	float spcW = (Floor::width * .5) / doorsOnFloor;
	float dwidth = spcW * 0.8;
	float dheight = (fheight-Floor::height) * 0.75;
	int id = 1;
	int safe = rand() % numDoors + 1; 
	for (int f = 0; f < numFloors; ++f)
	{
		float sy = 1080-f*fheight-Floor::height - dheight;  
		float left = Floor::bezel / 2 + spcW * 0.1;
		for (int d = 0; d < doorsOnFloor; ++d)
		{
			Door* door = new Door(left, sy, dwidth, dheight, f, rand() % 6, rand() % 4, id); 
			door->isGood = id == safe; 
			if (id == safe)
				createClues(door); 
			addEntity(door); 
			left += spcW*2;
			id++;
		}
	}
}

void Game::updateTimer()
{
	float timeLeft = timeLimit - gameTimer.getElapsedTime().asSeconds(); 
	timeLabel.setString(std::to_string((int) timeLeft)); 
}

void Game::updateClue()
{
	int clueNo = (int) (gameTimer.getElapsedTime().asSeconds() / (timeLimit / (clues.size() + 1))); 
	clueLabel.setString(clues[clueNo]); 
}

int Game::recieve(Layer& layer, int status)
{
	switch (status) {
		case -1:
			return -1;
		case 0:
			return 0;
		case 1://Player guesses correct door
			return 10;
		case 2://Player guesses incorrect door
			doorsOpened++;
			attemptsLabel.setString("Attempts\nLeft:\n"+std::to_string(3-doorsOpened));
			if (doorsOpened > 2) {//3 tries and ur out
				return 7;
			}else {
				return 0;
			}
		case 3://Player gets caught.
			return 7;

			break;
	}
	return 0;
}

void Game::notify(Layer& layer, int status)
{
}

void Game::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(timeLabel, states); 
	target.draw(attemptsLabel, states);
	target.draw(clueLabel, states); 
}

void Game::createPlayer(sf::Keyboard::Key L, sf::Keyboard::Key R, sf::Keyboard::Key T,sf::Keyboard::Key D,bool isFriendly)
{
	int p_bez = 12;
	int player_floor = rand() % numFloors;
	int pheight = (fheight - (Floor::height - p_bez)) * .67;
	int player_spawn_y = 1080 - (fheight * (player_floor)) - Floor::height - pheight;
	int pwidth = numFloors * (1920 - Floor::bezel) / (2 * numDoors) - p_bez;
	int player_spawn_x = Floor::bezel / 2 + (rand() % pwidth) * ((1920 - Floor::bezel) / pwidth);
	Player* player = new Player(player_spawn_x, player_spawn_y, pwidth, pheight, (1920.0f - Floor::bezel), Floor::bezel / 2, (1920 - Floor::bezel / 2), player_floor, L,R,T,D);
	if (!isFriendly) {
		player->type = 1;
	}
	addEntity(player);
}
