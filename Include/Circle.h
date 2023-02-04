#pragma once

#include "Vec2.h"
#include <SFML/Graphics.hpp>

struct Circle {
    Vec2<float> mPosition;
    float mRadius;

    Circle(Vec2<float> position, float radius) : mPosition(position), mRadius(radius)
        {}

    void draw(sf::RenderWindow& window, sf::Color color);

    void draw(sf::Window& window, sf::Texture& texture, sf::IntRect tex_bounds);
};

/**
 * @brief Returns True if the 2 circles overlap
 * 
 * @param a Circle 1
 * @param b Circle 2
 * @return true
 * @return false
 */
bool overlaps(Circle a, Circle b);

