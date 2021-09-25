#pragma once
#include "TimedLayer.hpp"
#include "Floor.hpp"
#include "Door.hpp"
#include "Teleporter.hpp"
class Game:public TimedLayer{
	public:
		Game(int difficulty);
		virtual int main() override;
	protected:
		//Number of Doors
		int numDoors;
		//Doors opened.
		int doorsOpened = 0;
		//Floor height(in pixels)
		int fheight = 125;
		//Labels for the player before they die.
		sf::Text timeLabel;
		sf::Clock gameTimer;
		//Time left before game over.
		float timeLimit = 60;
		//At the start, there will be a grace period for the player to move around.
		bool isStart = true;
		//Generate platforms/Ground, teleporters.
		void createFloors(int h);
		//Find subset of all bit arrays to use.
		void findBitArrays();
		//Create door based on bit arrays.
		void createDoors();
		virtual int recieve(Layer& layer, int status) override;
		virtual void notify(Layer& layer, int status) override;
};

