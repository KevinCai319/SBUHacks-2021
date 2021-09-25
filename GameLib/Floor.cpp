#include "Floor.hpp"
#include "Teleporter.hpp"
Floor::Floor(int floorNumber,int fheight, int availSpots):
	floorNumber(floorNumber)
{
	tags.insert("Floor");
	spots.resize(availSpots);
	for (int i = 0; i < spots.size(); i++) {
		spots[i] = 0;
	}
	ground = sf::RectangleShape(sf::Vector2f(width, height));
	ground.setPosition((1920-width)/2,1080-floorNumber*fheight-height);
}

const sf::Shape& Floor::getShape()
{
	return ground;
}

Teleporter* Floor::placeT(int W)
{
	int s = spots.size();
	for (int i = 0; i < 100; i++) {
		int idx = rand()%s;
		if (spots[idx] == 0) {
			spots[idx] = 1;
			return new Teleporter(ground.getGlobalBounds().left+W*idx,ground.getGlobalBounds().top,W/2-12,height/2,floorNumber,W*.5);
		}
	}
	return nullptr;
}

void Floor::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(ground, states);
}
int Floor::recieve(Layer& layer, int status) {
	switch (status) {
		case 0:
			return 0;
		default:
			return 0;
	}
	return 0;
}