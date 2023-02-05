#pragma once

#include "Enemy.h"

struct Projectile
{
    Vec2<float> position;
    Vec2<float> velocity;
    float angle;

    constexpr static float speed = 5.f;
    constexpr static float size = 10.f;

    Projectile(Vec2<float> position, float angle);

    bool overlaps(Enemy enemy);

    void update();

    void draw(sf::RenderWindow& window);

    operator Circle() { return Circle(position, size); };
};

struct doth_slain
{
    int hath_slain = 0;
};

void handle_collision(std::vector<Projectile>& projectiles, std::vector<Enemy>& enemies);
bool SIMEOONFOOD(std::vector<Projectile>& projectiles, std::vector<Enemy>& enemies);