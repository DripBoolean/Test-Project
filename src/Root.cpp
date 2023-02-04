#include "Root.h"
#include <exception>


Root::Root(Vec2<float> starting_point, Vec2<float> starting_velocity) : velocity(starting_velocity) {
    points.push_back(starting_point);
}

Vec2<float> Root::calyptra() {
    if(points.empty()) throw std::length_error("The List is EMPTY!!! What are you doing???");
    return points.back();
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

