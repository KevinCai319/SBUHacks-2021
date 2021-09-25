#pragma once
#include "WindowHandler.hpp"
#include "MainMenu.hpp"

#define EXIT -1
#define MENU 1
#define DIFFICULTY 2
#define MANUAL 3
#define EASY 4
#define NORMAL 5
#define DEATH 6
#define DEFEAT 7
#define WIN 8

class SceneHandler : public WindowHandler
{
	public:
		SceneHandler(int x, int y, const std::string& title,Layer* menu);
		virtual int recieve(Layer& layer, int status) override;
};

