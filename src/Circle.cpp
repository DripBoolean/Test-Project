#include "Circle.h"

bool overlaps(Circle a, Circle b) {
    return distance((Vec2<float>)a.location, (Vec2<float>)b.location) < a.radius + b.radius;
}