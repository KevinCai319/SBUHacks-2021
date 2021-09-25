#pragma once
#include <SFML/System.hpp>
#include "Layer.hpp"
#include "Button.hpp"

#define WWIDTH 1920
#define WHEIGHT 1080

#define TWIDTH 800
#define THEIGHT 200

#define BWIDTH 400
#define BHEIGHT 100
#define SPACE 100
#define XOFFSET ((WWIDTH - 3*BWIDTH - 2*SPACE) / 2)
#define YOFFSET (2 * (WHEIGHT - BHEIGHT) / 3)

class MainMenu : public Layer
{
	private: 
		Button titleBox; 
		Button playButton; 
		Button instructionButton; 
		Button exitButton; 

		sf::Font* fontptr; 
		sf::Text titleText; 
		sf::Text playText; 
		sf::Text instructionText; 
		sf::Text exitText; 

	public:
		MainMenu();
		~MainMenu(); 
		virtual int recieve(Layer& layer, int status)override;
		virtual void notify(Layer& layer, int status)override;
};

