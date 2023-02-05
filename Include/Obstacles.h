#pragma once

#include <vector>
#include "Vec2.h"
#include <SFML/Graphics.hpp>

enum class Rock {
    JAGGED,
    ROUND,
    PENTAGON,
    NUM_ROCKS
};


class Obstacle {
private:
    Vec2<float> position;
    Rock type;

    static std::array<std::vector<Vec2<float>>, (unsigned)Rock::NUM_ROCKS> array_map;
    static std::array<sf::Texture, (unsigned)Rock::NUM_ROCKS> texture_map;
    static bool loaded;
    float size = 5.f; // temp

    void static load() {
        
    } 

public:
    Obstacle(Vec2<float> position, Rock type);

    bool collision_check(Vec2<float> start_line, Vec2<float> end_line);

    void draw(sf::RenderWindow& window);
};

/**
 * @brief Basically box detection. Checks to see if the point is on the line segment.
 * 
 * @param q head of the Vec2<float> containing the root
 * @param p one of the points of the obstacle polygon 
 * @param r one of the points of the obstacle polygon
 * @return true 
 * @return false 
 */
bool in_segment(Vec2<float> q, Vec2<float> p, Vec2<float> r);

/**
 * @brief Function returns 0 if all points are collinear, 1 if clockwise, 
 *        and 2 if counterclockwise
 * 
 * @param q last point in Vec2<float> of root vector
 * @param p one of the points of the obstacle polygon
 * @param r one of the points of the obstacle polygon
 * @return int 
 */
int orientation(Vec2<float> q, Vec2<float> p, Vec2<float> r);

/**
 * @brief Checks orientation to see if lines overlap eachother. COvers special cases of only one
 *        point touching as well.
 * 
 * @param p1 starting value of the root Vec2<float>
 * @param q1 last value of the root Vec2<float>
 * @param p2 one of the points of the obstacle polygon
 * @param q2 the next point of the obstacle polygon after p2
 * @return true 
 * @return false 
 */
bool is_intersecting(Vec2<float> p1, Vec2<float> q1, Vec2<float> p2, Vec2<float> q2);

