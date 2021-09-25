#include "Teleporter.hpp"
#include "Player.hpp"
#include "Line.hpp"
Teleporter::Teleporter(int sx, int sy, int width, int height, int floor, int circ_rad) :
	linked(nullptr),
	sx(sx),
	sy(sy),
	width(width),
	height(height),
	floor(floor),
	circ_rad(circ_rad),
	Physical()
{
	tags.insert("Teleporter");
	box = sf::RectangleShape(sf::Vector2f(width,height));
	circ = sf::CircleShape(circ_rad);
	circ.setFillColor(sf::Color::Transparent);
	circ.setOutlineThickness(4);
	circ.setOutlineColor(sf::Color::Cyan);
	circ.setPosition((sx+width/2)-circ_rad,sy-height/2-circ_rad);
	box.setPosition(sx, sy-height);
}

int Teleporter::main()
{
	return 0;
}

const sf::Shape& Teleporter::getShape()
{
	return box;
}

int Teleporter::recieve(Layer& layer, int status)
{
	return 0;
}

void Teleporter::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box, states);
	std::set<Layer*> players = parent->getTag("Player");
	for (Layer* p : players) {
		Player* c = dynamic_cast<Player*>(p);
		int type = c->type;
		if (c->getFloor() == floor && c->getR() > box.getGlobalBounds().left && c->getL() < box.getGlobalBounds().left+box.getGlobalBounds().width) {
			target.draw(circ, states);
			target.draw(linked->circ, states);
			Line t = Line(circ.getPosition(), linked->circ.getPosition(),5);
			t.setColor(sf::Color::Cyan);
			target.draw(t, states);
		}
	}
}
