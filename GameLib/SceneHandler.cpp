#include <iostream>

#include "SceneHandler.hpp"
#include "MainMenu.hpp"
#include "DifficultySelect.hpp"
#include "Manual.hpp"
#include "Game.hpp"

SceneHandler::SceneHandler(int x, int y, const std::string& title,Layer* layer) :
	WindowHandler(x,y,title,layer)
{
	tags.insert("Root");
}

int SceneHandler::recieve(Layer& layer, int status)
{
	switch (status) {
		case 0:
			return status;//Exit
		case MENU: 
			switchScene(new MainMenu()); 
			return 0; 
		case DIFFICULTY:
			switchScene(new DifficultySelect()); 
			return 0;
		case MANUAL:
			switchScene(new Manual()); 
			return 0;
		case EASY:
			switchScene(new Game(0));
			return 0;
		case NORMAL:
			switchScene(new Game(1));
			return 0;
		case DEATH:
			switchScene(new Game(2));
			return 0;
		case DEFEAT:
			return 0;
		case WIN:
			return 0;
		default:
			return status;
	}
}
