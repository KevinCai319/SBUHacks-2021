#pragma once
#include <SFML/Graphics.hpp>
#include "Physical.hpp"
#include "Clue.hpp"
class Door :public Physical
{
private: 
	sf::RectangleShape box; 
	int floor; 
	// Clue clue; 

public: 
	Door(float sx, float sy, float width, float height, int floor);
	virtual void render(sf::RenderTarget& target, sf::RenderStates states) const override; 
	virtual int recieve(Layer& layer, int status) override; 
	virtual const sf::Shape& getShape() override; 
	int getFloor(); 
	const sf::Vector2f& getStart(); 
	const sf::Vector2f& getSize(); 
};

