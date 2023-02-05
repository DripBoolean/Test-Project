#include "Map.h"
#include "Utils.h"

Nitrogen::Nitrogen(Vec2<float> position) : position(position) 
    {}

bool Nitrogen::overlaps(Circle circle) {
    if(!exists) return false;
    return overlaping(circle, (Circle)(*this));
}

void Nitrogen::draw(sf::RenderWindow& window) {
    if(!exists) return;
    sf::CircleShape circ;
    circ.setRadius(size);
    circ.setOrigin(size, size);
    circ.setPosition(position.x, position.y);
    circ.setFillColor(sf::Color::Green);
    window.draw(circ);
}

void Nitrogen::harvest() {
    exists = false;
}

Water::Water(Vec2<float> position, float size) : position(position), size(size)
    {}

bool Water::overlaps(Circle circle) {
    if(size < 0.f) return false;
    return overlaping(circle, (Circle)(*this));
}

void Water::draw(sf::RenderWindow& window) {
    sf::CircleShape circ;
    circ.setRadius(size);
    circ.setOrigin(size, size);
    circ.setPosition(position.x, position.y);
    circ.setFillColor(sf::Color::Blue);
    window.draw(circ);
}

float Water::harvest() {
    size -= water_drain_rate;
    return water_drain_rate;
}

Map::Map() {
    float total_units = default_size * default_size * 2;

    int num_nitrogens = (int)(total_units * nitrogen_rate_per_unit);
    int num_waters = (int)(total_units * water_rate_per_unit);
    int num_obsticles = (int)(total_units * obsticle_rate_per_unit);

    for(unsigned i = 0; i < num_nitrogens; i++) {
        Nitrogen canidate(rand_point_in_default());
        if(overlaps_nitrogens((Circle)canidate)) continue;
        mNitrogens.push_back(canidate);
    }
    for(unsigned i = 0; i < num_waters; i++) {
        Water canidate(rand_point_in_default(), RandomFloat(water_min_size, water_max_size));
        if(overlaps_nitrogens((Circle)canidate)) continue;
        if(overlaps_waters((Circle)canidate)) continue;
        mWaterPockets.push_back(canidate);
    }
    // Add obsticles
}

void Map::draw(sf::RenderWindow& window) {
    for(Nitrogen nitrogen : mNitrogens) {
        nitrogen.draw(window);
    }
    for(Water water : mWaterPockets) {
        water.draw(window);
    }
}

Vec2<float> Map::rand_point_in_default() {
    return Vec2<float>(RandomFloat(-default_size, default_size), RandomFloat(0.f, default_size));
}

bool Map::overlaps_nitrogens(Circle testee) {
    for(Nitrogen nitrogen : mNitrogens) {
        if(nitrogen.overlaps(testee)) return true;
    }
    return false;
}

bool Map::overlaps_waters(Circle testee) {
    for(Water water : mWaterPockets) {
        if(water.overlaps(testee)) return true;
    }
    return false;
}