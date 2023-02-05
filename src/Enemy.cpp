#include "Enemy.h"
#include <random>
#include <math.h>
#include <Vec2.h>
#include "Utils.h"

sf::Texture Enemy::texture = sf::Texture();

Enemy::Enemy(sf::View view) {
    if(!texture.loadFromFile("assets/Muncher.png")) 
        throw std::runtime_error("bro");


    angle = RandomFloat(0, M_PI);
    float corner_distance = Vec2<float>(view.getSize().x, view.getSize().y).mag();
    float distance = corner_distance + size;
    mPosition = Vec2<float>(-distance, 0.f);
    mPosition.rotate(angle);
    mPosition.y += 2 * size;
}

void Enemy::update() {
    mPosition += normalized(target - mPosition) * speed;
}

void Enemy::draw(sf::RenderWindow& window) {
    sf::Sprite temp_sprite;
    temp_sprite.setTexture(texture);
    temp_sprite.setTextureRect({0, 0, 32, 32});
    temp_sprite.setOrigin(sf::Vector2f(16.f, 16.f));
    temp_sprite.setScale(0.4f, 0.4f);
    temp_sprite.setPosition(mPosition.x, mPosition.y);
    std::cout << angle << std::endl;
    temp_sprite.setRotation((angle * 180 / M_PI) - 90);
    window.draw(temp_sprite);
}

bool Enemy::reached_target() {
    return distance(mPosition, target) < size; 
}