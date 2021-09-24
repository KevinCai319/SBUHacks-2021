#include "SceneHandler.hpp"
SceneHandler::SceneHandler(int x, int y, const std::string& title,Layer* menu):WindowHandler(x,y,title,menu)
{
	tags.insert("Root");
}

int SceneHandler::recieve(Layer& layer, int status)
{
	switch (status) {
		case 0:
			return status;//Exit
		case 1:
			std::cout << "go to difficulty select screen" << std::endl;
			return 0;
		case 2:
			std::cout << "go to instructions screen" << std::endl;
			return 0;
		case 3:
			std::cout << "go to main game" << std::endl;
			return 0;
		case 4:
			std::cout << "go to game over" << std::endl;
			return 0;
		case 5:
			std::cout << "go to you won" << std::endl;
			return 0;
		default:
			return status;
	}
}
