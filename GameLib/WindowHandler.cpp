#include "WindowHandler.hpp"

//Setup main window and graphics reference.
WindowHandler::WindowHandler(int x, int y, const std::string& title, Layer* defaultScene) :
	Handler(defaultScene),
	window(sf::VideoMode(x, y), title)
{
	tags.insert("Window");
	this->screen = &window;
}

void WindowHandler::render()
{
	window.clear();
	if (running) {
		window.draw(*running, sf::RenderStates::Default);
	}
	window.display(); 
}

void WindowHandler::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*running, states); 
}

int WindowHandler::main()
{
	int res = Handler::main();
	if (res)return res;
	sf::Event event;
	while(window.pollEvent(event))
	{
		// Close window: exit
		if (event.type == sf::Event::Closed) {
			window.close(); 
			return 1;
		}
	}
	return 0;
}

int WindowHandler::recieve(Layer& layer, int status)
{
	return 0;
}

