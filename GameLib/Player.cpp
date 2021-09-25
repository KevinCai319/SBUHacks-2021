#include "Player.hpp"
#include "Teleporter.hpp"
#include "Door.hpp"
Player::Player(int sx, int sy, int width, int height, float velocity, int lbound, int rbound, int floor, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key interact) :
	left(left),
	right(right),
	interact(interact),
	width(width),
	height(height),
	velocity(velocity),
	lbound(lbound),
	rbound(rbound),
	floor(floor),
	Timed::Timed(),
	Physical::Physical()
{
	box = sf::RectangleShape(sf::Vector2f(width,height));
	box.setPosition(sx, sy);
	tags.insert("Player");
}

int Player::main(float dt)
{
	status = 0;
	if (sf::Keyboard::isKeyPressed(left)) {
		if (box.getGlobalBounds().left - velocity * dt > lbound) {
			box.move(sf::Vector2f(-velocity * dt, 0));
		}
	}
	if (sf::Keyboard::isKeyPressed(right)) {
		sf::FloatRect bounds = box.getGlobalBounds();
		if (bounds.left + bounds.width + velocity * dt < rbound) {
			box.move(sf::Vector2f(velocity * dt, 0));
		}
	}
	if (sf::Keyboard::isKeyPressed(interact)) {
		std::set<Layer*> teleporters = parent->getTag("Teleporter");
		for (Layer* i : teleporters) {
			Teleporter* tp = dynamic_cast<Teleporter*>(i);
			if (getFloor() == tp->floor && getR() > tp->sx && getL() < tp->sx + tp->width) {
				if (tdCounter <= 0.0f) {
					box.setPosition(tp->linked->sx, tp->linked->sy - height);
					tdCounter = tDebounce;
					floor = tp->linked->floor;
					return status;
				}
			}
		}
		std::set<Layer*> doors = parent->getTag("Door");
		for (Layer* i : doors)
		{
			Door* dr = dynamic_cast<Door*>(i); 
			if (getFloor() == dr->getFloor() && getR() > dr->getStart().x && getL() < dr->getStart().x + dr->getSize().x)
			{
				if (dr->isGood) {
					status = 1;
				}else {
					status = 2;
				}
			}
		}
	}
	if (tdCounter > 0.0f) {
		tdCounter -= dt;
	}
	return 0;
}

const sf::Shape& Player::getShape()
{
	return box;
}

int Player::getFloor()
{
	return floor;
}

int Player::getL()
{
	return box.getGlobalBounds().left;
}

int Player::getR()
{
	return box.getGlobalBounds().left + box.getGlobalBounds().width;
}

int Player::recieve(Layer& layer, int status)
{
	return 0;
}

void Player::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box, states);
}
