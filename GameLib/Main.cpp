#include <SFML/Graphics.hpp>
#include "Dimension.h"
#include "SceneHandler.hpp"
#include "Game.hpp"
int main() {
	SceneHandler* main = new SceneHandler(1920, 1080, "Hotel of Death", new Game(2));
	SceneHandler* main = new SceneHandler(WIN_WIDTH, WIN_HEIGHT, "Hotel of Death", new MainMenu());
	sf::Color bg(23, 23, 23); 
	main->setBGColor(bg); 

	while (main->update() == 0) {
		main->render();
	}
	delete main;
	
	std::cout << "Thanks for playing!" << std::endl;
	return 0;
}