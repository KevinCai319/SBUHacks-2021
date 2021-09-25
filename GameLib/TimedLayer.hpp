#pragma once
#include <SFML/System.hpp>
#include "Timed.hpp"
class TimedLayer : public Layer
{
	public:
		TimedLayer();
		float time = 0.0f;
		virtual int main() override;
	private: 
		sf::Clock timer; 
};

