#pragma once
#include "Layer.hpp"
#include "Physical.hpp"
class Ball :public Physical{
	public:
		Ball();
		int main() override;
		void render(sf::RenderTarget& target, sf::RenderStates states)const override;
		virtual const sf::Shape& getShape() override;
		virtual const sf::FloatRect getAABB() override;
		int pscore=0;
	private:
		sf::RectangleShape box;
		sf::Vector2f velocity;
		void notify(Layer& layer, int status)override;
};

