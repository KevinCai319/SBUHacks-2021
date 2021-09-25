#pragma once
#include <SFML/Graphics.hpp>
#include "Dimension.h"
#include "Layer.hpp"
#include "Button.hpp"

#define SELECT_VSPACE 150
#define SELECT_XOFFSET ((WIN_WIDTH - BUTTON_WIDTH) / 2)
#define SELECT_YOFFSET ((WIN_HEIGHT - 3*BUTTON_HEIGHT - 2*SELECT_VSPACE) / 2)

class GameOver : public Layer
{
private:
	Button backButton;
	Button headerBox;
	sf::Font* fontptr;
	sf::Text backText;
	sf::Text headerText;

public:
	GameOver(bool isWin);
	~GameOver();
	virtual int recieve(Layer& layer, int status)override;
	virtual void notify(Layer& layer, int status)override;
};

