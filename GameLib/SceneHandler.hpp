#pragma once
#include "WindowHandler.hpp"
#include "MainMenu.hpp"

#define EXIT -1
#define DIFFICULTY 1
#define MANUAL 2
#define GAME 3
#define DEFEAT 4
#define WIN 5

class SceneHandler : public WindowHandler
{
	public:
		SceneHandler(int x, int y, const std::string& title,Layer* menu);
		virtual int recieve(Layer& layer, int status) override;
};

