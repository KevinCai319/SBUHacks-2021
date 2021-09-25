#pragma once
#include <SFML/Graphics.hpp>
#include "Dimension.h"
#include "Layer.hpp"
#include "Button.hpp"

#define MAN_TEXT_WIDTH (WIN_WIDTH * 0.95)
#define MAN_TEXT_HEIGHT (WIN_HEIGHT * 0.8)
#define MAN_XOFFSET ((WIN_WIDTH - MAN_TEXT_WIDTH) / 2) 
#define MAN_YOFFSET ((WIN_HEIGHT - MAN_TEXT_HEIGHT - TITLE_HEIGHT) / 2)
#define MAN_SIZE 72

class Manual : public Layer
{
	private: 
		Button headerBox;
		Button manualBox; 
		Button backButton; 

		sf::Font* fontptr; 
		sf::Text headerText; 
		sf::Text manualText; 
		sf::Text backText; 

	public: 
		Manual(); 
		~Manual(); 
		int recieve(Layer& layer, int status); 
		void notify(Layer& layer, int status); 
};

