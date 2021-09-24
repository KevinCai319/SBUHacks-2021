#pragma once
#include <SFML\Graphics.hpp>
class Physical
{
	public:
		sf::VertexArray getShape();
		virtual bool isColliding(Physical other)const = 0;
	private:
};

