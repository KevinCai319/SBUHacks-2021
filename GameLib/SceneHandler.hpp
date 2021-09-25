#pragma once
#include "WindowHandler.hpp"
#include "MainMenu.hpp"

#define EXIT -1
#define MENU 1
#define DIFFICULTY 2
#define MANUAL 3
#define GAME 4
#define DEFEAT 9
#define WIN 10

class SceneHandler : public WindowHandler
{
	public:
		SceneHandler(int x, int y, const std::string& title,Layer* menu);
		virtual int recieve(Layer& layer, int status) override;
};

