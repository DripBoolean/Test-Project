#include "Projectile.h"
#include "SFXlib.h"

sf::Texture Projectile::texture = sf::Texture();

Projectile::Projectile(Vec2<float> position, float angle) 
    : position(position), angle(angle)
{
    if(!texture.loadFromFile("assets/Spike.png")) 
        throw std::runtime_error("bro");
    velocity = rotated(Vec2<float>(0.f, -speed), angle);
    
}

bool Projectile::overlaps(Enemy enemy) {
    return overlaping((Circle)enemy, (Circle)(*this));
}

void Projectile::update() {
    position += velocity;
}

void Projectile::draw(sf::RenderWindow& window) {
    sf::Sprite temp_sprite;
    temp_sprite.setTexture(texture);
    temp_sprite.setTextureRect({0, 0, 32, 32});
    temp_sprite.setOrigin(sf::Vector2f(16.f, 16.f));
    temp_sprite.setScale(0.4f, 0.4f);
    temp_sprite.setPosition(position.x, position.y);
    temp_sprite.setRotation((angle * 180 / M_PI));
    window.draw(temp_sprite);
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

bool collision_SFX(std::vector<Projectile>& projectiles, std::vector<Enemy>& enemies) {
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