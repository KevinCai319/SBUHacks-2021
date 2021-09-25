#pragma once
#include <SFML/Graphics.hpp>
#include "Dimension.h"
#include "Layer.hpp"
#include "Button.hpp"

#define SELECT_VSPACE 150
#define SELECT_XOFFSET ((WIN_WIDTH - BUTTON_WIDTH) / 2)
#define SELECT_YOFFSET ((WIN_HEIGHT - 3*BUTTON_HEIGHT - 2*SELECT_VSPACE) / 2)

class DifficultySelect : public Layer
{
	private: 
		Button easyButton; 
		Button normalButton; 
		Button deathButton; 
		Button backButton; 

		sf::Font* fontptr; 
		sf::Text easyText; 
		sf::Text normalText; 
		sf::Text deathText; 
		sf::Text backText; 

	public: 
		DifficultySelect(); 
		~DifficultySelect(); 
		virtual int recieve(Layer& layer, int status)override;
		virtual void notify(Layer& layer, int status)override;
};

