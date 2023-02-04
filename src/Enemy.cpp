#include "Enemy.h"
#include <random>
#include <math.h>
#include <Vec2.h>
#include "Utils.h"

Enemy::Enemy(sf::View view) {
    float angle = RandomFloat(0, M_PI);
    float corner_distance = Vec2<float>(view.getSize().x, view.getSize().y).mag();
    float distance = corner_distance + size;
    mPosition = Vec2<float>(-distance, 0.f);
    mPosition.rotate(angle);
    mPosition.y += 2 * size;
}

void Enemy::update() {
    mPosition -= (mPosition - target) * speed;
}

void Enemy::draw(sf::RenderWindow& window) {
    sf::CircleShape circ;
    circ.setRadius(size);
    circ.setOrigin(size, size);
    circ.setPosition(mPosition.x, mPosition.y);
    circ.setFillColor(sf::Color(50, 50, 50, 255));
    window.draw(circ);
}