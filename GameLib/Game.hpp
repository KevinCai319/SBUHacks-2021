#pragma once
#include <vector>
#include <string>
#include "Floor.hpp"
#include "Door.hpp"
#include "Teleporter.hpp"
#include "Player.hpp"
#include "TimedLayer.hpp"
class Game:public TimedLayer{
	public:
		Game(int difficulty);
		virtual int main() override;
	protected:
		//Number of Doors
		int numDoors;
		//Number of Floors
		int numFloors;
		//Doors opened.
		int doorsOpened = 0;
		//Floor height(in pixels)
		int fheight = 125;
		//Default player speed.(250px/s)
		const int defaultPSpeed = 250;
		//Default player speed.(125px/s)
		const int defaultESpeed = 125;
		//Labels for the player before they die.
		sf::Font* fontptr; 
		sf::Text timeLabel; 
		sf::Text attemptsLabel;
		//Time left before game over.
		sf::Clock gameTimer;
		float timeLimit = 60;
		// Clues for each door 
		std::vector<std::string> clues; 
		//At the start, there will be a grace period for the player to move around.
		bool isStart = true;
		//Generate platforms/Ground, teleporters.
		void createFloors(int h);
		//Find subset of all bit arrays to use.
		void findBitArrays();
		//Create door based on bit arrays.
		void createTeleporters();
		void createClues(const Door* door); 
		void createDoors(); 
		void updateTimer(); 
		virtual int recieve(Layer& layer, int status) override;
		virtual void notify(Layer& layer, int status) override;
		virtual void render(sf::RenderTarget& target, sf::RenderStates states) const override; 
		void createPlayer(sf::Keyboard::Key L, sf::Keyboard::Key R, sf::Keyboard::Key T, sf::Keyboard::Key D, bool isFriendly);
};

