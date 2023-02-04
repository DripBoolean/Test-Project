#include <vector>
#include "Vec2.h"

class Root {
private:
    std::vector<Vec2f> points;
    Vec2f velocity;

    /**
     * @brief Construct a new Root object with a given starting point and velocity
     * 
     * @param starting_point 
     * @param starting_velocity 
     */
    Root(Vec2f starting_point, Vec2f starting_velocity);

    /**
     * @brief Returns the head of the current Root
     * 
     * @return Vec2f Head of the root
     */
    Vec2f calyptra();

    /**
     * @brief Move the head of the root by its velocity
     * 
     */
    void move();


    /**
     * @brief Rotates the direction the root is traveling by
     * 
     * @param angle Angle amount to rotate by
     */
    void rotate(float angle);


    /**
     * @brief Scales the velocity by a scalar
     * 
     * @param scalar Values to scale the velocity by
     */
    void accelerate(float scalar);
};