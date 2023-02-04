#include "Circle.h"

bool overlaps(Circle a, Circle b) {
    return distance(a.mPosition, b.mPosition) < a.mRadius + b.mRadius;
}

bool Circle::draw(sf::RenderWindow& window, sf::Color color) {
    sf::CircleShape circ(mRadius);
    circ.setFillColor(color);
    circ.setOrigin(sf::Vector2f(mRadius, mRadius));
    circ.setPosition(sf::Vector2f(mPosition.x, mPosition.y));
    window.draw(circ);
}

bool draw(sf::Window& window, sf::Texture texture, sf::IntRect tex_bounds);