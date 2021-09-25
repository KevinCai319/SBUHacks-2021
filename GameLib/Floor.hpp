#pragma once
#include "Physical.hpp"
#include "Teleporter.hpp"
#include "Door.hpp"
class Floor :public Physical
{
	public:
		Floor(int floorNumber, int fheight, int availSpots);
		virtual const sf::Shape& getShape() override;
		Teleporter* placeT(int W,int H);
		int floorNumber;
		std::vector<int> spots;
		static const int bezel = 600;
		static const int width = 1920 - bezel;
		static const int height = 50;
		int connections = 0;
	protected:
		sf::RectangleShape ground;
		virtual void render(sf::RenderTarget& target, sf::RenderStates states)const;
		virtual int recieve(Layer& layer, int status) override;
};

