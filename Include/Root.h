#pragma once

#include <vector>
#include "Vec2.h"
#include <SFML/Graphics.hpp>

class Root {
private:
    std::vector<Vec2<float>> points;
    Vec2<float> velocity;

public:
    /**
     * @brief Construct a new Root object with a given starting point and velocity
     * 
     * @param starting_point 
     * @param starting_velocity 
     */
    Root(Vec2<float> starting_point, Vec2<float> starting_velocity);

    /**
     * @brief Returns the head of the current Root
     * 
     * @return Vec2<float> Head of the root
     */
    Vec2<float> calyptra();

    /**
     * @brief Move the head of the root by its velocity
     * 
     */
    void move();


    /**
     * @brief Rotates the direction the root is traveling by
     * 
     * @param angle Angle amount to rotate by
     */
    void rotate(float angle);


    /**
     * @brief Scales the velocity by a scalar
     * 
     * @param scalar Values to scale the velocity by
     */
    void accelerate(float scalar);

    /**
     * @brief Draws the root
     * 
     * @param window Window to render to
     */
    void draw(sf::RenderWindow& window);
};