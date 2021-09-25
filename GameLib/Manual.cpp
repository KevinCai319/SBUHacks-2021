#include "Manual.hpp"
#include "SceneHandler.hpp"

Manual::Manual() : 
	headerBox((WIN_WIDTH - TITLE_WIDTH) / 2, MAN_YOFFSET, TITLE_WIDTH, TITLE_HEIGHT), 
	manualBox(MAN_XOFFSET, WIN_HEIGHT - MAN_TEXT_HEIGHT, MAN_TEXT_WIDTH, MAN_TEXT_HEIGHT), 
	backButton(0, WIN_HEIGHT - BACK_HEIGHT, BACK_WIDTH, BACK_HEIGHT)
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
	manualText.setFillColor(sf::Color::White); 
	manualText.setCharacterSize(MAN_SIZE); 
	manualBox.setText(manualText); 
	manualBox.alignTextLeft(); 
	manualBox.alignTextTop(); 

	backText.setFont(*fontptr); 
	backText.setString("<-"); 
	backText.setFillColor(sf::Color::White); 
	backText.setCharacterSize(BACK_SIZE); 
	backButton.setText(backText); 

	backButton.setDefaultFunction([this]() {
		backText.setFillColor(sf::Color::White); 
		backButton.setText(backText); 
	});
	backButton.setHoverFunction([this]() {
		backText.setFillColor(sf::Color::Red); 
		backButton.setText(backText); 
	});
	backButton.setClickFunction([this]() {
		backButton.notify(*this, MENU);
	});

	addEntity(&headerBox); 
	addEntity(&manualBox); 
	addEntity(&backButton); 
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
