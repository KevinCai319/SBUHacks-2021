#include "Player.hpp"

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
		//parent->getTag("Physical");
		//return 3;
	}
	return 0;
}

const sf::Shape& Player::getShape()
{
	return box;
}

int Player::recieve(Layer& layer, int status)
{
	return 0;
}

void Player::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box, states);
}
