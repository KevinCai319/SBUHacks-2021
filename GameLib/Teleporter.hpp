#pragma once
#include "Physical.hpp"
class Teleporter : public Physical
{
public:
	Teleporter(int sx, int sy,int width, int height,int floor,int circ_rad);
	virtual int main() override;
	virtual const sf::Shape& getShape() override;
	Teleporter* linked;
	const int sx;
	const int sy;
	const int width;
	const int height;
	const int floor;
	const int circ_rad;
protected:
	sf::CircleShape circ;
	sf::RectangleShape box;
	virtual int recieve(Layer& layer, int status)override;
	virtual void render(sf::RenderTarget& target, sf::RenderStates states)const override;
};

