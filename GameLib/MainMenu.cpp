#include <iostream>
#include "MainMenu.hpp"
#include "Button.hpp"
MainMenu::MainMenu() : 
	titleBox((WWIDTH - TWIDTH) / 2, (WHEIGHT - THEIGHT) / 3, TWIDTH, THEIGHT),
	playButton(XOFFSET, YOFFSET, BWIDTH, BHEIGHT), 
	instructionButton(XOFFSET + BWIDTH + SPACE, YOFFSET, BWIDTH, BHEIGHT), 
	exitButton(XOFFSET + 2*BWIDTH + 2*SPACE, YOFFSET, BWIDTH, BHEIGHT)
{
	tags.insert("Menu");
	
	fontptr = new sf::Font(); 
	if (!fontptr->loadFromFile("Assets\\youmurdererbb_reg.ttf"))
	{
		std::cout << "Cannot load" << std::endl; 
		// do something
	}

	titleText.setFont(*fontptr); 
	titleText.setString("Hotel of Death"); 
	titleText.setFillColor(sf::Color::Red); 
	titleText.setCharacterSize(168); 
	titleBox.setText(titleText); 

	playText.setFont(*fontptr); 
	playText.setString("Play"); 
	playText.setFillColor(sf::Color::Black); 
	playText.setCharacterSize(96); 
	playButton.setText(playText); 

	instructionText.setFont(*fontptr); 
	instructionText.setString("Instructions"); 
	instructionText.setFillColor(sf::Color::Black); 
	instructionText.setCharacterSize(96); 
	instructionButton.setText(instructionText); 

	exitText.setFont(*fontptr); 
	exitText.setString("Exit"); 
	exitText.setFillColor(sf::Color::Black); 
	exitText.setCharacterSize(96); 
	exitButton.setText(exitText); 

	addEntity(&titleBox); 
	addEntity(&playButton); 
	addEntity(&instructionButton); 
	addEntity(&exitButton); 
}

MainMenu::~MainMenu()
{
	delete fontptr; 
}


int MainMenu::recieve(Layer& layer, int status)
{
	if (status == -1) {
		return status;
	}		
	return status;
}

void MainMenu::notify(Layer& layer, int status)
{
}
