#pragma once

#include "Vec2.h"
#include "Obstacles.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <Circle.h>

/**
 * @brief Water Pocket that is a key resource for the player
 * 
 */
struct Water {
    Vec2<float> position;
    float size;

    Water(Vec2<float> position, float size);

    constexpr static float water_drain_rate = 1.f;
    
    /**
     * @brief Determines if the water object overlaps a Circle
     * 
     * @param circle Circle to compare to
     * @return true 
     * @return false 
     */
    bool overlaps(Circle circle); 

    /**
     * @brief Renders the water to the window
     * 
     * @param window Window to render to
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Harvests the water and returns water retrieved
     * 
     * @return float Water harvested
     */
    float harvest();

    operator Circle() { return Circle(position, size); };
};

/**
 * @brief Nitrogen pocket granting the player an extra root!
 * 
 */
struct Nitrogen {
    Vec2<float> position;
    bool exists = true;

    constexpr static float size = 1.5f;

    Nitrogen(Vec2<float> position);

    /**
     * @brief Determines if the water object overlaps a Circle
     * 
     * @param circle Circle to compare to
     * @return true 
     * @return false 
     */
    bool overlaps(Circle circle);

    /**
     * @brief Renders the nitrogen to the window
     * 
     * @param window Window to render to
     */
    void draw(sf::RenderWindow& window);

    void harvest();

    operator Circle() { return Circle(position, size); };
};

/**
 * @brief Map to contain all the objects underground
 * 
 */
struct Map {
    std::vector<Nitrogen> mNitrogens;
    std::vector<Water> mWaterPockets;
    std::vector<Obstacles> mObstacles;

    constexpr static float default_size = 500.f;
    constexpr static float nitrogen_rate_per_unit = 0.0003f;
    constexpr static float water_rate_per_unit = 0.0003f;
    constexpr static float water_min_size = 1.f;
    constexpr static float water_max_size = 10.f;
    constexpr static float obsticle_rate_per_unit = 0.1f;

    Map();

    /**
     * @brief Renders the map on the window
     * 
     * @param window Window to render to
     */
    void draw(sf::RenderWindow& window);

private:
    /**
     * @brief Returns a random point withen the default space
     * 
     * @return Vec2<float> 
     */
    Vec2<float> rand_point_in_default();

    /**
     * @brief Determines if a nitrogen overlaps a nitrogen in the map
     * 
     * @param testee Nitrogen to compare with
     * @return true 
     * @return false 
     */
    bool overlaps_nitrogens(Circle testee);

    /**
     * @brief Determines if water overlaps a water in the map
     * 
     * @param testee Water to compare with
     * @return true 
     * @return false 
     */
    bool overlaps_waters(Circle testee);
};