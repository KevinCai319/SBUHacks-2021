#include "GameOver.hpp"
#include "SceneHandler.hpp"

GameOver::GameOver(bool isWin) :
	backButton(WIN_WIDTH-240,WIN_HEIGHT-144, BACK_WIDTH, BACK_HEIGHT),
	headerBox((WIN_WIDTH - TITLE_WIDTH) / 2,400, TITLE_WIDTH, TITLE_HEIGHT)
{
	tags.insert("Game Over");
	fontptr = new sf::Font();
	if (!fontptr->loadFromFile("Assets\\youmurdererbb_reg.ttf"))
	{
		// something happened
	}
	backText.setFont(*fontptr);
	backText.setString("->");
	backText.setFillColor(sf::Color::White);
	backText.setCharacterSize(144);
	backButton.setText(backText);

	headerText.setFont(*fontptr);
	if(isWin){
		headerText.setString("ALIVE");
		headerText.setFillColor(sf::Color::White);
	}
	else {
		headerText.setString("DEATH");
		headerText.setFillColor(sf::Color::Red);
	}
	headerText.setCharacterSize(TITLE_SIZE);
	headerBox.setText(headerText);

	backButton.setDefaultFunction([this]() {
		backText.setFillColor(sf::Color::White);
		backButton.setText(backText);
		});

	backButton.setHoverFunction([this]() {
		backText.setFillColor(sf::Color::Red);
		backButton.setText(backText);
		});

	backButton.setClickFunction([this]() {
		backButton.notify(*this, DIFFICULTY);
		});
	addEntity(&backButton);
	addEntity(&headerBox);
}

GameOver::~GameOver()
{
	delete fontptr;
}

int GameOver::recieve(Layer& layer, int status)
{
	return status;
}

void GameOver::notify(Layer& layer, int status)
{

}
