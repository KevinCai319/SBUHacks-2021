#include "SceneHandler.hpp"
#include "Game.hpp"
int main() {
	SceneHandler* main = new SceneHandler(1920, 1080, "Hotel of Death", new Game(1));

	while (main->update() == 0) {
		main->render();
	}
	delete main;
	
	std::cout << "Thanks for playing!" << std::endl;
	return 0;
}