#pragma once
#include "Physical.hpp"
#include "Line.hpp"
class Teleporter : public Physical
{
public:
	Teleporter(int sx, int sy,int width, int height,int floor,int circ_rad);
	virtual int main() override;
	virtual const sf::Shape& getShape() override;
	void updateLinked(Teleporter* link);
	Teleporter* linked;
	const int sx;
	const int sy;
	const int width;
	const int height;
	const int floor;
	const int circ_rad;
	bool renderLink = false;
protected:
	sf::CircleShape circ;
	Line linkLine;
	sf::RectangleShape box;
	virtual int recieve(Layer& layer, int status)override;
	virtual void render(sf::RenderTarget& target, sf::RenderStates states)const override;
};

