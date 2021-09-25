#pragma once
#include "Physical.hpp"
#include "Timed.hpp"
class Player :public Physical,public Timed{
	public:
		Player(int sx,int sy,sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key interact);
		virtual int main(sf::Time dt) override;
		virtual const sf::Shape& getShape() override;

};

