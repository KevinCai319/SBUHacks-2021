#pragma once
#include <SFML/System.hpp>
#include "Dimension.h"
#include "Layer.hpp"
#include "Button.hpp"


#define MENU_HSPACE 100
#define MENU_XOFFSET ((WIN_WIDTH - 3*BUTTON_WIDTH - 2*MENU_HSPACE) / 2)
#define MENU_YOFFSET (2 * (WIN_HEIGHT - BUTTON_HEIGHT) / 3)

class MainMenu : public Layer
{
	private: 
		Button titleBox; 
		Button playButton; 
		Button manualButton; 
		Button exitButton; 

		sf::Font* fontptr; 
		sf::Text titleText; 
		sf::Text playText; 
		sf::Text manualText; 
		sf::Text exitText; 

	public:
		MainMenu();
		~MainMenu(); 
		virtual int recieve(Layer& layer, int status)override;
		virtual void notify(Layer& layer, int status)override;
};

