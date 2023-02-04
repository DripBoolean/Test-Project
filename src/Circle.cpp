#include "Circle.h"

bool overlaps(Circle a, Circle b) {
    return distance(a.location, b.location) < a.radius + b.radius;
}