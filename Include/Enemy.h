#pragma once

#include <SFML/Graphics.hpp>
#include "Vec2.h"

class Enemy {
private:
    Vec2<float> mPosition;

    constexpr static float speed = 0.01f;
    constexpr static float size = 5.f;
    

public:
    constexpr static float spawn_chance = 1.f;
    constexpr static float spawn_time = 0.f; // 0 Only for testing shold be like 3 or smth
    static Vec2<float> target;

    Enemy(sf::View view);

    void update();

    void draw(sf::RenderWindow& window);
};