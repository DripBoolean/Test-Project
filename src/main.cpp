#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "Root.h"
#include "Circle.h"

int main() {
	
    Vec2<float> test(2.0, 1.0);
    Vec2<float> test2(3.0, 4.0);
    std::cout << test + test2 << std::endl;
    Vec2<float> test3 = test;
    std::cout << test3 << std::endl;
    std::cout << test3 * 3.0 << std::endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    Circle test_circle(Vec2<float>(100.f, 100.f), 100.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        test_circle.draw(window, sf::Color::Green);
        window.display();
    }

    return 0;
	
}