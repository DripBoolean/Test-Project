#pragma once

#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "Circle.h"

/**
 * @brief An Enemy which ATTACKS bulber!!
 * 
 */
class Enemy {
private:
    /**
     * @brief Position of the Enemy
     * 
     */
    Vec2<float> mPosition;

    /**
     * @brief Speed at which the Enemy moves
     * 
     */
    constexpr static float speed = 0.01f;

    /**
     * @brief Size of the Enemy
     * 
     */
    constexpr static float size = 5.f;
    

public:
    /**
     * @brief Average chance of an enemy to spawn every second 1 being 100%
     * 
     */
    constexpr static float spawn_chance = 1.f;

    /**
     * @brief Delay in seconds before enemys spawn
     * 
     */
    constexpr static float spawn_time = 0.f; // 0 Only for testing shold be like 3 or smth

    /**
     * @brief Target for the Enemies to move towards, should be the location of the bulb
     * 
     */
    static Vec2<float> target;

    /**
     * @brief Construct a new Enemy object
     * 
     * @param view The the view used for rendering
     */
    Enemy(sf::View view);

    /**
     * @brief Updates the position of the Enemy, should be called every frame
     * 
     */
    void update();

    /**
     * @brief Draws the enemy to the window
     * 
     * @param window Window to draw to
     */
    void draw(sf::RenderWindow& window);

    operator Circle() { return Circle(mPosition, size); };
};