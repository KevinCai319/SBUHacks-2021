#pragma once
#include "Physical.hpp"
#include "Timed.hpp"
class Player :public Physical,public Timed{
	public:
		Player(int sx,int sy, int width, int height, float velocity,int lbound, int rbound,int floor,sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key interact);
		virtual int main(float dt) override;
		virtual const sf::Shape& getShape() override;
	protected:
		virtual int recieve(Layer& layer, int status)override;
		virtual void render(sf::RenderTarget& target, sf::RenderStates states)const override;
		sf::RectangleShape box;
		sf::Keyboard::Key left;
		sf::Keyboard::Key right;
		sf::Keyboard::Key interact;
		const int width;
		const int height;
		const int lbound;
		const int rbound;
		const float velocity;
		int floor;
};

