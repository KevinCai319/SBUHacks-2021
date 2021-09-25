#pragma once
#include "Physical.hpp"
#include "Teleporter.hpp"
#include "Door.hpp"
class Floor :public Physical
{
	public:
		Floor(int floorNumber, int fheight);
		virtual const sf::Shape& getShape() override;
		int floorNumber;
	protected:
		sf::RectangleShape ground;
		virtual void render(sf::RenderTarget& target, sf::RenderStates states)const;
		virtual int recieve(Layer& layer, int status) override;
};

