#include "Physical.hpp"

Physical::Physical() 
{
    tags.insert("Physical");
}

const sf::FloatRect Physical::getAABB()
{
    return getShape().getGlobalBounds();
}

float Physical::dotProduct(sf::Vector2f p0, sf::Vector2f p1)
{
    return (p0.x * p1.x) + (p0.y * p1.y);
}
std::vector<sf::Vector2f> Physical::getAxis(const sf::Shape& shape) {
    const size_t length = shape.getPointCount();
    std::vector <sf::Vector2f> axes;
    for (int i = 0; i < length;i++) {
        sf::Vector2f p0 = shape.getPoint(i);
        sf::Vector2f p1 = shape.getPoint(i == length-1?0:i);
        sf::Vector2f axis = sf::Vector2f(p1.y - p0.y, p0.x - p1.x);
        axes.push_back(axis / sqrt(powf(axis.x,2)+powf(axis.y,2)));
    }
    return axes;
}
const bool Physical::isColliding(Physical& other)
{
    //estimate collision
    bool est = other.getAABB().intersects(getAABB());
    if (est) {
        return true; //TODO:remove this
        const sf::Shape& otherBound = other.getShape();
        const sf::Shape& myBound = getShape();
        size_t otherSize = otherBound.getPointCount();
        std::vector<sf::Vector2f> p0a = getAxis(myBound);
        std::vector<sf::Vector2f> p1a = getAxis(otherBound);
        //TODO: get this working
        return true;
    }
    return false;
}

bool Physical::isABBBColling(sf::FloatRect a, sf::FloatRect b)
{
    return false;
}
