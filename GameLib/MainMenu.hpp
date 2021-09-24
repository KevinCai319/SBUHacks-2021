#pragma once
#include "Layer.hpp"
class MainMenu : public Layer
{
	public:
		MainMenu();
		virtual int recieve(Layer& layer, int status)override;
		virtual void notify(Layer& layer, int status)override;
};

