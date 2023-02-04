#pragma once

#include <vector>
#include "Vec2.h"
#include <SFML/Graphics.hpp>

class Root {
private:
    std::vector<Vec2<float>> points;
    Vec2<float> velocity;

    /**
     * @brief Finds the largest y among all points in the Root
     * 
     * @return float 
     */
    float max_y();

    /**
     * @brief Finds the largest x among all points in the Root
     * 
     * @return float 
     */
    float max_x();

    /**
     * @brief Finds the smallest x among all points in the Root
     * 
     * @return float 
     */
    float min_x();

public:
    /**
     * @brief Construct a new Root object with a given starting point and velocity
     * 
     * @param starting_point 
     * @param starting_velocity 
     */
    Root(Vec2<float> starting_point, Vec2<float> starting_velocity);

    /**
     * @brief Returns the head of the Root
     * 
     * @return Vec2<float> Head of the Root
     */
    Vec2<float> calyptra();

    /**
     * @brief Returns the base of the Root
     * 
     * @return Vec2<float> Base of the Root
     */
    Vec2<float> base();

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

    /**
     * @brief Get the display view for the root
     * 
     * @return sf::View 
     */
    sf::View get_view();
};