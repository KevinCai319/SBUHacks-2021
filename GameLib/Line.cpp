#include "Line.hpp"
#include <SFML\Window\Mouse.hpp>
Line::Line() {

}
Line::Line(sf::Vector2f v1, sf::Vector2f v2, float thick) {
	startPoint = v1;
	endPoint = v2;
	thickness = thick / 2;
	start = sf::CircleShape(thickness);
	start.setPosition(getRealPoint(startPoint));
	end = sf::CircleShape(thickness);
	end.setPosition(getRealPoint(endPoint));
	calcLine();
}
Line::~Line() {

}
void Line::resetEnd(sf::Vector2f v2) {
	endPoint = v2;
	end.setPosition(getRealPoint(endPoint));
	calcLine();
}
void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(start,states);
	target.draw(end,states);
	target.draw(line, states);
}
void Line::setColor(sf::Color color)
{
	start.setFillColor(color);
	line.setFillColor(color);
	end.setFillColor(color);
}
void Line::calcLine() {
	calcDistance();
	length = sqrt(pow(distance.y, 2) + pow(distance.x, 2));
	line.setSize(sf::Vector2f(length, thickness * 2));
	calcAngle();
	sf::Vector2f normalized = distance / length;
	float tmp = normalized.x;
	normalized.x = normalized.y;
	normalized.y = -tmp;
	line.setRotation((distance.x < 0) ? 180 + angle : angle);
	line.setPosition(startPoint + normalized * thickness);
}
void Line::calcAngle() {
	angle = (float)atan2(distance.y / distance.x, 1) * 180 / 3.141592654;
}

sf::Vector2f Line::getRealPoint(sf::Vector2f vertex) {
	return sf::Vector2f(vertex.x - thickness, vertex.y - thickness);
}
void Line::calcDistance() {
	distance = (end.getPosition() - start.getPosition());
}
