#include "Teleporter.hpp"
#include "Player.hpp"

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
	renderPriority = 1;
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
	
	std::set<Layer*> players = parent->getTag("Player");
	for (Layer* p : players) {
		Player* c = dynamic_cast<Player*>(p);
		int type = c->type;
		if (c->getFloor() == floor && c->getR() > box.getGlobalBounds().left && c->getL() < box.getGlobalBounds().left + box.getGlobalBounds().width) {
			renderPriority = 2;
			if (!type) {
				circ.setOutlineColor(sf::Color::Cyan);
				linkLine.setColor(sf::Color::Cyan);
				linked->circ.setOutlineColor(sf::Color::Cyan);
				linked->linkLine.setColor(sf::Color::Cyan);
			}
			else {
				circ.setOutlineColor(sf::Color(255,155,0));
				linkLine.setColor(sf::Color(255, 155, 0));
				linked->circ.setOutlineColor(sf::Color(255, 155, 0));
				linked->linkLine.setColor(sf::Color(255, 155, 0));
			}
			renderLink = true;
			return 0;
		}
		else {
			renderPriority = 1;
			renderLink = false;
		}
	}
	return 0;
}

const sf::Shape& Teleporter::getShape()
{
	return box;
}

void Teleporter::updateLinked(Teleporter* link)
{
	linked = link;
	sf::Vector2f a = circ.getPosition();
	a.x += circ_rad;
	a.y += circ_rad;
	sf::Vector2f b = linked->circ.getPosition();
	b.x += circ_rad;
	b.y += circ_rad;
	sf::Vector2f d = a - b;
	d /= sqrt(powf(d.x, 2) + powf(d.y, 2));
	d.x *= circ_rad;
	d.y *= circ_rad;
	a -= d;
	b += d;
	linkLine = Line(a, b, 5);
	linkLine.setColor(sf::Color::Cyan);
}

int Teleporter::recieve(Layer& layer, int status)
{
	return 0;
}

void Teleporter::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box, states);
	if (renderLink) {
		target.draw(circ, states);
		target.draw(linked->circ, states);
		target.draw(linkLine, states);
	}else {

	}
}
