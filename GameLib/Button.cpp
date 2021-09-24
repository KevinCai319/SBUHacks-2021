#include "Button.hpp"

Button::Button(const sf::RectangleShape& hitbox, const sf::Text& text) : 
	Physical::Physical()
{
	m_hitbox = new sf::RectangleShape(hitbox); 
	m_text = new sf::Text(text); 
	alignTextCenter(); 
	tags.insert("Button");
}

Button::Button(const sf::RectangleShape& hitbox) : 
	Physical::Physical()
{
	m_hitbox = new sf::RectangleShape(hitbox); 
	tags.insert("Button"); 
}

Button::Button(float x, float y, float w, float h) : 
	Physical::Physical()
{
	m_hitbox = new sf::RectangleShape(sf::Vector2f(w, h)); 
	m_hitbox->setPosition(sf::Vector2f(x, y)); 
	m_hitbox->setOutlineColor(sf::Color::Red); 
	m_hitbox->setOutlineThickness(20); 
	tags.insert("Button"); 
}

Button::Button() : 
	Physical::Physical()
{
	m_hitbox = new sf::RectangleShape(sf::Vector2f(200.f, 200.f)); 
	m_hitbox->setPosition(0.f, 0.f); 
	tags.insert("Button"); 
}

Button::~Button()
{
	if (m_hitbox) delete m_hitbox; 
	if (m_text) delete m_text; 
}

const sf::Shape& Button::getShape()
{
	return *m_hitbox;
}

const sf::Text& Button::getText()
{
	return *m_text; 
}

void Button::setClickFunction(std::function<void()> function)
{
	if(function)onClick = function;
}

void Button::setHoverFunction(std::function<void()> function)
{
	if (function)onHover = function;
}

void Button::setText(const sf::Text& text)
{
	if (m_text) delete m_text; 
	m_text = new sf::Text(text); 
	alignTextCenter(); 
}

void Button::setShape(const sf::RectangleShape& hitbox)
{
	if (m_hitbox) delete m_hitbox; 
	m_hitbox = new sf::RectangleShape(hitbox); 
}

void Button::alignTextLeft()
{
	float hbheight = m_hitbox->getGlobalBounds().height - 2 * m_hitbox->getOutlineThickness(); 
	float offsetx = 0; 
	float offsety = (hbheight - m_text->getGlobalBounds().height) / 2; 
	float gap = m_text->getCharacterSize() - m_text->getGlobalBounds().height; 
	m_text->setPosition(sf::Vector2f(m_hitbox->getPosition().x + offsetx, m_hitbox->getPosition().y + offsety - gap)); 
}

void Button::alignTextCenter()
{
	float hbwidth = m_hitbox->getGlobalBounds().width - 2 * m_hitbox->getOutlineThickness(); 
	float hbheight = m_hitbox->getGlobalBounds().height - 2 * m_hitbox->getOutlineThickness(); 
	float offsetx = (hbwidth - m_text->getGlobalBounds().width) / 2;
	float offsety = (hbheight - m_text->getGlobalBounds().height) / 2; 
	float gap = m_text->getCharacterSize() - m_text->getGlobalBounds().height; 
	m_text->setPosition(sf::Vector2f(m_hitbox->getPosition().x + offsetx, m_hitbox->getPosition().y + offsety - gap)); 
}

void Button::alignTextRight()
{
	float hbwidth = m_hitbox->getGlobalBounds().width - 2 * m_hitbox->getOutlineThickness(); 
	float hbheight = m_hitbox->getGlobalBounds().height - 2 * m_hitbox->getOutlineThickness(); 
	float offsetx = (hbwidth - m_text->getGlobalBounds().width);
	float offsety = (hbheight - m_text->getGlobalBounds().height) / 2; 
	float gap = m_text->getCharacterSize() - m_text->getGlobalBounds().height; 
	m_text->setPosition(sf::Vector2f(m_hitbox->getPosition().x + offsetx, m_hitbox->getPosition().y + offsety - gap)); 
}

int Button::main()
{
	status = 0;
	if (checkHover()) 
	{
		m_hitbox->setOutlineColor(sf::Color::Red);
		if(onHover != nullptr)onHover();
		if (checkClick()) 
		{
			if(onClick != nullptr)onClick();
		}
	} 
	else 
	{
		m_hitbox->setOutlineColor(sf::Color::Green);
	}
	return status;
}

void Button::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(m_hitbox) target.draw(*m_hitbox, states);
	if(m_text) target.draw(*m_text, states); 
}


int Button::recieve(Layer& layer, int status)
{
	return 0;
}

void Button::notify(Layer& layer, int status)
{
	this->status = status;
}

bool Button::checkHover()
{
	sf::Vector2i pos = sf::Mouse::getPosition(*screen);
	float px = 0.0f + pos.x;
	float py = 0.0f + pos.y;
	return isHovering = m_hitbox->getGlobalBounds().contains(sf::Vector2f(px,py));
}

bool Button::checkClick()
{
	return isMouseDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
