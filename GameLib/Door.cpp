#include "Door.hpp"
#include "Line.hpp"
Door::Door(float sx, float sy, float width, float height, int floor, int color, int shape, int number) :
	box(sf::RectangleShape(sf::Vector2f(width, height))),
	floor(floor),
	color(color),
	shape(shape),
	id(number),
	lx(sx),
	hx(sx+width),
	number(sx+width*.25,sy+height*.125,width,height)
{
	box.setPosition(sf::Vector2f(sx, sy));
	// box.setFillColor(c); 
	fontptr = new sf::Font();
	if (!fontptr->loadFromFile("Assets\\youmurdererbb_reg.ttf"))
	{
		// something happened
	}
	renderPriority = -1;
	
	doorText.setFont(*fontptr);
	doorText.setString(std::to_string(id));
	doorText.setFillColor(sf::Color::Black);
	doorText.setCharacterSize(height/4);
	this->number.setText(doorText);
	sf::RectangleShape* tmp = new sf::RectangleShape(sf::Vector2f(width *0.9f, height / 2.0f));
	sf::CircleShape* tmp2 = new sf::CircleShape(width/8);
	switch (shape) {
		case 0:
			symbol = new Line(sf::Vector2f(sx,sy+height/4),sf::Vector2f(sx+width,sy+height/4),5);
			break;
		case 1:
			tmp->setPosition(sx + width * .05f, sy + height * .05f);
			symbol = tmp;
			break;
		case 2:
			tmp2->setPosition(sx + width / 4, sy + width / 4);
			symbol = tmp2;
			break;
		case 3:
			symbol = new Line(sf::Vector2f(sx+width/4, sy), sf::Vector2f(sx + width/4, sy + height), 5);
			break;
	}
	switch (color) {
		case 0:
			box.setFillColor(sf::Color::Yellow);
			break;
		case 1:
			box.setFillColor(sf::Color::Red);
			break;
		case 2:
			box.setFillColor(sf::Color::Green);
			break;
		case 3:
			box.setFillColor(sf::Color::Blue);
			break;
		case 4:
			box.setFillColor(sf::Color::Magenta);
			break;
		case 5:
			box.setFillColor(sf::Color::Cyan);
			break;
	}
	tags.insert("Door"); 
}

Door::~Door()
{
	delete fontptr;
	delete symbol;
}

void Door::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box, states); 
	target.draw(number, states);
	target.draw(*symbol, states);
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

