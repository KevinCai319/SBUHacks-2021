#pragma once
#include <SFML/Graphics.hpp>
#include "Physical.hpp"
#include "Clue.hpp"
#include "Button.hpp"
class Door :public Physical
{
private: 
	sf::RectangleShape box;  
	// Clue clue; 

public: 
	Door(float sx, float sy, float width, float height, int floor,int color,int shape, int number);
	~Door();
	virtual void render(sf::RenderTarget& target, sf::RenderStates states) const override; 
	virtual int recieve(Layer& layer, int status) override; 
	virtual const sf::Shape& getShape() override; 
	int getFloor(); 
	const sf::Vector2f& getStart(); 
	const sf::Vector2f& getSize(); 
	bool isGood = false;
	sf::Font* fontptr;
	int floor;
	int color;
	int shape;
	int id;
	int lx;
	int hx;
	Button number;
	sf::Text doorText;
	const sf::Drawable* symbol;
};

