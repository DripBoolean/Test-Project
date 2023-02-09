#include <vector>
#include "Obstacles.h"
#include "Vec2.h"
#include "Circle.h"
#include <exception>
#include <iostream>
using namespace std;

array<vector<Vec2<float>>, (unsigned)Rock::NUM_ROCKS> Obstacle::array_map = {{
        {Vec2<float>(5.f, 5.f), Vec2<float>(-5.f, 5.f), Vec2<float>(-5.f, -5.f), Vec2<float>(5.f, -5.f)},
    }};

std::array<sf::Texture, (unsigned)Rock::NUM_ROCKS> Obstacle::texture_map = {sf::Texture()};


Obstacle::Obstacle(Vec2<float> position, Rock type) 
    : position(position), type(type)
    {
        if(!texture_map[(unsigned)type].loadFromFile("assets/Rock.png"))
            throw runtime_error("No load Rock");
    }

bool Obstacle::collision_check(Vec2<float> start_line, Vec2<float> end_line)
{   
    return distance(end_line, position) < size; // temp workaround
    vector<Vec2<float>> points = Obstacle::array_map[(unsigned)type];
    for(Vec2<float>& point : points) {
        point += position;
    }
    for(unsigned i = 0; i < points.size(); i++)
    {
        if(i == points.size() - 1)
        {
            if(is_intersecting(start_line, end_line, points[i], points[0])) {
                std::cout << "Colliding Loop: " << start_line << ", " << end_line << ", " << points[i] << ", " << points[0] << endl;
                return true;
            }
        }
        else
        {
            if(is_intersecting(start_line, end_line, points[i], points[i+1])){
                std::cout << "Colliding: " << start_line << ", " << end_line << ", " << points[i] << ", " << points[i+1 ] << endl;
                return true;
            }
        }
    }
    return false;
}

void Obstacle::draw(sf::RenderWindow& window) {
    sf::Sprite temp_sprite;
    temp_sprite.setTexture(texture_map[(unsigned)type]);
    temp_sprite.setOrigin(texture_map[(unsigned)type].getSize().x / 2, texture_map[(unsigned)type].getSize().y / 2);
    temp_sprite.setPosition(position.x, position.y);
    temp_sprite.setScale(0.2f, 0.2f);
    window.draw(temp_sprite);

    /**
    sf::RectangleShape test;
    test.setPosition(position.x -5.f, position.y - 5.f);
    test.setSize(sf::Vector2f(10.f, 10.f));
    window.draw(test);
    */
}

// I did actually write this one myself, though it is the same as the link below.
bool in_segment(Vec2<float> q, Vec2<float> p, Vec2<float> r)
{   
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
  
    return false;
    if(q.x <= max(p.x, r.x) &&
        q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) &&
        q.y >= min(p.y, r.y))
        return true;
    return false;
}


// unapolgetically stolen from: https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
int orientation(Vec2<float> q, Vec2<float> p, Vec2<float> r)
{
    int value = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);  //dot product, if value 0 -- perpendicualr, >0 acute angle, <0 obtuse angle. Maybe flip y axis (p.y - q.y)
  
    if (value == 0) return 0;  // collinear
  
    return (value > 0)? 1: 2; // clockwise or counterclockwise (acute or obtuse)
}

bool is_intersecting(Vec2<float> p1, Vec2<float> q1, Vec2<float> p2, Vec2<float> q2)
{
        // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
  
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
    
    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && in_segment(p1, p2, q1)) return true;
  
    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && in_segment(p1, q2, q1)) return true;
  
    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && in_segment(p2, p1, q2)) return true;
  
     // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && in_segment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}
