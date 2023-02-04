#include "Vec2.h"
#include <vector>

/**
 * @brief Nitrogen pocket granting the player an extra root!
 * 
 */
struct Nitrogen {
    Vec2<float> position;

    constexpr static float size = 1.f;
};

/**
 * @brief Water Pocket that is a key resource for the player
 * 
 */
struct Water {
    Vec2<float> position;
    float size;
};

/**
 * @brief Map to contain all the objects underground
 * 
 */
class Map {
    std::vector<Nitrogen> mNitrogens;
    std::vector<Water> mWaterPockets;
};