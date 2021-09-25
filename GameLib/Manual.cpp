#include "Manual.hpp"

Manual::Manual() : 
	headerBox((WIN_WIDTH - TITLE_WIDTH) / 2, MAN_YOFFSET, TITLE_WIDTH, TITLE_HEIGHT), 
	manualBox(MAN_XOFFSET, WIN_HEIGHT - MAN_TEXT_HEIGHT, MAN_TEXT_WIDTH, MAN_TEXT_HEIGHT)
{
	tags.insert("Manual"); 

	fontptr = new sf::Font(); 
	if (!fontptr->loadFromFile("Assets\\youmurdererbb_reg.ttf"))
	{
		// something happened
	}

	headerText.setFont(*fontptr); 
	headerText.setString("Manual"); 
	headerText.setFillColor(sf::Color::Red); 
	headerText.setCharacterSize(TITLE_SIZE); 
	headerBox.setText(headerText); 

	manualText.setFont(*fontptr); 
	manualText.setString("Your manual goes right here..."); 
	manualText.setFillColor(sf::Color::Red); 
	manualText.setCharacterSize(MAN_SIZE); 
	manualBox.setText(manualText); 
	manualBox.alignTextLeft(); 
	manualBox.alignTextTop(); 

	addEntity(&headerBox); 
	addEntity(&manualBox); 
}

Manual::~Manual()
{
	delete fontptr; 
}

int Manual::recieve(Layer& layer, int status)
{
	return status;
}

void Manual::notify(Layer& layer, int status)
{

}
