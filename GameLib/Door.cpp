#include "Door.hpp"

Door::Door(float sx, float sy, float width, float height, int floor) : 
	box(sf::RectangleShape(sf::Vector2f(width, height))),
	floor(floor)
{
	box.setPosition(sf::Vector2f(sx, sy));
	// box.setFillColor(c); 
	tags.insert("Door"); 
}

void Door::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box, states); 
}

int Door::recieve(Layer& layer, int status)
{
	return status; 
}

const sf::Shape& Door::getShape()
{
	return box; 
}

int Door::getFloor()
{
	return floor;
}

const sf::Vector2f& Door::getStart()
{
	return box.getPosition(); 
}

const sf::Vector2f& Door::getSize()
{
	return box.getSize(); 
}

