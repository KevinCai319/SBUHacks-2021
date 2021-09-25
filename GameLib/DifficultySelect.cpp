#include "DifficultySelect.hpp"

DifficultySelect::DifficultySelect() : 
	easyButton(SELECT_XOFFSET, SELECT_YOFFSET, BUTTON_WIDTH, BUTTON_HEIGHT), 
	normalButton(SELECT_XOFFSET, SELECT_YOFFSET + BUTTON_HEIGHT + SELECT_VSPACE, BUTTON_WIDTH, BUTTON_HEIGHT), 
	deathButton(SELECT_XOFFSET, SELECT_YOFFSET + 2*BUTTON_HEIGHT + 2*SELECT_VSPACE, BUTTON_WIDTH, BUTTON_HEIGHT)
{
	tags.insert("Select"); 

	fontptr = new sf::Font(); 
	if (!fontptr->loadFromFile("Assets\\youmurdererbb_reg.ttf"))
	{
		// something happened
	}

	easyText.setFont(*fontptr); 
	easyText.setString("Easy"); 
	easyText.setFillColor(sf::Color::White); 
	easyText.setCharacterSize(NORMAL_SIZE); 
	easyButton.setText(easyText); 

	normalText.setFont(*fontptr); 
	normalText.setString("Normal"); 
	normalText.setFillColor(sf::Color::White); 
	normalText.setCharacterSize(NORMAL_SIZE); 
	normalButton.setText(normalText); 

	deathText.setFont(*fontptr); 
	deathText.setString("Death"); 
	deathText.setFillColor(sf::Color::White); 
	deathText.setCharacterSize(NORMAL_SIZE); 
	deathButton.setText(deathText); 

	easyButton.setDefaultFunction([this]() {
			easyText.setFillColor(sf::Color::White); 
			easyButton.setText(easyText); 
	});
	normalButton.setDefaultFunction([this]() {
			normalText.setFillColor(sf::Color::White); 
			normalButton.setText(normalText); 
	});
	deathButton.setDefaultFunction([this]() {
			deathText.setFillColor(sf::Color::White); 
			deathButton.setText(deathText); 
	});
	
	easyButton.setHoverFunction([this]() {
		easyText.setFillColor(sf::Color::Red); 
		easyButton.setText(easyText); 
	});
	normalButton.setHoverFunction([this]() {
		normalText.setFillColor(sf::Color::Red); 
		normalButton.setText(normalText); 
	});
	deathButton.setHoverFunction([this]() {
		deathText.setFillColor(sf::Color::Red); 
		deathButton.setText(deathText); 
	});

	addEntity(&easyButton); 
	addEntity(&normalButton); 
	addEntity(&deathButton); 
}

DifficultySelect::~DifficultySelect()
{
	delete fontptr; 
}

int DifficultySelect::recieve(Layer& layer, int status)
{
	return status; 
}

void DifficultySelect::notify(Layer& layer, int status)
{

}
