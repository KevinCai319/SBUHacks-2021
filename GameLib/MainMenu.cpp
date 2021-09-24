#include "MainMenu.hpp"
#include "Button.hpp"
MainMenu::MainMenu()
{
	tags.insert("Menu");

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
