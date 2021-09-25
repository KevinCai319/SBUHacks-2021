#include <SFML/Graphics.hpp>
#include "SceneHandler.hpp"
#include "MainMenu.hpp"
int main() {
	SceneHandler* main = new SceneHandler(1920, 1080, "Hotel of Death", new MainMenu());
	sf::Color bg(105, 105, 105); 
	main->setBGColor(bg); 

	while (main->update() == 0) {
		main->render();
	}
	delete main;
	
	std::cout << "Thanks for playing!" << std::endl;
	return 0;
}