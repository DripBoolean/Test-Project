#include "Vec2.h"

struct Circle {
    Vec2<float> location;
    float radius;
};

/**
 * @brief Returns True if the 2 circles overlap
 * 
 * @param a Circle 1
 * @param b Circle 2
 * @return true
 * @return false
 */
bool overlaps(Circle a, Circle b);