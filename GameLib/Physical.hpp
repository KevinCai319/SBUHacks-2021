#pragma once
#include <SFML/Graphics.hpp>
#include "Layer.hpp"
class Physical:public virtual Layer
{
	public:
		Physical();
		virtual const sf::Shape& getShape() = 0;
		virtual const sf::FloatRect getAABB();
		float dotProduct(sf::Vector2f p0, sf::Vector2f p1);
		std::vector<sf::Vector2f> getAxis(const sf::Shape& shape);
		virtual const bool isColliding(Physical& other);
		static bool isABBBColling(sf::FloatRect a, sf::FloatRect b);
	protected:

};

