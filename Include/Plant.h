#pragma once

#include "Root.h"
#include "Vec2.h"

struct Plant {
    Root main_root;
    float angle;
    Vec2<float> position = Vec2<float>(0.f, -10.f);

    constexpr static float rotation_rate = 0.05f;
    constexpr static float root_starting_speed = 0.1f;
    
    static sf::Texture plant_texture;

    Plant();

    void rotate_left();

    void rotate_right();

    void update(Map& map);

    void shoot_projectile();

    sf::View get_view();

    void draw(sf::RenderWindow& window);
};