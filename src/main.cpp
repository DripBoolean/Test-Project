#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vec2.h"

int main() {
	
    Vec2<float> test(2.0, 1.0);
    Vec2<float> test2(3.0, 4.0);
    std::cout << test + test2 << std::endl;
    Vec2<float> test3 = test;
    std::cout << test3 << std::endl;
    std::cout << test3 * 3.0 << std::endl;

    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }

    return 0;
	
}