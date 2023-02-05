#pragma once

#include "Root.h"
#include "Vec2.h"
#include "Projectile.h"

struct Plant {
    Root main_root;
    float angle;
    Vec2<float> position = Vec2<float>(0.f, -10.f);
    float water;

    constexpr static float rotation_rate = 0.05f;
    constexpr static float root_starting_speed = 0.1f;
    constexpr static float shooting_cost = 0.7f;
    constexpr static float starting_water = 1.4f;
    
    static sf::Texture plant_texture;

    Plant();

    void rotate_left();

    void rotate_right();

    void update(Map& map);

    void shoot_projectile(std::vector<Projectile>& projectiles);

    sf::View get_view();

    void draw(sf::RenderWindow& window);
};