#include "Projectile.h"
#include "SFXlib.h"

Projectile::Projectile(Vec2<float> position, float angle) 
    : position(position)
{
    velocity = rotated(Vec2<float>(0.f, -speed), angle);
}

bool Projectile::overlaps(Enemy enemy) {
    return overlaping((Circle)enemy, (Circle)(*this));
}

void Projectile::update() {
    position += velocity;
}

void Projectile::draw(sf::RenderWindow& window) {
    ((Circle)(*this)).draw(window, sf::Color::Red);
}

void handle_collision(std::vector<Projectile>& projectiles, std::vector<Enemy>& enemies) {
    for(unsigned proj_index = 0; proj_index < projectiles.size(); proj_index++) {
        bool collided = false;
        for(unsigned enemy_index = 0; enemy_index < enemies.size(); enemy_index++) {
            if(overlaping((Circle)projectiles[proj_index], (Circle)enemies[enemy_index])) {
                collided = true;
                enemies.erase(std::next(enemies.begin(), enemy_index));
                enemy_index--;
            }
        }
        if(collided) {
            projectiles.erase(std::next(projectiles.begin(), proj_index));
            proj_index--;
        }
        
    }
}

bool SIMEOONFOOD(std::vector<Projectile>& projectiles, std::vector<Enemy>& enemies) {
    for(unsigned proj_index = 0; proj_index < projectiles.size(); proj_index++) {
        bool collided = false;
        for(unsigned enemy_index = 0; enemy_index < enemies.size(); enemy_index++) {
            if(overlaping((Circle)projectiles[proj_index], (Circle)enemies[enemy_index])) {
                collided = true;
                return collided;
            }
        }
        
    }
    return false;
}