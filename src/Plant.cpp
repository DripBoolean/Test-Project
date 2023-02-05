#include "Plant.h"

sf::Texture Plant::plant_texture = sf::Texture();

Plant::Plant() :
    angle(0.f), 
    main_root(Root(Vec2<float>(0.f, 0), Vec2<float>(0.f, root_starting_speed))),
    water(starting_water)
    {   
        if(!plant_texture.loadFromFile("assets/Bulber2ElectricBulberoo.png")) throw std::runtime_error("Could not open BULBER");
    }

void Plant::rotate_left() {
    angle -= rotation_rate;
    if(angle < -M_PI / 2) angle = -M_PI / 2;
    main_root.rotate_left();
}

void Plant::rotate_right() {
    angle += rotation_rate;
    if(angle > M_PI / 2) angle = M_PI / 2;
    main_root.rotate_right();
}

void Plant::update(Map& map) {
    main_root.move(map.mObstacles);
    water += main_root.harvest(map);
}

void Plant::shoot_projectile(std::vector<Projectile>& projectiles) {
    if(water <  shooting_cost)
        return;

    water -= shooting_cost;
    projectiles.push_back(Projectile(position, angle));
}

sf::View Plant::get_view() {
    return main_root.get_view();
}

void Plant::draw(sf::RenderWindow& window) {
    sf::Sprite temp_sprite;
    temp_sprite.setOrigin(plant_texture.getSize().x / 2, plant_texture.getSize().y / 2);
    temp_sprite.setPosition(position.x, position.y);
    temp_sprite.setTexture(plant_texture);
    temp_sprite.rotate(angle * 180 / M_PI);
    temp_sprite.setScale(0.4f, 0.4f);
    window.draw(temp_sprite);
    main_root.draw(window, water);
}