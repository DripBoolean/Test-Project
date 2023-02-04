#include "Vec2.h"

struct Circle {
    Vec2f location;
    float radius;
};

bool overlaps(Circle a, Circle b);