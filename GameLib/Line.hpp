#pragma once
#include <SFML/Graphics.hpp>;
class Line:public sf::Drawable
{
public:
	Line();
	Line(sf::Vector2f start, sf::Vector2f end, float thickness);
	~Line();
	void resetEnd(sf::Vector2f v2);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setColor(sf::Color color);
private:
	sf::Vector2f startPoint;
	sf::Vector2f endPoint;
	float thickness;
	float angle;
	float length;
	sf::CircleShape start;
	sf::RectangleShape line;
	sf::CircleShape end;
	void calcLine();
	void calcAngle();
	sf::Vector2f distance;
	void calcDistance();
	sf::Vector2f getRealPoint(sf::Vector2f vertex);
};

