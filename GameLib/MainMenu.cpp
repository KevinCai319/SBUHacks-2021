#include "MainMenu.hpp"
#include "SceneHandler.hpp"
#include "Button.hpp"

MainMenu::MainMenu() : 
	titleBox((WIN_WIDTH - TITLE_WIDTH) / 2, (WIN_HEIGHT - TITLE_HEIGHT) / 3, TITLE_WIDTH, TITLE_HEIGHT),
	playButton(MENU_XOFFSET, MENU_YOFFSET, BUTTON_WIDTH, BUTTON_HEIGHT), 
	manualButton(MENU_XOFFSET + BUTTON_WIDTH + MENU_HSPACE, MENU_YOFFSET, BUTTON_WIDTH, BUTTON_HEIGHT), 
	exitButton(MENU_XOFFSET + 2*BUTTON_WIDTH + 2*MENU_HSPACE, MENU_YOFFSET, BUTTON_WIDTH, BUTTON_HEIGHT)
{
	tags.insert("Menu");
	
	fontptr = new sf::Font(); 
	if (!fontptr->loadFromFile("Assets\\youmurdererbb_reg.ttf"))
	{
		// something happened
	}

	titleText.setFont(*fontptr); 
	titleText.setString("Hotel of Death"); 
	titleText.setFillColor(sf::Color::Red); 
	titleText.setCharacterSize(TITLE_SIZE); 
	titleBox.setText(titleText); 

	playText.setFont(*fontptr); 
	playText.setString("Play"); 
	playText.setFillColor(sf::Color::White); 
	playText.setCharacterSize(NORMAL_SIZE); 
	playButton.setText(playText); 

	manualText.setFont(*fontptr); 
	manualText.setString("Manual"); 
	manualText.setFillColor(sf::Color::White); 
	manualText.setCharacterSize(NORMAL_SIZE); 
	manualButton.setText(manualText); 

	exitText.setFont(*fontptr); 
	exitText.setString("Exit"); 
	exitText.setFillColor(sf::Color::White); 
	exitText.setCharacterSize(NORMAL_SIZE); 
	exitButton.setText(exitText); 

	playButton.setDefaultFunction([this]() {
		playText.setFillColor(sf::Color::White); 
		playButton.setText(playText); 
	});
	manualButton.setDefaultFunction([this]() {
		manualText.setFillColor(sf::Color::White); 
		manualButton.setText(manualText); 
	});
	exitButton.setDefaultFunction([this]() {
		exitText.setFillColor(sf::Color::White); 
		exitButton.setText(exitText); 
	});

	playButton.setHoverFunction([this]() {
		playText.setFillColor(sf::Color::Red); 
		playButton.setText(playText); 
	});
	manualButton.setHoverFunction([this]() {
		manualText.setFillColor(sf::Color::Red); 
		manualButton.setText(manualText); 
	});
	exitButton.setHoverFunction([this]() {
		exitText.setFillColor(sf::Color::Red); 
		exitButton.setText(exitText); 
	});

	playButton.setClickFunction([this]() {
		playButton.notify(*this, DIFFICULTY);
	});
	manualButton.setClickFunction([this]() {
		manualButton.notify(*this, MANUAL);
	});
	exitButton.setClickFunction([this]() {
		exitButton.notify(*this, EXIT);
	});

	addEntity(&titleBox); 
	addEntity(&playButton); 
	addEntity(&manualButton); 
	addEntity(&exitButton); 
}

MainMenu::~MainMenu()
{
	delete fontptr; 
}

int MainMenu::recieve(Layer& layer, int status)
{
	return status;
}

void MainMenu::notify(Layer& layer, int status)
{

}
