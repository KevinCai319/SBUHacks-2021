#include "Floor.hpp"

Floor::Floor(int floorNumber,int fheight):
	floorNumber(floorNumber)
{
	tags.insert("Floor");
	int bezel = 600;
	int width = 1920-bezel;
	int height = 50;
	ground = sf::RectangleShape(sf::Vector2f(width, height));
	ground.setPosition((1920-width)/2,1080-floorNumber*fheight-height);
}

const sf::Shape& Floor::getShape()
{
	return ground;
}

void Floor::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(ground, states);
}
int Floor::recieve(Layer& layer, int status) {
	switch (status) {
		case 0:
			return 0;
		default:
			return 0;
	}
	return 0;
}