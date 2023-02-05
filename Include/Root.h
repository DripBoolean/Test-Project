#pragma once

#include <vector>
#include "Vec2.h"
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Circle.h"

/**
 * @brief The Root System of the Bulber Plant!
 * 
 */
class Root {
private:
    std::vector<Vec2<float>> points;
    Vec2<float> velocity;
    bool is_alive;

    constexpr static float max_size = 1.5f;

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

    /**
     * @brief Gives the size of a node at its index
     * 
     * @param index Index this represents the "age" of the node
     * @return float 
     */
    float size_at_age(unsigned index);

    /**
     * @brief Get a circle for the node at the given index
     * 
     * 
     * @param index index of the node to get a circle object from
     * @return Circle 
     */
    Circle get_circle(unsigned index);

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

    /**
     * @brief Harvests resources from the map
     * 
     * @param map map to be HARVESTED from
     */
    float harvest(Map& map);
};