#pragma once
#include "WindowHandler.hpp"
#include "MainMenu.hpp"
class SceneHandler : public WindowHandler
{
	public:
		SceneHandler(int x, int y, const std::string& title,Layer* menu);
		virtual int recieve(Layer& layer, int status) override;
};

