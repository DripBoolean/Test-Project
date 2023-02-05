#include "Root.h"
#include <exception>
#include "Screen.h"

float Root::max_y() {
    float current_max = base().y;
    for(Vec2<float> point : points) {
        if(point.y > current_max) current_max = point.y;
    }
    return current_max;
}

float Root::max_x() {
    float current_max = base().x;
    for(Vec2<float> point : points) {
        if(point.x > current_max) current_max = point.x;
    }
    return current_max;
}

float Root::min_x() {
    float current_min = base().x;
    for(Vec2<float> point : points) {
        if(point.x < current_min) current_min = point.x;
    }
    return current_min;
}

float Root::size_at_age(unsigned index) {
    return max_size; // Fix This later
}

Circle Root::get_circle(unsigned index) {
    return Circle(points[index], size_at_age(index));
}

Root::Root(Vec2<float> starting_point, Vec2<float> starting_velocity) : velocity(starting_velocity) {
    points.push_back(starting_point);
}

Vec2<float> Root::calyptra() {
    if(points.empty()) throw std::length_error("The List is EMPTY!!! What are you doing???");
    return points.back();
}

Vec2<float> Root::base() {
    if(points.empty()) throw std::length_error("Hey, The List is empty. Thats alright. We all make mistakes sometimes. I know you will do better next time :)");
    return points[0];
}

void Root::move() {
    points.push_back(calyptra() + velocity);
}

void Root::rotate(float angle) {
    velocity.rotate(angle);
}

void Root::accelerate(float scalar) {
    velocity *= scalar;
}

void Root::draw(sf::RenderWindow& window) {
    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Green);

    for(unsigned i = 0; i < points.size(); i++) {
        circle.setPosition(points[i].x, points[i].y);
        float size = size_at_age(i);
        circle.setRadius(size);
        circle.setOrigin(size, size);
        window.draw(circle);
    }
}

sf::View Root::get_view() {
    sf::View out;

    out.setCenter(0.f, 0.f);

    float view_height = 2 * max_y();

    if(view_height < MIN_SIZE) view_height = MIN_SIZE;

    view_height += 2 * (view_height + MARGIN);

    out.setSize(view_height, view_height * ASPECT_RATIO);

    return out;
}

float Root::harvest(Map& map) {
    float water_harvested;
    for(unsigned i = 0; i < points.size(); i++) {
        for(Water& water : map.mWaterPockets) {
            if(overlaping(get_circle(i), (Circle)water)) {
                water_harvested += water.harvest();
            }
        }
        for(Nitrogen& nitrogen : map.mNitrogens) {
            if(overlaping(get_circle(i), (Circle)nitrogen)) {
                nitrogen.harvest();
                // Add Branch
            }
        }
    }
}