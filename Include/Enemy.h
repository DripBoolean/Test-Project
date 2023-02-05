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

    float angle;

    /**
     * @brief Speed at which the Enemy moves
     * 
     */
    constexpr static float speed = 1.f;

    /**
     * @brief Size of the Enemy 
     * 
     */
    constexpr static float size = 5.f;

    static sf::Texture texture;

    static bool loaded;
    

public:
    /**
     * @brief Rate that the spawn chance grows per second
     * 
     */
    constexpr static float spawn_rate_growth = 0.0001f;

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

    bool reached_target();

    static float spawn_rate(float time);

    operator Circle() { return Circle(mPosition, size); };
};