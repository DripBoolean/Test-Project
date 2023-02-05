#include "Root.h"
#include <exception>
#include "Screen.h"
#include "Utils.h"

float Root::max_y() {
    float current_max = base().y;
    for(Vec2<float> point : points) {
        if(point.y > current_max) current_max = point.y;
    }
    return current_max;
}

float Root::max_x() {
    float current_max = base().x;
    for(Vec2<float> point : points) {
        if(point.x > current_max) current_max = point.x;
    }
    return current_max;
}

float Root::min_x() {
    float current_min = base().x;
    for(Vec2<float> point : points) {
        if(point.x < current_min) current_min = point.x;
    }
    return current_min;
}

float Root::size_at_age(unsigned index) {
    return (-max_size / (points.size() - index)) + max_size;
}

Circle Root::get_circle(unsigned index) {
    return Circle(points[index], size_at_age(index));
}

Vec2<float> Root::perpindicular_vector(unsigned index) {
    if(points.size() <= 1) return Vec2<float>(0.f, -1.f);
    if(index == points.size() - 1) return rotated((points[index] - points[index - 1]), M_PI / 2);
    return rotated((points[index] - points[index + 1]), M_PI / 2);
}

Root::Root(Vec2<float> starting_point, Vec2<float> starting_velocity, bool rand_rotation) 
    : calyptra(starting_point), velocity(starting_velocity), distance_traveled_before_last_node(0)
    {
        if(rand_rotation) {
            rotation_multiplier = RandomFloat(-2.f, 2.f);
            if(rotation_multiplier <= 0.f && rotation_multiplier > -0.5f) {
                rotation_multiplier = -0.5;
            }
            if(rotation_multiplier > 0.f && rotation_multiplier < 0.5f) {
                rotation_multiplier = 0.5;
            }
        }
        else rotation_multiplier = 1.f;
    }


Vec2<float> Root::base() {
    if(points.empty()) return calyptra;
    return points[0];
}

void Root::move(std::vector<Obstacle>& obsticles) {
    for(Root& branch : branches) {
        branch.move(obsticles);
    }
    if(!is_alive) return;
    Vec2<float> new_pos = calyptra + velocity;

    for(Obstacle& obsticle : obsticles) {
        if(obsticle.collision_check(calyptra, new_pos)) {
            is_alive = false;
            return;
        }
    }

    calyptra += velocity;
    distance_traveled_before_last_node += velocity.mag();
    if(distance_traveled_before_last_node > distance_between_nodes) {
        distance_traveled_before_last_node = 0.f;
        points.push_back(calyptra);
    }
    if(calyptra.y < 0.f) is_alive = false;
    
}

void Root::rotate_left() {
    velocity.rotate(-rotation_rate * rotation_multiplier);

    for(Root& branch : branches) {
        branch.rotate_left();
    }
}

void Root::rotate_right() {
    velocity.rotate(rotation_rate * rotation_multiplier);

    for(Root& branch : branches) {
        branch.rotate_right();
    }
}


void Root::draw(sf::RenderWindow& window, float water) {
    sf::CircleShape circle;
    int g = 0xbd * (-1 / (water + 1.f) + 1);
    circle.setFillColor(sf::Color(0x41, g, 0x91, 0xFF));
    for(unsigned i = 0; i < points.size(); i++) {
        circle.setPosition(points[i].x, points[i].y);
        float size = size_at_age(i);
        circle.setRadius(size);
        circle.setOrigin(size, size);
        window.draw(circle);
    }
    for(Root& branch : branches) {
        branch.draw(window, water);
    }
}

sf::View Root::get_view() {
    sf::View out;

    out.setCenter(0.f, 0.f);

    float view_height = max_y();

    if(view_height < MIN_SIZE) view_height = MIN_SIZE;

    if(view_height > MAX_SIZE) view_height = MAX_SIZE;

    view_height += 2 * (view_height + MARGIN);

    out.setSize(view_height, view_height * ASPECT_RATIO);

    return out;
}

float Root::harvest(Map& map) {
    float water_harvested = 0.f;
    for(unsigned i = 0; i < points.size(); i++) {
        for(Water& water : map.mWaterPockets) {
            if(water.overlaps(get_circle(i))) {
                water_harvested += water.harvest();
            }
        }
        for(Nitrogen& nitrogen : map.mNitrogens) {
            if(nitrogen.overlaps(get_circle(i))) {
                nitrogen.harvest();
                branch();
            }
        }
    }
    for(Root& branch : branches) {
        water_harvested += branch.harvest(map);
    }
    return water_harvested;
}

void Root::branch() {
    unsigned branch_index = rand() % points.size();
    Vec2<float> branch_location = points[branch_index];
    Vec2<float> branch_velocity = normalized(perpindicular_vector(branch_index)) * RandomFloat(min_speed, max_speed) * ((rand() % 2) ? -1.f : 1.f);
    branches.push_back(Root(branch_location, branch_velocity, true));
}