#include <vector>
#include "Vec2.h"



class Root {
private:
    std::vector<Vec2f> points;
    Vec2f velocity;


    Root(Vec2f starting_point, Vec2f starting_velocity);

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
     * @brief Scales the acceleration by a scalar
     * 
     * @param scalar Values to scale the acceleration by
     */
    void accelerate(float scalar);
};