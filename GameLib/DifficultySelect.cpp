#include "DifficultySelect.hpp"
#include "SceneHandler.hpp"

DifficultySelect::DifficultySelect() : 
	easyButton(SELECT_XOFFSET, SELECT_YOFFSET, BUTTON_WIDTH, BUTTON_HEIGHT), 
	normalButton(SELECT_XOFFSET, SELECT_YOFFSET + BUTTON_HEIGHT + SELECT_VSPACE, BUTTON_WIDTH, BUTTON_HEIGHT), 
	deathButton(SELECT_XOFFSET, SELECT_YOFFSET + 2*BUTTON_HEIGHT + 2*SELECT_VSPACE, BUTTON_WIDTH, BUTTON_HEIGHT), 
	backButton(0, WIN_HEIGHT - BACK_HEIGHT, BACK_WIDTH, BACK_HEIGHT)
{
	tags.insert("Select"); 
	difficulty = 0;
	fontptr = new sf::Font(); 
	if (!fontptr->loadFromFile("Assets\\youmurdererbb_reg.ttf"))
	{
		// something happened
	}

	easyText.setFont(*fontptr); 
	easyText.setString("Easy"); 
	easyText.setFillColor(sf::Color::White); 
	easyText.setCharacterSize(BUTTON_SIZE); 
	easyButton.setText(easyText); 

	normalText.setFont(*fontptr); 
	normalText.setString("Normal"); 
	normalText.setFillColor(sf::Color::White); 
	normalText.setCharacterSize(BUTTON_SIZE); 
	normalButton.setText(normalText); 

	deathText.setFont(*fontptr); 
	deathText.setString("Death"); 
	deathText.setFillColor(sf::Color::White); 
	deathText.setCharacterSize(BUTTON_SIZE); 
	deathButton.setText(deathText); 

	backText.setFont(*fontptr); 
	backText.setString("<-"); 
	backText.setFillColor(sf::Color::White); 
	backText.setCharacterSize(BACK_SIZE); 
	backButton.setText(backText); 

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
	backButton.setDefaultFunction([this]() {
		backText.setFillColor(sf::Color::White); 
		backButton.setText(backText); 
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
	backButton.setHoverFunction([this]() {
		backText.setFillColor(sf::Color::Red); 
		backButton.setText(backText); 
	});

	backButton.setClickFunction([this]() {
		backButton.notify(*this, MENU);
	}); 
	easyButton.setClickFunction([this]() {
		difficulty = 0;
		easyButton.notify(*this, EASY);
		});
	normalButton.setClickFunction([this]() {
		difficulty = 1;
		normalButton.notify(*this, NORMAL);
		});
	deathButton.setClickFunction([this]() {
		difficulty = 2;
		deathButton.notify(*this, DEATH);
	});

	addEntity(&easyButton); 
	addEntity(&normalButton); 
	addEntity(&deathButton); 
	addEntity(&backButton); 
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
