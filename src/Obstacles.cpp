#include <vector>
#include "Obstacles.h"
#include "Vec2.h"
#include "Circle.h"
#include <exception>
#include <iostream>
using namespace std;

Obstacles::Obstacles()
{
    mPoints;
}

void Obstacles::add_obstacles(vector<Vec2<float>> vert)
{
    mPoints = vert;
}

bool Obstacles::collision_check(Vec2<float> start_line, Vec2<float> end_line)
{
    for(int i = 0; i < mPoints.size(); i++)
    {
        if(i == mPoints.size() - 1)
        {
            if(is_intersecting(start_line, end_line, mPoints[i], mPoints[0]))
                return true;
        }
        else
        {
            if(is_intersecting(start_line, end_line, mPoints[i], mPoints[i+1]))
                return true;
        }
        return false;
    }
}

// I did actually write this one myself, though it is the same as the link below.
bool in_segment(Vec2<float> q, Vec2<float> p, Vec2<float> r)
{
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
              (q.x - p.x) * (r.y - q.y);
  
    if (value == 0) return 0;  // collinear
  
    return (value > 0)? 1: 2; // clockwise or counterclockwise
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