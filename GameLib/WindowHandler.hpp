#pragma once
#include "Handler.hpp"
class WindowHandler:public Handler
{
	public:
		WindowHandler(int x, int y, const std::string& title, Layer* defaultScene);
		void render();
		virtual void render(sf::RenderTarget& target, sf::RenderStates states)const override;
		int main() override;
		// handle request
		virtual int recieve(Layer& layer,int status)override;
		void setBGColor(sf::Color& bg); 
	private:
		sf::RenderWindow window;
		sf::Color bgColor; 
};

