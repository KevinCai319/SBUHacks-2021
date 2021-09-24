#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Physical.hpp"
#include "Layer.hpp"

class Button:public Physical
{
	public:
		Button(const sf::RectangleShape& hitbox, const sf::Text& text);
		Button(const sf::RectangleShape& hitbox); 
		Button(float x, float y, float w, float h);
		Button(); 
		~Button(); 

		void setClickFunction(std::function<void()> function);
		void setHoverFunction(std::function<void()> function);
		void setShape(const sf::RectangleShape& hitbox); 
		void setText(const sf::Text& text); 

		const sf::Shape& getShape()override;
		const sf::Text& getText(); 

		void alignTextLeft(); 
		void alignTextCenter(); 
		void alignTextRight(); 

		virtual int main() override;
		virtual void render(sf::RenderTarget& target, sf::RenderStates states)const override;
		virtual int recieve(Layer& layer, int status) override;
		virtual void notify(Layer& layer, int status) override;

		bool checkHover();
		bool checkClick();
	private:
		sf::Shape* m_hitbox = nullptr; 
		sf::Text* m_text = nullptr; 
		bool isHovering = false;
		bool isMouseDown = false;
		std::function<void()> onClick = nullptr;
		std::function<void()> onHover = nullptr;
};

